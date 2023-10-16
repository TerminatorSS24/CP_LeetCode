/*Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

image: https://upload.wikimedia.org/wikipedia/commons/0/0d/PascalTriangleAnimated2.gif 

Example 1:

Input: rowIndex = 3
Output: [1,3,3,1]
Example 2:

Input: rowIndex = 0
Output: [1]
Example 3:

Input: rowIndex = 1
Output: [1,1]
**********LEETCODE POTD(16/10/2023)**********
*/
int *getRow(int rowIndex, int *returnSize)
{
    const int n = rowIndex + 1;
    int *result = (int *)calloc(n, sizeof(int));
    *returnSize = n;
    result[0] = 1;
    for (int i = 1; i < n; ++i)
    {
        for (int j = i; j >= 1; --j)
            result[j] += result[j - 1];
    }
    return result;
}