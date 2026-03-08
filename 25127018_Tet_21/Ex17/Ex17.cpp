//link to the problem: https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/?envType=problem-list-v2&envId=hash-table
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
    	//Time Comp: O(n*n), Space Comp: O(n)
        int n = nums.size();
        vector<int> res;
        
        // Use a map to store the frequency of each number
        map<int, int> mp;
        // Step 1: Count the occurrences of each number in the array
        for(int i = 0; i < n; i++) {
            // Inserting or updating elements in a map takes O(log N) time
            mp[nums[i]]++;
        }
        // Step 2: Loop through the original array to find the answer for each element
        for(int i = 0; i < n; i++) {
            // cnt(meaning count by the way) will accumulate the total number of elements strictly smaller than nums[i]
            int cnt = 0;
            // Iterate through the key-value pairs in our sorted map
            for(auto x : mp) {
                // If the map's current key matches the number we are evaluating
                if(nums[i] == x.first) {
                    res.push_back(cnt)
                    // Break out of the inner loop early to save time
                    break;
                }
                // If the map's key is smaller, add its frequency (x.second) to our running total
                cnt += x.second;
            }
        }
        // Return the fully populated result array
        return res
    }
};

//test case 1
//[8,1,2,2,3]
//Ans: [4,0,1,1,3]

//test case 2
//[6,5,4,8]
//Ans: [2,1,0,3]

//test case 3
//[7,7,7,7]
//Ans: [0,0,0,0]
