// You are given a string s. You can convert s to a 
// palindrome
//  by adding characters in front of it.

// Return the shortest palindrome you can find by performing this transformation.

 

// Example 1:

// Input: s = "aacecaaa"
// Output: "aaacecaaa"
// Example 2:

// Input: s = "abcd"
// Output: "dcbabcd"





#include <stdlib.h>
#include <string.h>

void computeLPSArray(char *pat, int M, int *lps) {
    int len = 0;
    lps[0] = 0;
    
    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0)
                len = lps[len - 1];
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

char * shortestPalindrome(char *s) {
    int len = strlen(s);
    char *result = (char *)malloc((2 * len + 1) * sizeof(char));
    
    int newSize = 2 * len + 1;
    char *newStr = (char *)malloc(newSize * sizeof(char));
    strcpy(newStr, s);
    newStr[len] = '#';
    for (int i = 0; i < len; i++) {
        newStr[len + i + 1] = s[len - i - 1];
    }
    
    int *lps = (int *)malloc(newSize * sizeof(int));
    computeLPSArray(newStr, newSize, lps);
    
    int prefixEnd = len - lps[newSize - 1];
    
    for (int i = 0; i < prefixEnd; i++) {
        result[i] = s[len - 1 - i];
    }
    strcpy(&result[prefixEnd], s);
    
    free(newStr);
    free(lps);
    
    return result;
}
