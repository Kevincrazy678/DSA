class Solution {
public:
    int maxDepth(string s) {
        stack<char> st; 
        int res = 0; 
        // Time Complexity: O(N) where N is the string length
        for(auto x : s){
            if(x == '('){
                st.push(x);
                // Update 'res' to be the maximum between current max and stack size
                int st_size = st.size();
                res = max(res, st_size);
            }
            else if(x == ')'){
                if(!st.empty()){
                    st.pop();
                }
            }
        }
        return res;
    }
};

//Test case 1
//Input: "(1+(2*3)+((8)/4))+1"
//Expected: 3
//Test case 2
//Input: "(1)+((2))+(((3)))"
//Expected: 3
//Test case 3
//Input: "()(())((()()))"
//Expected: 3
