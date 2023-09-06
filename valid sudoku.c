/*Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
Note:

A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.
 

Example 1:

image: https://upload.wikimedia.org/wikipedia/commons/thumb/f/ff/Sudoku-by-L2G-20050714.svg/250px-Sudoku-by-L2G-20050714.svg.png

Input: board = 
[["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: true
Example 2:

Input: board = 
[["8","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: false
Explanation: Same as Example 1, except with the 5 in the top left corner being modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.*/
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isValidSudoku(char** board, int boardSize, int* boardColSize){
    int horizontal[9], vertical[9], block[9][9] = {0};
    for(int i = 0; i < 9; i++){
        memset(horizontal, 0, sizeof(horizontal));
        memset(vertical, 0, sizeof(vertical));
        for(int j = 0; j < 9; j++){
            if (board[i][j] != '.'){
                if(horizontal[(board[i][j] - '0')-1] != 0) return false;
                horizontal[(board[i][j] - '0')-1] = 1;
                
                int block_num = ((int)(i / 3))*3 + (int)(j / 3);
                if (block[block_num][(board[i][j] - '0')-1] != 0) return false;
                block[block_num][(board[i][j] - '0')-1] = 1;
            }  
            if (board[j][i] != '.'){
               if(vertical[(board[j][i] - '0')-1] != 0) return false;
                vertical[(board[j][i] - '0')-1] = 1; 
            }  
        }
    }
    return true;
}