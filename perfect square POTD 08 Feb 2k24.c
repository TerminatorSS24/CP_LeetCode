/*
Given an integer n, return the least number of perfect square numbers that sum to n.

A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself. For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.

 

Example 1:

Input: n = 12
Output: 3
Explanation: 12 = 4 + 4 + 4.
Example 2:

Input: n = 13
Output: 2
Explanation: 13 = 4 + 9
**********LEETCODE POTD(08/02/2024)**********
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int myCheck(int n, int *dp)
{
    if (dp[n] != -1)
        return dp[n];
    if ((int)sqrt(n) * (int)sqrt(n) == n)
    {
        dp[n] = 1;
        return dp[n];
    }
    int re = n, num1;
    for (int i = 1; i * i < n; i++)
    {
        num1 = myCheck(n - i * i, dp);
        if (num1 + 1 < re)
            re = num1 + 1;
    }

    dp[n] = re;
    return re;
}

int numSquares(int n)
{
    int *dp = (int *)malloc(sizeof(int) * (n + 1));
    for (int i = 1; i <= n; i++)
        dp[i] = -1;
    dp[1] = 1;
    return myCheck(n, dp);
}