// The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

// Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

// Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.


//image: https://assets.leetcode.com/uploads/2020/11/13/queens.jpg

// Example 1:
// Input: n = 4
// Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
// Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
// Example 2:

// Input: n = 1
// Output: [["Q"]]
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isSafe(char **board, int row, int col, int n) {
    for (int i = 0; i < col; i++) {
        if (board[row][i] == 'Q') {
            return 0;
        }
    }

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q') {
            return 0;
        }
    }

    for (int i = row, j = col; i < n && j >= 0; i++, j--) {
        if (board[i][j] == 'Q') {
            return 0;
        }
    }

    return 1;
}

void solveNQueensHelper(int n, int col, char **board, char ***result, int *returnSize, int **returnColumnSizes) {
    if (col == n) {
        result[*returnSize] = (char **)malloc(sizeof(char *) * n);
        returnColumnSizes[0][*returnSize] = n;

        for (int i = 0; i < n; i++) {
            result[*returnSize][i] = strdup(board[i]);
        }

        (*returnSize)++;
        return;
    }

    for (int i = 0; i < n; i++) {
        if (isSafe(board, i, col, n)) {
            board[i][col] = 'Q';
            solveNQueensHelper(n, col + 1, board, result, returnSize, returnColumnSizes);
            board[i][col] = '.';
        }
    }
}

char ***solveNQueens(int n, int *returnSize, int **returnColumnSizes) {
    char ***result = (char ***)malloc(sizeof(char **) * 1000);
    *returnSize = 0;

    char **board = (char **)malloc(sizeof(char *) * n);
    for (int i = 0; i < n; i++) {
        board[i] = (char *)malloc(sizeof(char) * (n + 1));
        memset(board[i], '.', n);
        board[i][n] = '\0';
    }

    *returnColumnSizes = (int *)malloc(sizeof(int) * 1000);

    solveNQueensHelper(n, 0, board, result, returnSize, returnColumnSizes);

    return result;
}

