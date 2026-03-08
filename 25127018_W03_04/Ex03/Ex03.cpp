class Solution {
public:
    string clearDigits(string s) {
        stack<char> st;  
        string res = ""; 
        // Time Complexity: O(N) where N is the length of string 's'
        for(auto x : s){
            // case 1: The character is not a digit (it is a letter)
            if(!isdigit(x)){
                st.push(x);
            }
            // Case 2: The character is a digit
            else{
                // a digit acts as a "delete" command for the closest non-digit to its left.
                // we can remove the top element of the stack.
                if(!st.empty()){
                    st.pop();
                }
            }
        }
        
        if(st.empty()){
            return res; // Return empty string if no characters remain
        }
        else{
            // Transfer characters from stack to string 'res'
            // Since Stack is LIFO, 'res' will be in reverse order
            while(!st.empty()){
                res += st.top();
                st.pop();
            }
            // Reverse the string to get the correct order
            reverse(res.begin(), res.end());
            
            return res;
        }
    }
};

//Test case 1
//Input: "abc"
//Expected: "abc"
//Test case 2
//Input: "cb34"
//Expected: "zxyxxe"
//Test case 3
//Input: "rule67"
//Expected: "ru"
