/*We are given n different types of stickers. Each sticker has a lowercase English word on it.

You would like to spell out the given string target by cutting individual letters from your collection of stickers and rearranging them. You can use each sticker more than once if you want, and you have infinite quantities of each sticker.

Return the minimum number of stickers that you need to spell out target. If the task is impossible, return -1.

Note: In all test cases, all words were chosen randomly from the 1000 most common US English words, and target was chosen as a concatenation of two random words.

 

Example 1:

Input: stickers = ["with","example","science"], target = "thehat"
Output: 3
Explanation:
We can use 2 "with" stickers, and 1 "example" sticker.
After cutting and rearrange the letters of those stickers, we can form the target "thehat".
Also, this is the minimum number of stickers necessary to form the target string.
Example 2:

Input: stickers = ["notice","possible"], target = "basicbasic"
Output: -1
Explanation:
We cannot form the target "basicbasic" from cutting letters from the given stickers.*/
#include <stdio.h>
#include <string.h>
#include <limits.h>

int minStickers(char **stickers, int stickersSize, char *target) {
    int n = strlen(target);
    int dp[1 << n];
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;

    for (int mask = 0; mask < (1 << n); mask++) {
        if (dp[mask] == -1) {
            continue;
        }

        for (int i = 0; i < stickersSize; i++) {
            int curMask = mask;
            for (int j = 0; stickers[i][j]; j++) {
                for (int k = 0; k < n; k++) {
                    if (((curMask >> k) & 1) == 0 && stickers[i][j] == target[k]) {
                        curMask |= (1 << k);
                        break;
                    }
                }
            }

            if (dp[curMask] == -1 || dp[curMask] > dp[mask] + 1) {
                dp[curMask] = dp[mask] + 1;
            }
        }
    }

    return dp[(1 << n) - 1];
}
