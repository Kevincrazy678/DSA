//link to the problem: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/?envType=problem-list-v2&envId=dynamic-programming
class Solution {
public:
    int maxProfit(vector<int>& prices) {
		//Time Comp: O(n), Space Comp: O(1)
		
        int res = 0, n = prices.size(); 
        
        // Base case: If there is only 1 day (or less), we can't make any transactions.
        if(n <= 1) return 0;
        
        // We stop at n-1 because we need to compare today (i) with tomorrow (i+1).
        for(int i = 0; i < n - 1; i++) {
            // Greedy algorithm: If tomorrow's price is higher than today's price
            if(prices[i] < prices[i+1]) {
                // we "buy" today and "sell" tomorrow, adding the difference to our total profit.
                res += prices[i+1] - prices[i]; 
            }
        }
        
        // Return the accumulated maximum profit.
        return res;
    }
};

//test case 1
//[7,1,5,3,6,4]
//Ans: 7

//test case 2
//[1,2,3,4,5]
//Ans: 4

//test case 3
//[7,6,4,3,1]
//Ans: 0
