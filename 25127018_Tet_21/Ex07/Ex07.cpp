//link to the problem: https://leetcode.com/problems/score-of-parentheses/?envType=problem-list-v2&envId=stack
class Solution {
public:
    int scoreOfParentheses(string s) {
    	//Time Comp: O(n), Space Comp: O(n)
        stack<int>st;
        st.push(0);
        for(int i=0; i<s.length(); i++){
            if(s[i] == '('){
                st.push(0);
            }
            else{
                int top = st.top(); st.pop();
                // The rule says:
                // - If inner_score is 0, it means it was an empty "()", which has a score of 1.
                // - If inner_score > 0, it means there were nested parentheses like "(A)", 
                //   so the score is 2 * inner_score.
                int cur = max(top*2, 1);
                if(!st.empty()){
                    int top2 = st.top(); st.pop();
                    st.push(cur + top2);
                }
            }
        }
        return st.top();
    }
};

//test case 1
//()
//Ans: 1

//test case 2
//()()
//Ans: 2

//test case 3
//(())
//Ans: 2
