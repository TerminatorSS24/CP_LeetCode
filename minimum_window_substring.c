// Given two strings s and t of lengths m and n respectively, return the minimum window 
// substring
//  of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

// The testcases will be generated such that the answer is unique.

 

// Example 1:

// Input: s = "ADOBECODEBANC", t = "ABC"
// Output: "BANC"
// Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
// Example 2:

// Input: s = "a", t = "a"
// Output: "a"
// Explanation: The entire string s is the minimum window.
// Example 3:

// Input: s = "a", t = "aa"
// Output: ""
// Explanation: Both 'a's from t must be included in the window.
// Since the largest window of s only has one 'a', return empty string.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHAR_COUNT 256 

char *minWindow(char *s, char *t) {
    int sLen = strlen(s);
    int tLen = strlen(t);

    if (tLen > sLen) {
        return "";
    }

    int tFreq[CHAR_COUNT] = {0}; 
    int sFreq[CHAR_COUNT] = {0}; 

    for (int i = 0; i < tLen; i++) {
        tFreq[t[i]]++;
    }

    int left = 0;      
    int minLength = sLen + 1; 
    int minStart = 0;  
    int count = 0;     

    for (int right = 0; right < sLen; right++) {
        if (tFreq[s[right]] > 0) {
            sFreq[s[right]]++;

            if (sFreq[s[right]] <= tFreq[s[right]]) {
                count++;
            }

            while (count == tLen) {
                if (right - left + 1 < minLength) {
                    minLength = right - left + 1;
                    minStart = left;
                }

                if (tFreq[s[left]] > 0) {
                    sFreq[s[left]]--;

                    if (sFreq[s[left]] < tFreq[s[left]]) {
                        count--;
                    }
                }

                left++;
            }
        }
    }

    if (minLength > sLen) {
        return "";
    }

    char *result = (char *)malloc((minLength + 1) * sizeof(char));
    strncpy(result, s + minStart, minLength);
    result[minLength] = '\0';

    return result;
}

