//link to the problem: https://leetcode.com/problems/divisor-game/?envType=problem-list-v2&envId=dynamic-programming
class Solution {
public:
    bool divisorGame(int n) {
    	//Time Comp: O(n*n), Space Comp: O(n)
        vector<int>dp(n+1, 0);
        // Build the DP table bottom-up starting from 2 all the way to n
        for (int i = 2; i <= n; i++) {
            // Try every possible valid move 'x' (where x is a divisor of i)
            for (int x = 1; x < i; x++) {
                // Check if 'x' is an actual divisor of 'i'
                if (i % x == 0) {
                    // It means we have found a winning strategy for our current number 'i'
                    if (dp[i - x] == false) {
                        // Mark our current state as a winning state
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        // The final answer for the game starting with 'n' is stored at dp[n]
        return dp[n];
    }
};

//test case 1
//2
//Ans: true

//test case 2
//3
//Ans: false

//test case 3
//9
//Ans: false
