/*
Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.



Example 1:

Input: text1 = "abcde", text2 = "ace"
Output: 3
Explanation: The longest common subsequence is "ace" and its length is 3.
Example 2:

Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.
Example 3:

Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.
**********LEETCODE POTD(25/01/2024)**********
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define max(a, b) a > b ? a : b

int longestCommonSubsequence(char *text1, char *text2)
{
    int numRows = strlen(text1) + 1;
    int numCols = strlen(text2) + 1;

    int **mat = malloc(numRows * sizeof(int *));
    if (mat == NULL)
        return -1;

    for (int i = 0; i < numRows; i++)
    {
        mat[i] = malloc(numCols * sizeof(int));
        if (mat[i] == NULL)
            return -1;
        mat[i][0] = 0;
    }

    for (int i = 0; i < numCols; i++)
        mat[0][i] = 0;

    for (int i = 1; i < numRows; i++)
        for (int j = 1; j < numCols; j++)
            mat[i][j] = (text1[i - 1] == text2[j - 1] ? mat[i - 1][j - 1] + 1 : max(mat[i][j - 1], mat[i - 1][j]));

    return mat[numRows - 1][numCols - 1];
}