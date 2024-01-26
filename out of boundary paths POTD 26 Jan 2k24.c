/*
There is an m x n grid with a ball. The ball is initially at the position [startRow, startColumn]. You are allowed to move the ball to one of the four adjacent cells in the grid (possibly out of the grid crossing the grid boundary). You can apply at most maxMove moves to the ball.

Given the five integers m, n, maxMove, startRow, startColumn, return the number of paths to move the ball out of the grid boundary. Since the answer can be very large, return it modulo 109 + 7.



Example 1:

image: https://assets.leetcode.com/uploads/2021/04/28/out_of_boundary_paths_1.png

Input: m = 2, n = 2, maxMove = 2, startRow = 0, startColumn = 0
Output: 6
Example 2:

image: https://assets.leetcode.com/uploads/2021/04/28/out_of_boundary_paths_2.png

Input: m = 1, n = 3, maxMove = 3, startRow = 0, startColumn = 1
Output: 12
**********LEETCODE POTD(26/01/2024)**********
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MOD 1000000007

int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
{
    int ***dp = (int ***)malloc(sizeof(int **) * m);
    for (int i = 0; i < m; i++)
    {
        dp[i] = (int **)malloc(sizeof(int *) * n);
        for (int j = 0; j < n; j++)
        {
            dp[i][j] = (int *)malloc(sizeof(int) * (maxMove + 1));
            for (int k = 0; k <= maxMove; k++)
                dp[i][j][k] = -1;
        }
    }

    return myFindPaths(m, n, maxMove, startRow, startColumn, dp);
}

int myFindPaths(int m, int n, int maxMove, int startRow, int startColumn, int ***dp)
{
    if (dp[startRow][startColumn][maxMove] != -1)
        return dp[startRow][startColumn][maxMove];
    dp[startRow][startColumn][maxMove] = 0;
    if (maxMove == 0)
        return 0;
    int re = 0;
    int count = 0;
    if (startRow == 0)
    {
        re++;
        re %= MOD;
    }
    else
    {
        count = myFindPaths(m, n, maxMove - 1, startRow - 1, startColumn, dp) % MOD;
        re += count;
        re %= MOD;
    }
    if (startRow == m - 1)
    {
        re++;
        re %= MOD;
    }
    else
    {
        count = myFindPaths(m, n, maxMove - 1, startRow + 1, startColumn, dp) % MOD;
        re += count;
        re %= MOD;
    }
    if (startColumn == 0)
    {
        re++;
        re %= MOD;
    }
    else
    {
        count = myFindPaths(m, n, maxMove - 1, startRow, startColumn - 1, dp) % MOD;
        re += count;
        re %= MOD;
    }
    if (startColumn == n - 1)
    {
        re++;
        re %= MOD;
    }
    else
    {
        count = myFindPaths(m, n, maxMove - 1, startRow, startColumn + 1, dp) % MOD;
        re += count;
        re %= MOD;
    }
    dp[startRow][startColumn][maxMove] = re;
    return re;
}