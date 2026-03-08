//link to the problem: https://leetcode.com/problems/find-the-winner-of-the-circular-game/?envType=problem-list-v2&envId=queue
class Solution {
public:
    int findTheWinner(int n, int k) {
    	//Time Comp: O(n*k), Space Comp: O(n)
        queue<int>q;
        // Populate the queue with friends numbered from 1 to n.
        for(int i = 1; i <= n; i++) {
            q.push(i);
        }
        // 'tmp' acts as our counter to keep track of the current count (up to k)
        int tmp = 0; 
        // The game continues until there is exactly 1 friend left in the queue.
        while(q.size() != 1) {
            tmp++; 
            // Case 1: We have reached the k-th person.
            if(tmp == k) {
                // Eliminate them by permanently removing them from the front
                q.pop(); 
                // Reset the counter to 0 for the next round of counting.
                tmp = 0; 
            }
            // Case 2: We have not reached the k-th person yet.
            else {
                // This person survives this count. 
                // We simulate passing them in the circle by taking them from the front
                int top = q.front(); 
                q.pop();
                q.push(top); 
            }
        }
        
        // The while loop ends when only 1 person remains. They are the winner!
        return q.front();
    }
};

//test case 1
//5 2
//Ans: 3

//test case 2
//6 5
//Ans: 1	

//test case 3
//9 2
//Ans: 3
