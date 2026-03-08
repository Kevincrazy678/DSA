//link to the problem: https://leetcode.com/problems/first-unique-character-in-a-string/?envType=problem-list-v2&envId=queue
class Solution {
public:
    int firstUniqChar(string s) {
    	//Time Comp: O(n), Space Comp: O(1)
        int count[26] = {0}; 
        // Step 1: Count the frequency of every character in the string.
        for(char c : s) {
            // 'c - 'a'' converts the character to an index from 0 to 25.
            count[c - 'a']++; 
        }
        
        for(int i = 0; i < s.length(); i++) {
            // Check the frequency of the current character.
            if(count[s[i] - 'a'] == 1) {
                // Return its index immediately since we want the *first* unique character.
                return i; 
            }
        }
        
        // If the loop finishes and we haven't returned anything, return -1
        return -1;
    }
};

//test case 1
//"leetcode"
//Ans: 0

//test case 2
//"loveleetcode"
//Ans: 2

//test case 3
//"aabb"
//Ans: -1
