//link to the problem: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/?envType=problem-list-v2&envId=dynamic-programming
class Solution {
public:
    int maxProfit(vector<int>& prices) {
    	//Time Comp: O(n), Space Comp: O(1)
    	
        int res = 0, n = prices.size(), min_p = prices[0]; 
        // Loop through the prices starting from the second day (index 1) to the end.
        for(int i = 1; i < n; i++) {
            // Update 'res' if this new profit is strictly greater than the previous 'res'.
            res = max(res, prices[i] - min_p); 
            // Update the minimum price (min_p) if today's price is lower than the current min_p.
            min_p = min(min_p, prices[i]); 
        }
        
        // Ensure the profit is at least 0 (in case the array is strictly decreasing, we just don't buy).
        res = max(res, 0); 
        
        // Return the final calculated maximum profit.
        return res;
    }
};

//test case 1
//[7,1,5,3,6,4]
//Ans: 5

//test case 2
//[7,6,4,3,1]
//Ans: 0

//test case 3
//[9,1,2,3,8]
//Ans: 7
