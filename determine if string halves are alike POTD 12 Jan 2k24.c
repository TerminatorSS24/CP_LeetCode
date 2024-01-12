/*
You are given a string s of even length. Split this string into two halves of equal lengths, and let a be the first half and b be the second half.

Two strings are alike if they have the same number of vowels ('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'). Notice that s contains uppercase and lowercase letters.

Return true if a and b are alike. Otherwise, return false.

 

Example 1:

Input: s = "book"
Output: true
Explanation: a = "bo" and b = "ok". a has 1 vowel and b has 1 vowel. Therefore, they are alike.
Example 2:

Input: s = "textbook"
Output: false
Explanation: a = "text" and b = "book". a has 1 vowel whereas b has 2. Therefore, they are not alike.
Notice that the vowel o is counted twice.
**********LEETCODE POTD(12/01/2024)**********
*/
#include <stdio.h>
#include <stdbool.h>

bool halvesAreAlike(char* s) {
    int i, vowelCount = 0, len, halfLen;
    len = strlen(s);
    halfLen = len/2;
    for (i = 0; i < halfLen; ++i) {
        switch (s[i]) {
            case 'A' :
            case 'E' :
            case 'I' :
            case 'O' :
            case 'U' :
            case 'a' :
            case 'e' :
            case 'i' :
            case 'o' :
            case 'u' : ++vowelCount;
        }
    }
    for (i = halfLen; i < len; ++i) {
        switch (s[i]) {
            case 'A' :
            case 'E' :
            case 'I' :
            case 'O' :
            case 'U' :
            case 'a' :
            case 'e' :
            case 'i' :
            case 'o' :
            case 'u' : --vowelCount;
        }
    }
    return vowelCount == 0;
}