/*You are given an m x n integer array grid where grid[i][j] could be:

1 representing the starting square. There is exactly one starting square.
2 representing the ending square. There is exactly one ending square.
0 representing empty squares we can walk over.
-1 representing obstacles that we cannot walk over.
Return the number of 4-directional walks from the starting square to the ending square, that walk over every non-obstacle square exactly once.

 

Example 1:

image: https://assets.leetcode.com/uploads/2021/08/02/lc-unique1.jpg

Input: grid = [[1,0,0,0],[0,0,0,0],[0,0,2,-1]]
Output: 2
Explanation: We have the following two paths: 
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)
Example 2:

image: https://assets.leetcode.com/uploads/2021/08/02/lc-unique2.jpg

Input: grid = [[1,0,0,0],[0,0,0,0],[0,0,0,2]]
Output: 4
Explanation: We have the following four paths: 
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2),(2,3)
2. (0,0),(0,1),(1,1),(1,0),(2,0),(2,1),(2,2),(1,2),(0,2),(0,3),(1,3),(2,3)
3. (0,0),(1,0),(2,0),(2,1),(2,2),(1,2),(1,1),(0,1),(0,2),(0,3),(1,3),(2,3)
4. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2),(2,3)
Example 3:

image: https://assets.leetcode.com/uploads/2021/08/02/lc-unique3-.jpg

Input: grid = [[0,1],[2,0]]
Output: 0
Explanation: There is no path that walks over every empty square exactly once.
Note that the starting and ending square can be anywhere in the grid.*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int solve(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& visited, int m, int n, int count, int walk) {
        if (row < 0 || col < 0 || row > m - 1 || col > n - 1 || grid[row][col] == -1) {
            return 0;
        }
        if (grid[row][col] == 2) {
            if (count == walk)
                return 1;

            return 0;
        }
        if (visited[row][col]) {
            return 0;
        }

        visited[row][col] = 1;

        int up = solve(row - 1, col, grid, visited, m, n, count + 1, walk);
        int right = solve(row, col + 1, grid, visited, m, n, count + 1, walk);
        int down = solve(row + 1, col, grid, visited, m, n, count + 1, walk);
        int left = solve(row, col - 1, grid, visited, m, n, count + 1, walk);

        visited[row][col] = 0;
        return up + right + down + left;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size(); // rows
        int n = grid[0].size(); // cols

        vector<vector<int>> visited(m, vector<int>(n, 0));
        int walk = 0;
        int count = 0;
        int row = 0, col = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    row = i;
                    col = j;
                }
                if (grid[i][j] == 0 || grid[i][j] == 2) {
                    walk++;
                }
            }
        }

        return solve(row, col, grid, visited, m, n, count, walk);
    }
};