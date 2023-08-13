/*Given a string s, return the number of different non-empty palindromic subsequences in s. Since the answer may be very large, return it modulo 109 + 7.

A subsequence of a string is obtained by deleting zero or more characters from the string.

A sequence is palindromic if it is equal to the sequence reversed.

Two sequences a1, a2, ... and b1, b2, ... are different if there is some i for which ai != bi.



Example 1:

Input: s = "bccb"
Output: 6
Explanation: The 6 different non-empty palindromic subsequences are 'b', 'c', 'bb', 'cc', 'bcb', 'bccb'.
Note that 'bcb' is counted only once, even though it occurs twice.
Example 2:

Input: s = "abcdabcdabcdabcdabcdabcdabcdabcddcbadcbadcbadcbadcbadcbadcbadcba"
Output: 104860361
Explanation: There are 3104860382 different non-empty palindromic subsequences, which is 104860361 modulo 109 + 7.*/
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int mod = 1e9 + 7;

    int countPalindromicSubsequences(string s)
    {
        long long int n = s.length() % mod;
        vector<long long int> prev(n);
        vector<long long int> next(n);
        unordered_map<char, long long int> mp;

        for (long long int i = 0; i < n; i++)
        {
            char a = s[i];
            if (mp.find(a) != mp.end())
            {
                prev[i] = mp[a] % mod;
            }
            else
            {
                prev[i] = -1;
            }
            mp[a] = i % mod;
        }
        mp.clear();
        for (long long int i = n - 1; i >= 0; i--)
        {
            char a = s[i];
            if (mp.find(a) != mp.end())
            {
                next[i] = mp[a] % mod;
            }
            else
            {
                next[i] = -1;
            }
            mp[a] = i % mod;
        }
        vector<vector<long long int>> dp(n, vector<long long int>(n, 0));

        for (long long int k = 0; k < n; k++)
        {
            for (long long int i = 0, j = k + i; i < n and j < n; i++, j++)
            {
                if (k == 0)
                {
                    dp[i][j] = 1;
                }
                else if (k == 1)
                {
                    dp[i][j] = 2;
                }
                else
                {
                    if (s[i] != s[j])
                    {
                        dp[i][j] = ((dp[i][j - 1] % mod) % mod + (dp[i + 1][j] % mod) % mod - (dp[i + 1][j - 1]) % mod) % mod;
                    }
                    else
                    {
                        int n = next[i];
                        int p = prev[j];

                        if (n < p)
                        {
                            dp[i][j] = ((2 * (dp[i + 1][j - 1] % mod) % mod) % mod - (dp[n + 1][p - 1]) % mod) % mod;
                        }
                        else if (n == p)
                        {
                            dp[i][j] = ((2 * (dp[i + 1][j - 1] % mod) % mod) % mod + 1) % mod;
                        }
                        else
                        {
                            dp[i][j] = ((2 * (dp[i + 1][j - 1] % mod) % mod) % mod + 2) % mod;
                        }
                    }
                }
            }
        }
        return ((dp[0][n - 1] % mod + mod) % mod);
    }
};