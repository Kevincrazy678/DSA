//link to the problem: https://leetcode.com/problems/check-if-all-characters-have-equal-number-of-occurrences/?envType=problem-list-v2&envId=hash-table
class Solution {
public:
    bool areOccurrencesEqual(string s) {
    	//Time Comp: O(nlogk), Space Comp: O(k), k is the number of unique characters
        map<char, int>mp;
        int cnt = 0;
        for(int i=0; i<s.length(); i++){
        	// Increment the occurrence count for the current character
            mp[s[i]]++;
            // Dynamically update 'cnt' to hold the maximum frequency
            cnt = max(cnt, mp[s[i]]);
        }
        for(auto x : mp){
        	// If we find any character whose frequency (x.second) does not match the max 'cnt'
            if(x.second != cnt)return false;
        }
        return true;
    }
};

//test case 1
//"abacbc"
//Ans: true

//test case 2
//"aaabb"
//Ans: false

//test case 3
//"ahdjahdwdasd"
//Ans: false
