//link to the problem: https://leetcode.com/problems/valid-parenthesis-string/?envType=problem-list-v2&envId=dynamic-programming
class Solution {
public:
    bool checkValidString(string s) {
    	//Time Comp: O(n), Space Comp: O(n)
        stack<int> st, star;
        
        // Iterate through each character in the string
        for(int i = 0; i < s.length(); i++) {
            
            // If current character is '(', push its index onto the 'st' stack
            if(s[i] == '(') {
                st.push(i);
            }
            // If current character is '*', push its index onto the 'star' stack
            else if(s[i] == '*') {
                star.push(i);
            }
            // If current character is ')'
            else {
                // Prioritize using a '(' to match with the current ')'
                if(!st.empty()) {
                    st.pop();
                }
                // If there are no '(' available, fall back to checking '*'
                else {
                    // Use a '*' as a substitute for an opening bracket '('
                    if(!star.empty()) {
                        star.pop();
                    }
                    // if neither '(' nor '*' is available, the string is invalid immediately
                    else return false;
                }
            }
        }
        
        // after the first pass, try to match any leftover '(' with leftover '*'
        while(!st.empty() && !star.empty()) {
            // a '*' can only act as a closing bracket ')' if it appears AFTER the '('
            if(st.top() > star.top()) {
                return false;
            }
            
            // Pop both if they are a valid match
            st.pop();
            star.pop();
        }
        
        // If 'st' is empty, all '(' were successfully matched, returning true
        return st.empty();
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
