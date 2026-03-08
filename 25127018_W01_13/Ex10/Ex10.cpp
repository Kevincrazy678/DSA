class Solution {
public:
    int reverseDegree(string s) {
        int res = 0;
        //Complexity: O(n)
        for(int i=0; i<s.length(); i++){
            int c = s[i] - '0';
            //Instead of (65+27) - c, leetcode used (48+27) - c
            res += abs(75 - c) * (i+1);
        }
        return res;
    }
};
//Test case 1
//Input: "abc"
//Expected: 148
//Test case 2
//Input: "zaza"
//Expected: 160
//Test case 3
//Input: "xybz"
//Expected: 86
