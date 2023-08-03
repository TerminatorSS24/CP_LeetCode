// The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

// Given an integer n, return the number of distinct solutions to the n-queens puzzle.

 

// Example 1:

// image: https://assets.leetcode.com/uploads/2020/11/13/queens.jpg

// Input: n = 4
// Output: 2
// Explanation: There are two distinct solutions to the 4-queens puzzle as shown.
// Example 2:

// Input: n = 1
// Output: 1
#include <stdio.h>
#include <stdlib.h>

int isSafe(int *queens, int row, int col) {
    for (int i = 0; i < row; i++) {
        if (queens[i] == col || abs(queens[i] - col) == abs(i - row)) {
            return 0;
        }
    }
    return 1;
}

void solveNQueensHelper(int n, int row, int *queens, int *count) {
    if (row == n) {
        (*count)++;
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(queens, row, col)) {
            queens[row] = col;
            solveNQueensHelper(n, row + 1, queens, count);
        }
    }
}

int totalNQueens(int n) {
    int count = 0;
    int *queens = (int *)malloc(sizeof(int) * n);

    solveNQueensHelper(n, 0, queens, &count);

    free(queens);
    return count;
}
