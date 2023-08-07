// Given an m x n integers matrix, return the length of the longest increasing path in matrix.

// From each cell, you can either move in four directions: left, right, up, or down. You may not move diagonally or move outside the boundary (i.e., wrap-around is not allowed).

 

// Example 1:

// image: https://assets.leetcode.com/uploads/2021/01/05/grid1.jpg

// Input: matrix = [[9,9,4],[6,6,8],[2,1,1]]
// Output: 4
// Explanation: The longest increasing path is [1, 2, 6, 9].
// Example 2:

// image: https://assets.leetcode.com/uploads/2021/01/27/tmp-grid.jpg

// Input: matrix = [[3,4,5],[3,2,6],[2,2,1]]
// Output: 4
// Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
// Example 3:

// Input: matrix = [[1]]
// Output: 1
#include <stdio.h>
#include <stdlib.h>
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int dfs(int** matrix, int** memo, int i, int j, int m, int n) {
    if (memo[i][j] != -1) {
        return memo[i][j];
    }

    int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int maxPath = 1;

    for (int d = 0; d < 4; ++d) {
        int newRow = i + directions[d][0];
        int newCol = j + directions[d][1];

        if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n &&
            matrix[newRow][newCol] > matrix[i][j]) {
            maxPath = MAX(maxPath, 1 + dfs(matrix, memo, newRow, newCol, m, n));
        }
    }

    memo[i][j] = maxPath;
    return maxPath;
}

int longestIncreasingPath(int** matrix, int matrixSize, int* matrixColSize) {
    if (matrixSize == 0 || *matrixColSize == 0) {
        return 0;
    }

    int m = matrixSize;
    int n = *matrixColSize;
    int result = 0;

    int** memo = (int**)malloc(sizeof(int*) * m);
    for (int i = 0; i < m; ++i) {
        memo[i] = (int*)malloc(sizeof(int) * n);
        for (int j = 0; j < n; ++j) {
            memo[i][j] = -1;
        }
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            result = MAX(result, dfs(matrix, memo, i, j, m, n));
        }
    }

    for (int i = 0; i < m; ++i) {
        free(memo[i]);
    }
    free(memo);

    return result;
}
