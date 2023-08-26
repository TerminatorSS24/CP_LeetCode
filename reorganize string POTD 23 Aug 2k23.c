/*Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.

Return any possible rearrangement of s or return "" if not possible.

 

Example 1:

Input: s = "aab"
Output: "aba"
Example 2:

Input: s = "aaab"
Output: ""
**********LEETCODE POTD(23/08/2023)**********
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char ch;
    int freq;
} CharFreq;

int compare(const void* a, const void* b) {
    return ((CharFreq*)b)->freq - ((CharFreq*)a)->freq;
}

char* reorganizeString(char* s) {
    int n = strlen(s);
    int charCount[26] = {0};

    for (int i = 0; i < n; i++) {
        charCount[s[i] - 'a']++;
        if (charCount[s[i] - 'a'] > (n + 1) / 2) {
            return "";
        }
    }

    CharFreq charFreqs[26];
    for (int i = 0; i < 26; i++) {
        charFreqs[i].ch = i + 'a';
        charFreqs[i].freq = charCount[i];
    }

    qsort(charFreqs, 26, sizeof(CharFreq), compare);

    char* result = (char*)malloc((n + 1) * sizeof(char));
    int idx = 0;

    for (int i = 0; i < 26; i++) {
        while (charFreqs[i].freq > 0) {
            result[idx] = charFreqs[i].ch;
            idx += 2;
            if (idx >= n) {
                idx = 1;
            }
            charFreqs[i].freq--;
        }
    }

    result[n] = '\0';
    return result;
}