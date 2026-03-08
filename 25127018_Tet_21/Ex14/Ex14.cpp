//link to the problem: https://leetcode.com/problems/roman-to-integer/?envType=problem-list-v2&envId=hash-table
class Solution {
public:
    int romanToInt(string s) {
    	//Time Comp: O(n), Space Comp: O(1)
    	
        // Create a hash map to store the integer values of the 7 basic Roman symbols
        unordered_map<char, int> sym = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, 
            {'C', 100}, {'D', 500}, {'M', 1000}
        };
        
        int res = 0, n = s.length();
        // Loop through each character in the string from left to right
        for(int i = 0; i < n; i++) {
            // Check if we are NOT at the last character AND the current symbol's value 
            if(i < n - 1 && sym[s[i]] < sym[s[i+1]]) {
                // Apply the subtraction rule: subtract the current symbol's value from the result
                res -= sym[s[i]];
            }
            else {
                // Otherwise, apply the standard addition rule: add the current symbol's value
                res += sym[s[i]];
            }
        }
        // Return the fully accumulated integer value
        return res;
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
