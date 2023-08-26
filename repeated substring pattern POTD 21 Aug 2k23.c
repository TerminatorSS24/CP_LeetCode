/*Given a string s, check if it can be constructed by taking a substring of it and appending multiple copies of the substring together.

 

Example 1:

Input: s = "abab"
Output: true
Explanation: It is the substring "ab" twice.
Example 2:

Input: s = "aba"
Output: false
Example 3:

Input: s = "abcabcabcabc"
Output: true
Explanation: It is the substring "abc" four times or the substring "abcabc" twice.
**********LEETCODE POTD (21/08/2023)**********
*/
#include <stdbool.h>
#include <string.h>

bool repeatedSubstringPattern(char *s) {
    int len = strlen(s);

    for (int subLen = 1; subLen <= len / 2; subLen++) {
        if (len % subLen == 0) {
            bool isPattern = true;

            for (int i = subLen; i < len; i++) {
                if (s[i] != s[i % subLen]) {
                    isPattern = false;
                    break;
                }
            }

            if (isPattern) {
                return true;
            }
        }
    }

    return false;
}
