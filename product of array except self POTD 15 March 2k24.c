/*Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.



Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]
Example 2:

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
**********LEETCODE POTD(15/03/2024)
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int *productExceptSelf(int *nums, int numsSize, int *returnSize)
{
    int *result = (int *)malloc(numsSize * sizeof(int));
    int *left = (int *)malloc(numsSize * sizeof(int));
    int *right = (int *)malloc(numsSize * sizeof(int));

    left[0] = 1;
    for (int i = 1; i < numsSize; i++)
    {
        left[i] = left[i - 1] * nums[i - 1];
    }

    right[numsSize - 1] = 1;
    for (int i = numsSize - 2; i >= 0; i--)
    {
        right[i] = right[i + 1] * nums[i + 1];
    }

    for (int i = 0; i < numsSize; i++)
    {
        result[i] = left[i] * right[i];
    }

    *returnSize = numsSize;

    free(left);
    free(right);

    return result;
}