// Given a string s, return the longest 
// palindromic substring  in s.

 

// Example 1:

// Input: s = "babad"
// Output: "bab"
// Explanation: "aba" is also a valid answer.
// Example 2:

// Input: s = "cbbd"
// Output: "bb"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char* longestPalindrome(char* s) {
    int n = strlen(s);
    if (n < 2) {
        return s;
    }

    bool dp[n][n];
    memset(dp, false, sizeof(dp));

    int maxLength = 1;
    int start = 0;

    for (int i = 0; i < n; i++) {
        dp[i][i] = true;
    }
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1]) {
            dp[i][i + 1] = true;
            maxLength = 2;
            start = i;
        }
    }

    for (int len = 3; len <= n; len++) {
        for (int i = 0; i < n - len + 1; i++) {
            int j = i + len - 1;
            if (s[i] == s[j] && dp[i + 1][j - 1]) {
                dp[i][j] = true;
                maxLength = len;
                start = i;
            }
        }
    }

    char* result = (char*)malloc((maxLength + 1) * sizeof(char));
    strncpy(result, s + start, maxLength);
    result[maxLength] = '\0';

    return result;
}
