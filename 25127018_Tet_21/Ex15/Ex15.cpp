//link to the problem: https://leetcode.com/problems/valid-anagram/?envType=problem-list-v2&envId=hash-table
class Solution {
public:
    bool isAnagram(string s, string t) {
    	//Time Comp: O(n), Space Comp: O(1)
        map<char, int> s1, t1;
        // Loop through every character in the first string 's'
        for(int i = 0; i < s.length(); i++) {
            // Increment the frequency count of the current character in map 's1'
            s1[s[i]]++;
        }
        // Loop through every character in the second string 't'
        for(int i = 0; i < t.length(); i++) {
            // Increment the frequency count of the current character in map 't1'
            t1[t[i]]++;
        }
        // This will return true only if both maps have the exact same keys and values
        return t1 == s1;
    }
};

//test case 1
//"III"
//Ans: 3

//test case 2
//"LVIII"
//Ans: 58

//test case 3
//"MCMXCIV"
//Ans: 1994
