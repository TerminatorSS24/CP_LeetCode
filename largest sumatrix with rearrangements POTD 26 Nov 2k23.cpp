/*ou are given a binary matrix matrix of size m x n, and you are allowed to rearrange the columns of the matrix in any order.

Return the area of the largest submatrix within matrix where every element of the submatrix is 1 after reordering the columns optimally.

 

Example 1:

image: https://assets.leetcode.com/uploads/2020/12/29/screenshot-2020-12-30-at-40536-pm.png

Input: matrix = [[0,0,1],[1,1,1],[1,0,1]]
Output: 4
Explanation: You can rearrange the columns as shown above.
The largest submatrix of 1s, in bold, has an area of 4.
Example 2:

image: https://assets.leetcode.com/uploads/2020/12/29/screenshot-2020-12-30-at-40852-pm.png

Input: matrix = [[1,0,1,0,1]]
Output: 3
Explanation: You can rearrange the columns as shown above.
The largest submatrix of 1s, in bold, has an area of 3.
Example 3:

Input: matrix = [[1,1,0],[1,0,1]]
Output: 2
Explanation: Notice that you must rearrange entire columns, and there is no way to make a submatrix of 1s larger than an area of 2.*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution
{
public:
    int largestSubmatrix(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] != 0)
                    matrix[i][j] += matrix[i - 1][j];
            }
        }
        int maxarea = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            sort(matrix[i].begin(), matrix[i].end(), greater<int>());
            int temp = INT_MAX;
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == 0)
                    continue;
                temp = min(temp, matrix[i][j]);
                int area = (j + 1) * temp;
                maxarea = max(maxarea, area);
            }
        }
        if (maxarea == INT_MIN)
            return 0;
        return maxarea;
    }
};