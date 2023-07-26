// Write a program to solve a Sudoku puzzle by filling the empty cells.

// A sudoku solution must satisfy all of the following rules:

// Each of the digits 1-9 must occur exactly once in each row.
// Each of the digits 1-9 must occur exactly once in each column.
// Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
// The '.' character indicates empty cells

// Input: board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
// Output: [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]

#include <stdbool.h>

bool isValid(char** board, int row, int col, char num) {
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == num || board[i][col] == num) {
            return false;
        }
    }


    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[startRow + i][startCol + j] == num) {
                return false;
            }
        }
    }

    return true;
}

bool solveSudokuUtil(char** board, int boardSize, int* boardColSize, int row, int col) {
    
    if (row == 9) {
        return true;
    }

    if (col == 9) {
        return solveSudokuUtil(board, boardSize, boardColSize, row + 1, 0);
    }
    if (board[row][col] != '.') {
        return solveSudokuUtil(board, boardSize, boardColSize, row, col + 1);
    }

    
    for (char num = '1'; num <= '9'; num++) {
        if (isValid(board, row, col, num)) {
            
            board[row][col] = num;

            if (solveSudokuUtil(board, boardSize, boardColSize, row, col + 1)) {
                return true;
            }

            board[row][col] = '.';
        }
    }
    return false;
}

void solveSudoku(char** board, int boardSize, int* boardColSize) {
    solveSudokuUtil(board, boardSize, boardColSize, 0, 0);
}
