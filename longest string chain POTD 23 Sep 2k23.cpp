/*You are given an array of words where each word consists of lowercase English letters.

wordA is a predecessor of wordB if and only if we can insert exactly one letter anywhere in wordA without changing the order of the other characters to make it equal to wordB.

For example, "abc" is a predecessor of "abac", while "cba" is not a predecessor of "bcad".
A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1, where word1 is a predecessor of word2, word2 is a predecessor of word3, and so on. A single word is trivially a word chain with k == 1.

Return the length of the longest possible word chain with words chosen from the given list of words.

 

Example 1:

Input: words = ["a","b","ba","bca","bda","bdca"]
Output: 4
Explanation: One of the longest word chains is ["a","ba","bda","bdca"].
Example 2:

Input: words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
Output: 5
Explanation: All the words can be put in a word chain ["xb", "xbc", "cxbc", "pcxbc", "pcxbcf"].
Example 3:

Input: words = ["abcd","dbqca"]
Output: 1
Explanation: The trivial word chain ["abcd"] is one of the longest word chains.
["abcd","dbqca"] is not a valid word chain because the ordering of the letters is changed.
**********LEETCODE POTD(23/09/2023)**********
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

class Solution
{
public:
    vector<vector<int>> dp;

    static bool comp(const string &a, const string &b)
    {
        return a.length() < b.length();
    }

    bool checkHelper(string &a, string &b)
    {
        bool flag = false;
        for (int i = 0; i < a.length(); i++)
        {
            if (!flag && a[i] != b[i])
                flag = true;
            if (flag && a[i] != b[i + 1])
                return false;
        }
        return true;
    }

    bool check(string &a, string &b)
    {
        int n = a.length();
        int m = b.length();
        if (abs(n - m) != 1)
            return false;
        if (a.length() > b.length())
            return checkHelper(b, a);
        return checkHelper(a, b);
    }

    int solve(vector<string> &words, int i, int j)
    {
        if (i >= words.size())
            return 0;
        if (dp[i][j + 1] != -1)
            return dp[i][j + 1];
        if (j == -1 || check(words[i], words[j]))
            dp[i][j + 1] = max(dp[i][j + 1], 1 + solve(words, i + 1, i));
        return dp[i][j + 1] = max(dp[i][j + 1], solve(words, i + 1, j));
    }

    int longestStrChain(vector<string> &words)
    {
        dp = vector<vector<int>>(words.size(), vector<int>(words.size() + 1, -1));
        sort(words.begin(), words.end(), comp);
        return solve(words, 0, -1);
    }
};