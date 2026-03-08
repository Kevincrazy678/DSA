//link to the problem: https://leetcode.com/problems/find-lucky-integer-in-an-array/?envType=problem-list-v2&envId=hash-table
class Solution {
public:
    int findLucky(vector<int>& arr) {
    	//Time Comp: O(nlogn), Space Comp: O(n)
    	
        map<int, int> ;
        for(int i = 0; i < arr.size(); i++) {
            // Increment the count for the current number
            mp[arr[i]]++;
        }
        
        // Initialize our result to -1, which is the default return value if no lucky number exists
        int res = -1;
        
        // Iterate through the key-value pairs in the sorted map
        for(auto x : mp) {
            // Check if the number (x.first) matches its frequency (x.second)
            if(x.first == x.second) {
                // Update our result with the current lucky number
                res = x.first;
            }
        }
        // Return the final result
        return res;
    }
};

//test case 1
//[2,2,3,4]
//Ans: 2

//test case 2
//[1,2,2,3,3,3]
//Ans: 3

//test case 3
//[2,2,2,3,3]
//Ans: -1

