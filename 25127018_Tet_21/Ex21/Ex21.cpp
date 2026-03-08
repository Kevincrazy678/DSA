//link to the problem: https://leetcode.com/problems/count-number-of-pairs-with-absolute-difference-k/?envType=problem-list-v2&envId=hash-table
class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
    	//Time Comp: O(n), Space Comp: O(n)
        unordered_map<int, int>mp;
        int cnt = 0;
        for(int i=0; i<nums.size(); i++){
        	// Check if (nums[i] - k) exists in our map of previously seen numbers
            if(mp.count(nums[i] - k)){
                cnt += mp[nums[i] - k];
            }
            // Check if (nums[i] + k) exists in our map
            if(mp.count(nums[i] + k)){
                cnt += mp[nums[i] + k];
            }
            // After checking for pairs, add the current number to the map for future numbers to pair with
            mp[nums[i]]++;
        }
        return cnt;
    }
};

//test case 1
//[1,2,2,1] 1
//Ans: 4

//test case 2
//[1,3] 3
//Ans: 0

//test case 3
//[3,2,1,5,4] 2
//Ans: 3
