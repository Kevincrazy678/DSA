//link to the problem: https://leetcode.com/problems/baseball-game/description/?envType=problem-list-v2&envId=stack
class Solution {
public:
    int calPoints(vector<string>& operations) {
    	//Time Comp: O(n), Space Comp: O(n)
        int n = operations.size(); 
        stack<int> st; 
        
        for(int i = 0; i < n; i++) {
            
            // Case 1: The operation is "+".
            if(operations[i] == "+") {
                // Pop the top score and store it in top1.
                int top1 = st.top(); st.pop();
                // Pop the next score (which is now the top) and store it in top2.
                int top2 = st.top(); st.pop();
                
                // Push the elements back onto the stack in their original order
                st.push(top2); 
                st.push(top1); 
                // Push the new score, which is the sum of the two previous scores
                st.push(top1 + top2); 
            }
            // Case 2: The operation is "D".
            else if(operations[i] == "D") {
                int top = st.top();
                st.push(top * 2); 
            }
            // Case 3: The operation is "C".
            else if(operations[i] == "C") {
                // Pop the top element from the stack, discarding it.
                st.pop(); 
            }
            // Case 4: The operation is an integer (represented as a string).
            else {
                // Convert the string to an integer using stoi() and push it onto the stack.
                int x = stoi(operations[i]);
                st.push(x); 
            }
        }
        
        // res: accumulates the total sum of all valid scores left in the stack.
        int res = 0; 
        
        // Pop elements one by one until the stack is completely empty.
        while(!st.empty()) {
            // Add the top element to our total result, then remove it.
            res += st.top(); 
            st.pop();
        }
        
        // Return the final accumulated sum.
        return res;
    }
};

//test case 1
//["5","2","C","D","+"]
//Ans: 30

//test case 2
//["5","-2","4","C","D","9","+","+"]
//Ans: 27

//test case 3
//["1","C"]
//Ans: 0
