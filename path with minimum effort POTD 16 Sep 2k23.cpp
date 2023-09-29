/*
Code

Testcase
Testcase
Result

1631. Path With Minimum Effort
Medium
Topics
Companies
Hint
You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.

A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.

Return the minimum effort required to travel from the top-left cell to the bottom-right cell.

 

Example 1:

image: https://assets.leetcode.com/uploads/2020/10/04/ex1.png

Input: heights = [[1,2,2],[3,8,2],[5,3,5]]
Output: 2
Explanation: The route of [1,3,5,3,5] has a maximum absolute difference of 2 in consecutive cells.
This is better than the route of [1,2,2,2,5], where the maximum absolute difference is 3.
Example 2:

image: https://assets.leetcode.com/uploads/2020/10/04/ex2.png

Input: heights = [[1,2,3],[3,8,4],[5,3,5]]
Output: 1
Explanation: The route of [1,2,3,4,5] has a maximum absolute difference of 1 in consecutive cells, which is better than route [1,3,5,3,5].
Example 3:

image: https://assets.leetcode.com/uploads/2020/10/04/ex3.png

Input: heights = [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]
Output: 0
Explanation: This route does not require any effort.
**********LEETCODE POTD(16/09/2023)**********
*/
#include <vector>
#include <cstring>
#include <cstdlib>

using namespace std;

class Solution
{
    int mv[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int n, m;
    bool isOk(int i, int j)
    {
        return i >= 0 && j >= 0 && i < n && j < m;
    }
    int vis[100][100];
    bool f(vector<vector<int>> &H, int i, int j, int mid)
    {
        if (i == n - 1 && j == m - 1)
            return true;
        bool ans = false;
        vis[i][j] = 1;
        for (int k = 0; k < 4; k++)
        {
            int x = i + mv[k][0], y = j + mv[k][1];
            if (isOk(x, y) && vis[x][y] == -1 && abs(H[i][j] - H[x][y]) <= mid)
                ans |= f(H, x, y, mid);
        }
        return ans;
    }

public:
    int minimumEffortPath(vector<vector<int>> &H)
    {
        n = H.size(), m = H[0].size();
        int l = 0, r = 1e6, ans = 0;
        while (l <= r)
        {
            memset(vis, -1, sizeof(vis));
            int mid = (l + r) / 2;
            if (f(H, 0, 0, mid))
            {
                ans = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return ans;
    }
};
