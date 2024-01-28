/*
Given a matrix and a target, return the number of non-empty submatrices that sum to target.

A submatrix x1, y1, x2, y2 is the set of all cells matrix[x][y] with x1 <= x <= x2 and y1 <= y <= y2.

Two submatrices (x1, y1, x2, y2) and (x1', y1', x2', y2') are different if they have some coordinate that is different: for example, if x1 != x1'.



Example 1:

image: https://assets.leetcode.com/uploads/2020/09/02/mate1.jpg

Input: matrix = [[0,1,0],[1,1,1],[0,1,0]], target = 0
Output: 4
Explanation: The four 1x1 submatrices that only contain 0.
Example 2:

Input: matrix = [[1,-1],[-1,1]], target = 0
Output: 5
Explanation: The two 1x2 submatrices, plus the two 2x1 submatrices, plus the 2x2 submatrix.
Example 3:

Input: matrix = [[904]], target = 0
Output: 0
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int numSubmatrixSumTarget(vector<vector<int>> &matrix, int target)
    {
        int n = matrix.size(), m = matrix[0].size();
        matrix.insert(matrix.begin(), vector<int>(m, 0));
        for (vector<int> &v : matrix)
            v.insert(v.begin(), 0);
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                matrix[i][j] += matrix[i - 1][j] + matrix[i][j - 1] - matrix[i - 1][j - 1];
        int cnt = 0;
        for (int r1 = 1; r1 <= n; ++r1)
            for (int r2 = r1; r2 <= n; ++r2)
                for (int c1 = 1; c1 <= m; ++c1)
                    for (int c2 = c1; c2 <= m; ++c2)
                        if (matrix[r2][c2] - matrix[r1 - 1][c2] - matrix[r2][c1 - 1] + matrix[r1 - 1][c1 - 1] == target)
                            ++cnt;
        return cnt;
    }
};