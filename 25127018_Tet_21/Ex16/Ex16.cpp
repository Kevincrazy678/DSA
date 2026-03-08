//link to the problem: https://leetcode.com/problems/missing-number/?envType=problem-list-v2&envId=hash-table
class Solution {
public:
    int missingNumber(vector<int>& nums) {
    	//Time Comp: O(n log n), Space Comp: O(n)
        int n = nums.size();
        set<int>st;
        for(int i=0; i<n; i++){
        	// Insert the current number into the set
            st.insert(nums[i]);
        }
        for(int i=0; i<=n; i++){
        	// Check if the current number 'i' is missing from our set
            if(st.find(i) == st.end()){
            	// Return the missing number immediately upon finding it
                return i;
            }
        }
        return -1;
    }
};

//test case 1
//[3,0,1]
//Ans: 2

//test case 2
//[0,1]
//Ans: 2

//test case 3
//[9,6,4,2,3,5,7,0,1]
//Ans: 8
