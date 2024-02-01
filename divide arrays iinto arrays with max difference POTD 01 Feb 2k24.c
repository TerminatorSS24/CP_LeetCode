/*
You are given an integer array nums of size n and a positive integer k.

Divide the array into one or more arrays of size 3 satisfying the following conditions:

Each element of nums should be in exactly one array.
The difference between any two elements in one array is less than or equal to k.
Return a 2D array containing all the arrays. If it is impossible to satisfy the conditions, return an empty array. And if there are multiple answers, return any of them.



Example 1:

Input: nums = [1,3,4,8,7,9,3,5,1], k = 2
Output: [[1,1,3],[3,4,5],[7,8,9]]
Explanation: We can divide the array into the following arrays: [1,1,3], [3,4,5] and [7,8,9].
The difference between any two elements in each array is less than or equal to 2.
Note that the order of elements is not important.
Example 2:

Input: nums = [1,3,3,2,7,3], k = 3
Output: []
Explanation: It is not possible to divide the array satisfying all the conditions.
**********LEETCODE POTD(01/02/2024)**********
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */
int cmp(const void *a, const void *b) { return *((int *)a) - *((int *)b); }

int **divideArray(int *nums, int numsSize, int k, int *returnSize,
                  int **returnColumnSizes)
{
    int **ret = malloc((numsSize / 3) * sizeof(int *));
    (*returnColumnSizes) = malloc((numsSize / 3) * sizeof(int));
    int smallest = 0;
    *returnSize = -1;
    int idx = 0;

    qsort(nums, numsSize, sizeof(int), cmp);
    for (int i = 0; i < numsSize; i++)
    {
        if (!idx)
        {
            ret[++(*returnSize)] = malloc(3 * sizeof(int));
            (*returnColumnSizes)[(*returnSize)] = 3;
            smallest = nums[i];
        }
        else if (nums[i] - smallest > k)
        {
            *returnSize = 0;
            return ret;
        }
        ret[(*returnSize)][idx++] = nums[i];
        idx %= 3;
    }
    (*returnSize)++;
    return ret;
}