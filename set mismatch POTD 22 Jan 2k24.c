/*
You have a set of integers s, which originally contains all the numbers from 1 to n. Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set, which results in repetition of one number and loss of another number.

You are given an integer array nums representing the data status of this set after the error.

Find the number that occurs twice and the number that is missing and return them in the form of an array.

 

Example 1:

Input: nums = [1,2,2,4]
Output: [2,3]
Example 2:

Input: nums = [1,1]
Output: [1,2]
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *findErrorNums(int *nums, int numsSize, int *returnSize)
{
    int n = numsSize;
    for (int i = 0; i < n; i++)
    {
        while (nums[i] != nums[nums[i] - 1])
        {
            int temp = nums[nums[i] - 1];
            nums[nums[i] - 1] = nums[i];
            nums[i] = temp;
        }
    }

    int duplicate;
    int missing;
    for (int j = 0; j < n; j++)
    {
        if (j + 1 != nums[j])
        {
            duplicate = nums[j];
            missing = j + 1;
        }
    }
    *returnSize = 2;
    int *result = (int *)malloc(2 * sizeof(int));
    result[0] = duplicate;
    result[1] = missing;

    return result;
}