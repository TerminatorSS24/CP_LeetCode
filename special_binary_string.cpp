/*Special binary strings are binary strings with the following two properties:

The number of 0's is equal to the number of 1's.
Every prefix of the binary string has at least as many 1's as 0's.
You are given a special binary string s.

A move consists of choosing two consecutive, non-empty, special substrings of s, and swapping them. Two strings are consecutive if the last character of the first string is exactly one index before the first character of the second string.

Return the lexicographically largest resulting string possible after applying the mentioned operations on the string.

 

Example 1:

Input: s = "11011000"
Output: "11100100"
Explanation: The strings "10" [occuring at s[1]] and "1100" [at s[3]] are swapped.
This is the lexicographically largest string possible after some number of swaps.
Example 2:

Input: s = "10"
Output: "10"*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string makeLargestSpecial(string s) {
        vector<string> specials; 
        int cnt = 0;
        for (char c : s) {
            if (cnt == 0) specials.push_back("");
            c == '1' ? ++cnt : --cnt;
            specials.back() += c;            
        }

        for (auto& special : specials)
            special = '1' + makeLargestSpecial(special.substr(1, special.size() - 2)) + '0';
        
        sort(specials.begin(), specials.end(), greater<string>());

        string res;
        for (auto& special : specials) res += special;
        return res;
    }
};