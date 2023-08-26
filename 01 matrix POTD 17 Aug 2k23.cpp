/*Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.

 

Example 1:

image: https://assets.leetcode.com/uploads/2021/04/24/01-1-grid.jpg

Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
Output: [[0,0,0],[0,1,0],[0,0,0]]
Example 2:

image: https://assets.leetcode.com/uploads/2021/04/24/01-2-grid.jpg

Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
Output: [[0,0,0],[0,1,0],[1,2,1]]
**********LEETCODE POTD(17/08/2023)**********
*/
#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        vector<vector<int>> result(m, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    result[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        
        vector<pair<int, int>> dirs{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        while (!q.empty()) {
            pair<int, int> cell = q.front();
            q.pop();
            
            for (const auto& dir : dirs) {
                int newRow = cell.first + dir.first;
                int newCol = cell.second + dir.second;
                if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n) {
                    if (result[newRow][newCol] > result[cell.first][cell.second] + 1) {
                        result[newRow][newCol] = result[cell.first][cell.second] + 1;
                        q.push({newRow, newCol});
                    }
                }
            }
        }
        
        return result;
    }
};
