/*et's define a function countUniqueChars(s) that returns the number of unique characters on s.

For example, calling countUniqueChars(s) if s = "LEETCODE" then "L", "T", "C", "O", "D" are the unique characters since they appear only once in s, therefore countUniqueChars(s) = 5.
Given a string s, return the sum of countUniqueChars(t) where t is a substring of s. The test cases are generated such that the answer fits in a 32-bit integer.

Notice that some substrings can be repeated so in this case you have to count the repeated ones too.

 

Example 1:

Input: s = "ABC"
Output: 10
Explanation: All possible substrings are: "A","B","C","AB","BC" and "ABC".
Every substring is composed with only unique letters.
Sum of lengths of all substring is 1 + 1 + 1 + 2 + 2 + 3 = 10
Example 2:

Input: s = "ABA"
Output: 8
Explanation: The same as example 1, except countUniqueChars("ABA") = 1.
Example 3:

Input: s = "LEETCODE"
Output: 92*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int uniqueLetterString(string s) {
        vector<vector<int>> mp(26);
        for (int i = 0; i < 26; i++)
            mp[i].push_back(-1);

        for (int i = 0; i < s.length(); i++)
            mp[s[i] - 'A'].push_back(i);

        for (int i = 0; i < 26; i++)
            mp[i].push_back(s.length());

        int res = 0;
        for (int j = 0; j < 26; j++) {
            for (int i = 1; i < mp[j].size() - 1; i++) {
                res += (mp[j][i] - mp[j][i - 1]) * (mp[j][i + 1] - mp[j][i]);
            }
        }
        return res;
    }
};