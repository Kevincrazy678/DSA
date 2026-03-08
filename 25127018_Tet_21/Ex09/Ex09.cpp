//link to the problem: https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/?envType=problem-list-v2&envId=queue
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
    	//Time Comp: O(n*n), Space Comp: O(n)
        int n = students.size();
        
        // 'st' represents the line of students.
        // 'sa' represents the stack of sandwiches.
        queue<int> st, sa; 
        
        for(int i = 0; i < n; i++) {
            st.push(students[i]);
            sa.push(sandwiches[i]);
        }
        
        // 'waiting' tracks how many consecutive students have rejected the current top sandwich.
        int waiting = 0; 
        
        // Continue the simulation as long as there are still students in line.
        while(!st.empty()) {
            
            // Case 1: The student at the front of the line likes the sandwich at the front.
            if(st.front() == sa.front()) {
                st.pop();
                sa.pop();
                // Reset the waiting counter because the sandwich stack has changed
                waiting = 0; 
            }
            // Case 2: The student likes a dif type of sandwich.
            else {
                int x = st.front(); 
                st.pop();
                st.push(x);
                // Increment the counter since this student couldn't eat.
                waiting++; 
            }
            
            // Termination Condition:
            if(waiting == st.size()) break; 
        }
        
        // Return the number of students left in the line who couldn't eat.
        return st.size();
    }
};

//test case 1
//[1,1,0,0] [0,1,0,1]
//Ans: 0

//test case 2
//[1,1,1,0,0,1] [1,0,0,0,1,1]
//Ans: 3

//test case 3
//[1,1,1,0,0,1] [1,0,0,0,1,1]
//Ans: 3
