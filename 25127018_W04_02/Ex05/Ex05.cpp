//link to the problem: https://leetcode.com/problems/transform-array-by-parity/
class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
    	//Time Comp: O(n) because we have to interate to all elements of the array, Space Comp: O(n)
        int n = nums.size();
        vector<int>res(n);
        for(int i=0; i<n; i++){
        	//Check if num[i] is even
            if(nums[i] % 2 == 0)res[i] = 0;
            //Check if num[i] is odd
            else res[i] = 1;
        }
        sort(res.begin(), res.end());
        return res;
    }
};

//test case 1
//[4,3,2,1]
//Ans: [0,0,1,1]

//test case 2
//[1,5,1,4,2]
//Ans: [0,0,1,1,1]

//test case 3
//[7,4,2,1,3,4,5]
//Ans: [0,0,0,1,1,1,1]
