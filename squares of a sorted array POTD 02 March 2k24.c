/*Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.



Example 1:

Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].
Example 2:

Input: nums = [-7,-3,2,3,11]
Output: [4,9,9,49,121]
**********LEETCODE POTD(02/03/2024)**********
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *sortedSquares(int *nums, int numsSize, int *returnSize)
{
    int *arr = (int *)malloc(sizeof(int) * numsSize);
    *returnSize = numsSize;
    int l = 0, r = numsSize - 1;
    for (int k = r; k >= 0; k--)
    {
        if (abs(nums[r] > abs(nums[l])))
            arr[k] = nums[r] * nums[r--];
        else
            arr[k] = nums[l] * nums[l++];
    }
    return arr;
}