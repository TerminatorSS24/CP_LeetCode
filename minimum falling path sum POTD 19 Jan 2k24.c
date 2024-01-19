/*
Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

 

Example 1:

image: https://assets.leetcode.com/uploads/2021/11/03/failing1-grid.jpg

Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
Output: 13
Explanation: There are two falling paths with a minimum sum as shown.
Example 2:

image: https://assets.leetcode.com/uploads/2021/11/03/failing2-grid.jpg

Input: matrix = [[-19,57],[-40,-5]]
Output: -59
Explanation: The falling path with a minimum sum is shown.
**********LEETCODE POTD(19/01/2024)**********
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int min(int a, int b)
{
    return a < b ? a : b;
}

int minFallingPathSum(int **matrix, int matrixSize, int *matrixColSize)
{
    for (int i = matrixSize - 2; i >= 0; i--)
        for (int j = 0; j < *matrixColSize; ++j)
        {
            int count = matrix[i + 1][j];
            if (j > 0)
                count = min(count, matrix[i + 1][j - 1]);
            if (j < *matrixColSize - 1)
                count = min(count, matrix[i + 1][j + 1]);
            matrix[i][j] += count;
        }

    int result = matrix[0][0];
    for (int j = 1; j < *matrixColSize; ++j)
        result = min(result, matrix[0][j]);

    return result;
}