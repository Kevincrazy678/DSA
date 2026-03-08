class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st; 
        string res = ""; 
        // Iterate through each character 'x' in string 's' (Time: O(N))
        for(auto x : s){
            // CASE 1: Encounter an Open Parenthesis '('
            if(x == '('){
                st.push(x); // Push to stack to record a new level of nesting
                // - If st.size() == 1: This is the very first outermost open parenthesis. We skip adding it to 'res'.
                // - If st.size() > 1: This is an inner open parenthesis. We keep it.
                if(st.size() != 1){
                    res += "(";
                }
            }
            // CASE 2: Encounter a Closing Parenthesis ')'
            else{
                // - If st.size() > 1: The stack still has more than 1 open parenthesis.
                //   => This closing parenthesis matches an inner open parenthesis. We keep it.
                // - If st.size() == 1: This closing parenthesis matches the outer open parenthesis. We skip it.
                if(st.size() != 1){
                    res += ")";
                }
                st.pop(); // Remove the matching open parenthesis from the stack
            }
        }
        
        return res;
    }
};

//Test case 1
//Input: "(()())(())"
//Expected: "()()()"
//Test case 2
//Input: "(()())(())(()(()))"
//Expected: "()()()()(())"
//Test case 3
//Input: "()()"
//Expected: ""
