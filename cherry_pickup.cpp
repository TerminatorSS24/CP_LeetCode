/*You are given an n x n grid representing a field of cherries, each cell is one of three possible integers.

0 means the cell is empty, so you can pass through,
1 means the cell contains a cherry that you can pick up and pass through, or
-1 means the cell contains a thorn that blocks your way.
Return the maximum number of cherries you can collect by following the rules below:

Starting at the position (0, 0) and reaching (n - 1, n - 1) by moving right or down through valid path cells (cells with value 0 or 1).
After reaching (n - 1, n - 1), returning to (0, 0) by moving left or up through valid path cells.
When passing through a path cell containing a cherry, you pick it up, and the cell becomes an empty cell 0.
If there is no valid path between (0, 0) and (n - 1, n - 1), then no cherries can be collected.

Example 1:

image: https://assets.leetcode.com/uploads/2020/12/14/grid.jpg

Input: grid = [[0,1,-1],[1,0,-1],[1,1,1]]
Output: 5
Explanation: The player started at (0, 0) and went down, down, right right to reach (2, 2).
4 cherries were picked up during this single trip, and the matrix becomes [[0,1,-1],[0,0,-1],[0,0,0]].
Then, the player went left, up, up, left to return home, picking up one more cherry.
The total number of cherries picked up is 5, and this is the maximum possible.
Example 2:

Input: grid = [[1,1,-1],[1,-1,1],[-1,1,1]]
Output: 0*/
#include <iostream>
#include <vector>
#include <climits>
#include <cstring>

using namespace std;

class Solution {
public:
    int dp[55][55][55];
    int n;
    int dx1[4] = {1,1,0,0};
    int dy1[4] = {0,0,1,1};
    int dx2[4] = {1,0,1,0};
    int dy2[4] = {0,1,0,1};

    int solve(int x1, int y1, int x2, int y2, vector<vector<int>>& grid) {
        if(x1 >= n || y1 >= n || x2 >= n || y2 >= n || grid[x1][y1] == -1 || grid[x2][y2] == -1) {
            return INT_MIN;
        }
        if(x1 == n - 1 && y1 == n - 1) {
            return (grid[x1][y1] == 1);
        }

        if(dp[x1][y1][x2] != -1) {
            return dp[x1][y1][x2];
        }

        int ans = INT_MIN;

        for(int i = 0; i < 4; i++) {
            ans = max(ans, solve(x1 + dx1[i], y1 + dy1[i], x2 + dx2[i], y2 + dy2[i], grid));
        }

        if(ans == INT_MIN) return dp[x1][y1][x2] = ans;

        ans += (grid[x1][y1] == 1);
        ans += (grid[x2][y2] == 1);

        if(x1 == x2 && y1 == y2 && grid[x1][y1] == 1) {
            ans--;
        }

        return  dp[x1][y1][x2] = ans;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();
        memset(dp, -1, sizeof(dp));
        int ans = solve(0, 0, 0, 0, grid);
        return (ans == INT_MIN) ? 0 : ans;
    }
};

