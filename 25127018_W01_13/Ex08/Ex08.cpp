class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> res;
        for(int i=0; i<words.size(); i++){
            for(auto s : words[i]){
            	//check if word "x" appears in string word
                if(s == x){
                    res.push_back(i);
                    break;
                }
            }
        }
        return res;
    }
};
//Test case 1
//Input: ["leet","code"], x = "e"
//Expected: [0,1]
//Test case 2
//Input: ["abc","bcd","aaaa","cbc"], x = "a"
//Expected: [0,2]
//Test case 3
//Input: ["abc","bcd","aaaa","cbc"], x = "z" 
//Expected: []
