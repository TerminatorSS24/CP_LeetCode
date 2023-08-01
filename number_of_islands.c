// Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

// Example 1:

// Input: grid = [
//   ["1","1","1","1","0"],
//   ["1","1","0","1","0"],
//   ["1","1","0","0","0"],
//   ["0","0","0","0","0"]
// ]
// Output: 1
// Example 2:

// Input: grid = [
//   ["1","1","0","0","0"],
//   ["1","1","0","0","0"],
//   ["0","0","1","0","0"],
//   ["0","0","0","1","1"]
// ]
// Output: 3
#include <stdbool.h>

void dfs(char** grid, int row, int col, int numRows, int numCols) {
    if (row < 0 || row >= numRows || col < 0 || col >= numCols || grid[row][col] == '0') {
        return;
    }

    
    grid[row][col] = '0';

    dfs(grid, row - 1, col, numRows, numCols); 
    dfs(grid, row + 1, col, numRows, numCols); 
    dfs(grid, row, col - 1, numRows, numCols); 
    dfs(grid, row, col + 1, numRows, numCols); 
}

int numIslands(char** grid, int gridSize, int* gridColSize) {
    int numRows = gridSize;
    int numCols = gridColSize[0];
    int numIslands = 0;

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            if (grid[i][j] == '1') {
                numIslands++;
                dfs(grid, i, j, numRows, numCols);
            }
        }
    }

    return numIslands;
}

