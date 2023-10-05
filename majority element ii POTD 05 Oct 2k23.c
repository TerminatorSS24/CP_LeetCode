/*Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

 

Example 1:

Input: nums = [3,2,3]
Output: [3]
Example 2:

Input: nums = [1]
Output: [1]
Example 3:

Input: nums = [1,2]
Output: [1,2]
**********LEETCODE POTD(05/10/2023)**********
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int cmpfunc(const void *a, const void *b)
{
    return (*(int*)a - *(int*)b);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* majorityElement(int* nums, int numsSize, int* returnSize){

    bool elNotInserted = false;
    int count = 0;
    int idx = 0;

    qsort(nums, numsSize, sizeof(int), cmpfunc);

    int *array = (int*)malloc(sizeof(int) * 50000);

    for (int index = 0; index < numsSize; index++)
    {
        if (index + 1 < numsSize && nums[index] == nums[index+1])
        {
            count++;

            if (numsSize >= 3 && count >= (numsSize/3) && !elNotInserted)
            {
                array[idx] = nums[index];
                elNotInserted = true;
                idx++;
            }
        }
        else
        {
            if (numsSize < 3)
            {
                array[idx] = nums[index];
                idx++;
            }
            else
            {
                elNotInserted = false;
                count = 0;
            }
        }
    }

    *returnSize = idx;
    return array;
}