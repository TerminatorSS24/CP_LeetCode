/*Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).



Example 1:

Input: s = "abc", t = "ahbgdc"
Output: true
Example 2:

Input: s = "axc", t = "ahbgdc"
Output: false
**********LEETCODE POTD(22/09/2023)**********
*/
#include <stdio.h>
#include <stdbool.h>
int sL, tL;
char *S, *T;

bool checker(int sP, int tP)
{
    if (sP == sL)
        return true;
    if (tP == tL)
        return false;

    return (S[sP] == T[tP]) ? checker(sP + 1, tP + 1) : checker(sP, tP + 1);
}

bool isSubsequence(char *s, char *t)
{
    sL = strlen(s);
    tL = strlen(t);
    S = s;
    T = t;
    return checker(0, 0);
}