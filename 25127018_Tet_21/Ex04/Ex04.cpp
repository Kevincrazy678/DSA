//link to the problem: https://leetcode.com/problems/fibonacci-number/?envType=problem-list-v2&envId=dynamic-programming
class Solution {
public:
    int maxProfit(vector<int>& prices) {
		//Time Comp: O(n), Space Comp: O(1)
		
        int F[31]; 
        // Base cases for the Fibonacci sequence:
        // F(0) is 0 and F(1) is 1. 
        F[0] = 0, F[1] = 1; 
        
        // Iterate from 2 up to n to calculate the subsequent Fibonacci numbers.
        for(int i = 2; i <= n; i++) {
            // DP recurrence relation:
            F[i] = F[i-1] + F[i-2]; 
        }
        
        // Return the n-th Fibonacci number.
        return F[n];
    }
};

//test case 1
//2
//Ans: 1

//test case 2
//3
//Ans: 2

//test case 3
//4
//Ans: 3
