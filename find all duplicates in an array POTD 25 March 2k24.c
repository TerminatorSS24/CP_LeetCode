/*Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears once or twice, return an array of all the integers that appears twice.

You must write an algorithm that runs in O(n) time and uses only constant extra space.



Example 1:

Input: nums = [4,3,2,7,8,2,3,1]
Output: [2,3]
Example 2:

Input: nums = [1,1,2]
Output: [1]
Example 3:

Input: nums = [1]
Output: []
**********LEETCODE POTD(25/03/2024)**********
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int *findDuplicates(int *nums, int numsSize, int *returnSize)
{
    int *result = malloc(sizeof(int) * numsSize);
    *returnSize = 0;

    for (int i = 0; i < numsSize; ++i)
    {
        int index = abs(nums[i]) - 1;

        if (nums[index] < 0)
            result[(*returnSize)++] = abs(nums[i]);
        else
            nums[index] = -nums[index];
    }

    for (int i = 0; i < numsSize; ++i)
    {
        if (nums[i] < 0)
            nums[i] = -nums[i];
    }

    result = (int *)realloc(result, sizeof(int) * (*returnSize));

    return result;
}