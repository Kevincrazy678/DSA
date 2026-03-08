class Solution {
public:
    string reversePrefix(string word, char ch) {
        stack<char> st;
        string res;
        int mark = -1;
        // Time Complexity: O(N)
        for(int i = 0; i < word.size(); i++){
            if(word[i] == ch){
                mark = i;
                break; // Stop immediately after finding the first occurrence
            }
        }
        // case 1: Character not found
        if(mark == -1){
            return word; // Return original string unchanged
        }
        // case 2: Character found
        else{
            // Push characters from start (0) up to 'mark' into the stack
            for(int i = 0; i <= mark; i++){
                st.push(word[i]);
            }
            // Pop from stack and append to 'res' to create the reversed prefix
            while(!st.empty()){
                res += st.top();
                st.pop();
            }
            // Append the rest of the string (from 'mark + 1' to end)
            for(int i = mark + 1; i < word.size(); i++){
                res += word[i];
            }
            return res;
        }
    }
};

//Test case 1
//Input: "abcdefd" "d"
//Expected: "dcbaefd"
//Test case 2
//Input: "xyxzxe" "z"
//Expected: "zxyxxe"
//Test case 3
//Input: "abcd" "z"
//Expected: "abcd"
