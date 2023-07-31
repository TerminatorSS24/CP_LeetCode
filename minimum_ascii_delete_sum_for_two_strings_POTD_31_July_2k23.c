// Given two strings s1 and s2, return the lowest ASCII sum of deleted characters to make two strings equal.

 

// Example 1:

// Input: s1 = "sea", s2 = "eat"
// Output: 231
// Explanation: Deleting "s" from "sea" adds the ASCII value of "s" (115) to the sum.
// Deleting "t" from "eat" adds 116 to the sum.
// At the end, both strings are equal, and 115 + 116 = 231 is the minimum sum possible to achieve this.
// Example 2:

// Input: s1 = "delete", s2 = "leet"
// Output: 403
// Explanation: Deleting "dee" from "delete" to turn the string into "let",
// adds 100[d] + 101[e] + 101[e] to the sum.
// Deleting "e" from "leet" adds 101[e] to the sum.
// At the end, both strings are equal to "let", and the answer is 100+101+101+101 = 403.
// If instead we turned both strings into "lee" or "eet", we would get answers of 433 or 417, which are higher.
//**********LEETCODE POTD(31/07/2023)**********
#include <stdio.h>
#include <string.h>

int min(int a, int b) {
    return a < b ? a : b;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int minimumDeleteSum(char* s1, char* s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    int dp[len1 + 1][len2 + 1];

    for (int i = 0; i <= len1; i++) {
        dp[i][0] = 0;
    }
    for (int j = 0; j <= len2; j++) {
        dp[0][j] = 0;
    }

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + s1[i - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    int asciiSum1 = 0;
    int asciiSum2 = 0;
    for (int i = 0; i < len1; i++) {
        asciiSum1 += s1[i];
    }
    for (int i = 0; i < len2; i++) {
        asciiSum2 += s2[i];
    }

    return asciiSum1 + asciiSum2 - 2 * dp[len1][len2];
}

