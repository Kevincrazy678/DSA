//link to the problem: https://leetcode.com/problems/maximum-number-of-words-you-can-type/?envType=problem-list-v2&envId=hash-table
class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
    	//Time Comp: O(n+m) where n is the length of text and m is the length of brokenLetters, Space Comp: O(1)
    	
        bool ch[26] = {false}, check = true;
        // 'res' will keep the final count of fully valid words
        int res = 0;
        for(int i=0; i<brokenLetters.size(); i++){
        	// Convert the character to an index (0 to 25) and mark that specific key as true (broken)
            ch[brokenLetters[i] - 'a'] = true;
        }
        for(int i=0; i<text.size(); i++){
        	// If the current character is a space, it indicates the end of a word
            if(text[i] == ' '){
            	// If the 'check' flag is still true, the entire previous word was valid, so we count it
                if(check)res++;
                // Reset the flag back to true for the brand new word that follows the space
                check = true;
            }
            else{
            	// Look up the letter in our boolean array to see if the key is broken
                if(ch[text[i] - 'a'])check = false;
            }
        }
        // Since the string does not end with a trailing space, the very last word isn't counted in the loop, so we need to check for the last time
        if(check)res++;
        return res;
    }
};

//test case 1
//"hello world" "ad"
//Ans: 1 

//test case 2
//"leet code" "lt"
//Ans: 1

//test case 3
//"leet code" "e"
//Ans: 1
