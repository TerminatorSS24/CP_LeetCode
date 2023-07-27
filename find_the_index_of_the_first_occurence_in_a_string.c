// Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

 

// Example 1:

// Input: haystack = "sadbutsad", needle = "sad"
// Output: 0
// Explanation: "sad" occurs at index 0 and 6.
// The first occurrence is at index 0, so we return 0.
// Example 2:

// Input: haystack = "leetcode", needle = "leeto"
// Output: -1
// Explanation: "leeto" did not occur in "leetcode", so we return -1.





#include <stdbool.h>

int strStr(char *haystack, char *needle) {
    if (haystack == '\0' || needle == '\0')
        return -1;

    int haystackLen = strlen(haystack);
    int needleLen = strlen(needle);

    if (needleLen == 0)
        return 0;

    for (int i = 0; i <= haystackLen - needleLen; i++) {
        bool found = true;
        for (int j = 0; j < needleLen; j++) {
            if (haystack[i + j] != needle[j]) {
                found = false;
                break;
            }
        }
        if (found)
            return i;
    }

    return -1;
}
