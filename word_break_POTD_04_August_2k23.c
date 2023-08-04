// Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

// Note that the same word in the dictionary may be reused multiple times in the segmentation.

 

// Example 1:

// Input: s = "leetcode", wordDict = ["leet","code"]
// Output: true
// Explanation: Return true because "leetcode" can be segmented as "leet code".
// Example 2:

// Input: s = "applepenapple", wordDict = ["apple","pen"]
// Output: true
// Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
// Note that you are allowed to reuse a dictionary word.
// Example 3:

// Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
// Output: false
//**********LEETCODE POTD(04/08/2023)**********
#include <stdbool.h>
#include <string.h>

bool wordBreak(char *s, char **wordDict, int wordDictSize) {
    int len = strlen(s);
    bool dp[len + 1];
    memset(dp, false, sizeof(dp));

    dp[0] = true; 

    for (int i = 1; i <= len; i++) {
        for (int j = 0; j < wordDictSize; j++) {
            int wordLen = strlen(wordDict[j]);
            if (i >= wordLen && dp[i - wordLen] &&
                strncmp(s + i - wordLen, wordDict[j], wordLen) == 0) {
                dp[i] = true;
                break;
            }
        }
    }

    return dp[len];
}


