//link to the problem: https://leetcode.com/problems/count-pairs-whose-sum-is-less-than-target/
class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
    	//Time Comp: O(n*n), Space Comp: O(1)
        int res = 0, n = nums.size();
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
            	//Check if the sum of nums[i] and nums[j] is lower than target
                if(nums[i] + nums[j] < target)res++;
            }
        }
        return res;
    }
};

//test case 1
//[-1,1,2,3,1] 2
//Ans: 3

//test case 2
//[-6,2,5,-2,-7,-1,3] -2
//Ans: 10

//test case 3
//[2,3,5,1,21,23,18] 12
//Ans: 6
