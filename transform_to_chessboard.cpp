/*You are given an n x n binary grid board. In each move, you can swap any two rows with each other, or any two columns with each other.

Return the minimum number of moves to transform the board into a chessboard board. If the task is impossible, return -1.

A chessboard board is a board where no 0's and no 1's are 4-directionally adjacent.

 

Example 1:

image: https://assets.leetcode.com/uploads/2021/06/29/chessboard1-grid.jpg

Input: board = [[0,1,1,0],[0,1,1,0],[1,0,0,1],[1,0,0,1]]
Output: 2
Explanation: One potential sequence of moves is shown.
The first move swaps the first and second column.
The second move swaps the second and third row.
Example 2:

image: https://assets.leetcode.com/uploads/2021/06/29/chessboard2-grid.jpg

Input: board = [[0,1],[1,0]]
Output: 0
Explanation: Also note that the board with 0 in the top left corner, is also a valid chessboard.
Example 3:

image: https://assets.leetcode.com/uploads/2021/06/29/chessboard3-grid.jpg

Input: board = [[1,0],[1,0]]
Output: -1
Explanation: No matter what sequence of moves you make, you cannot end with a valid chessboard.*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    int movesToChessboard(vector<vector<int>>& board) {
        int n = board.size();
        int row_counter = 0, col_counter = 0;
        for (int r = 0; r < n; r++) {
            row_counter += board[r][0] ? 1 : -1;
            for (int c = 0; c < n; c++) {
                if (r == 0) col_counter += board[r][c] ? 1 : -1;
                if ((board[r][0] ^ board[0][0]) ^ (board[r][c] ^ board[0][c])) return -1;
            }
        }
        if (abs(row_counter) > 1 || abs(col_counter) > 1) return -1;
        int row_swap_count = 0, col_swap_count = 0, row_0_count = 0, col_0_count = 0;
        for (int i = 0; i < n; i++) {
            if (i & 1) {
                row_swap_count += board[i][0];
                col_swap_count += board[0][i];
            }
            row_0_count += board[i][0] == 0, col_0_count += board[0][i] == 0;
        }
        int odd_position_count = n / 2;
        if (n & 1) {
            row_swap_count = row_0_count == odd_position_count ? row_swap_count : (odd_position_count - row_swap_count);
            col_swap_count = col_0_count == odd_position_count ? col_swap_count : (odd_position_count - col_swap_count);
        } else {
            row_swap_count = min(row_swap_count, odd_position_count - row_swap_count);
            col_swap_count = min(col_swap_count, odd_position_count - col_swap_count);
        }
        return row_swap_count + col_swap_count;
    }
};

