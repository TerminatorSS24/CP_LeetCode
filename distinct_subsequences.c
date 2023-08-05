// Given two strings s and t, return the number of distinct 
// subsequences
//  of s which equals t.

// The test cases are generated so that the answer fits on a 32-bit signed integer.

 

// Example 1:

// Input: s = "rabbbit", t = "rabbit"
// Output: 3
// Explanation:
// As shown below, there are 3 ways you can generate "rabbit" from s.
// rabbbit
// rabbbit
// rabbbit
// Example 2:

// Input: s = "babgbag", t = "bag"
// Output: 5
// Explanation:
// As shown below, there are 5 ways you can generate "bag" from s.
// babgbag
// babgbag
// babgbag
// babgbag
// babgbag
#include <stdio.h>
#include <string.h>

#define MOD 1000000007 

int numDistinct(char *s, char *t) {
    int sLen = strlen(s);
    int tLen = strlen(t);

    int dp[sLen + 1][tLen + 1];
    for (int i = 0; i <= sLen; i++) {
        for (int j = 0; j <= tLen; j++) {
            dp[i][j] = 0;
        }
    }

    for (int i = 0; i <= sLen; i++) {
        dp[i][0] = 1;
    }

    for (int i = 1; i <= sLen; i++) {
        for (int j = 1; j <= tLen; j++) {
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[sLen][tLen];
}
