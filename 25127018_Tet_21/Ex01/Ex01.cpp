//link to the problem: https://leetcode.com/problems/climbing-stairs/description/?envType=problem-list-v2&envId=dynamic-programming
class Solution {
public:
    int climbStairs(int n) {
    	//Time Comp: O(n), Space Comp: O(1)
    	
        // This array stores the number of ways to reach the i-th step (which follows the Fibonacci sequence).
        long long F[93]; 
        
        // Base cases:
        // F[0] = 1: 0 steps to climb means 1 way to stay at the ground
        // F[1] = 1: 1 step to climb means exactly 1 way
        F[0] = F[1] = 1; 
        
        // Iterate from the 2nd step all the way up to the n-th step.
        for(int i = 2; i <= n; i++) {
            // DP recurrence relation:
            // The ways to reach the i-th step is the sum of the ways to reach the (i-1)-th and (i-2)-th steps.
            F[i] = F[i-1] + F[i-2]; 
        }
        // Return the total number of ways to climb to the top of n stairs.
        return F[n]; 
    }
};

//test case 1
//2
//Ans: 2

//test case 2
//3
//Ans: 3

//test case 3
//5
//Ans: 8
