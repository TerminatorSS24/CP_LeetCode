/*
You are given two strings of the same length s and t. In one step you can choose any character of t and replace it with another character.

Return the minimum number of steps to make t an anagram of s.

An Anagram of a string is a string that contains the same characters with a different (or the same) ordering.

 

Example 1:

Input: s = "bab", t = "aba"
Output: 1
Explanation: Replace the first 'a' in t with b, t = "bba" which is anagram of s.
Example 2:

Input: s = "leetcode", t = "practice"
Output: 5
Explanation: Replace 'p', 'r', 'a', 'i' and 'c' from t with proper characters to make t anagram of s.
Example 3:

Input: s = "anagram", t = "mangaar"
Output: 0
Explanation: "anagram" and "mangaar" are anagrams. 
**********LEETCODE POTD(13/01/2024)**********
*/
#include <stdio.h>
#include <stdlib.h>

int minSteps(char *s, char *t)
{
    const int n = strlen(s), m = strlen(t);
    int *count = (int *)calloc(26, sizeof(int));
    for (int i = 0; i < n; i++)
        count[s[i] - 'a']++;
    for (int i = 0; i < m; i++)
        count[t[i] - 'a']--;
    int r = 0;
    for (int i = 0; i < 26; i++)
    {
        if (count[i] <= 0)
            continue;
        r += abs(count[i]);
    }
    free(count);
    return r;
}
