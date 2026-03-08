//link to the problem: https://leetcode.com/problems/backspace-string-compare/description/?envType=problem-list-v2&envId=stack
class Solution {
public:
    bool backspaceCompare(string s, string t) {
    	//Time Comp: O(n+m), Space Comp: O(n+m)
        stack<char> st1, st2; 
        
        // Process the first string 's'.
        for(int i = 0; i < s.length(); i++) {
            // If the current character is a normal letter (not a backspace)
            if(s[i] != '#') {
                st1.push(s[i]); 
            }
            // If the character is a backspace ('#')
            else {
                if(!st1.empty()) st1.pop(); 
            }
        }
        
        // Process the second string 't' 
        for(int i = 0; i < t.length(); i++) {
            if(t[i] != '#') {
                st2.push(t[i]);
            }
            else {
                if(!st2.empty()) st2.pop();
            }
        }
        
        // s1 and t1 will store the final typed strings.
        string s1 = "", t1 = ""; 
        
        // Empty the first stack into string s1.
        while(!st1.empty()) {
            s1 += st1.top(); 
            st1.pop();
        }
        
        // Empty the second stack into string t1.
        while(!st2.empty()) {
            t1 += st2.top(); 
            st2.pop();
        }
        
        // identical to each other, it means the original processed strings are equal.
        return s1 == t1;
    }
};

//test case 1
//"ab#c" "ad#c"
//Ans: true

//test case 2
//"ab##" "c#d#"
//Ans: true

//test case 3
//"a#c" "b"
//Ans: false
