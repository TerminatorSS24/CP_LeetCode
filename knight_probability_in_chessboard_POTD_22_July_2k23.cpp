// On an n x n chessboard, a knight starts at the cell (row, column) and attempts to make exactly k moves. The rows and columns are 0-indexed, so the top-left cell is (0, 0), and the bottom-right cell is (n - 1, n - 1).

// A chess knight has eight possible moves it can make, as illustrated below. Each move is two cells in a cardinal direction, then one cell in an orthogonal direction.
//image = https://assets.leetcode.com/uploads/2018/10/12/knight.png
// Each time the knight is to move, it chooses one of eight possible moves uniformly at random (even if the piece would go off the chessboard) and moves there.

// The knight continues moving until it has made exactly k moves or has moved off the chessboard.

// Return the probability that the knight remains on the board after it has stopped moving.

 

// Example 1:

// Input: n = 3, k = 2, row = 0, column = 0
// Output: 0.06250
// Explanation: There are two moves (to (1,2), (2,1)) that will keep the knight on the board.
// From each of those positions, there are also two moves that will keep the knight on the board.
// The total probability the knight stays on the board is 0.0625.
// Example 2:

// Input: n = 1, k = 0, row = 0, column = 0
// Output: 1.00000
//**********LEETCODE POTD(22/07/2023)**********

#include <vector>
using namespace std;

class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>> memo(n, vector<vector<double>>(n, vector<double>(k + 1, -1.0)));
        return dfs(n, k, row, column, memo);
    }

    double dfs(int n, int k, int row, int column, vector<vector<vector<double>>>& memo) {
        if (row < 0 || row >= n || column < 0 || column >= n)
            return 0.0;
        if (k == 0)
            return 1.0;
        if (memo[row][column][k] != -1.0)
            return memo[row][column][k];

        double probability = 0.0;
        vector<pair<int, int>> moves = { {2, 1}, {1, 2}, {2, -1}, {1, -2}, {-2, 1}, {-1, 2}, {-2, -1}, {-1, -2} };
        for (const auto& move : moves) {
            int newRow = row + move.first;
            int newColumn = column + move.second;
            probability += 0.125 * dfs(n, k - 1, newRow, newColumn, memo);
        }

        memo[row][column][k] = probability;
        return probability;
    }
};
