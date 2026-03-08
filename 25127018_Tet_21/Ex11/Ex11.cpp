//link to the problem: https://leetcode.com/problems/is-subsequence/?envType=problem-list-v2&envId=dynamic-programming
class Solution {
public:
    bool isSubsequence(string s, string t) {
    	//Time Comp: O(n), Space Comp: O(1)
        // Initialize two pointers: 'left' to track string 's' and 'right' to track string 't'
        int left = 0, right = 0;
        
        while(left < s.length() && right < t.length()) {
            
            // If the characters match, we successfully found the current character of 's' inside 't'
            if(s[left] == t[right]) {
                left++;
            }
            
            // Regardless of a match, always move the 'right' pointer forward 
            right++;
        }
        
        // If the 'left' pointer reached the exact length of 's', it means we successfully matched
        return left == s.length();
    }
};

//test case 1
//"abc" "ahbgdc"
//Ans: true

//test case 2
//"axc" "ahbgdc"
//Ans: false

//test case 3
//"acb" "ahbgdc"
//Ans: false
