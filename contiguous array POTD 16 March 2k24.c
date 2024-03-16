/*Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.



Example 1:

Input: nums = [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.
Example 2:

Input: nums = [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
**********LEETCODE POTD(16/03/2024)**********
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include<string.h>

int findMaxLength(int *nums, int numsSize)
{
    int result = 0, sum = 0, temp, map[numsSize * 2 + 1], i;
    memset(map, 0xFF, (numsSize * 2 + 1) * sizeof(int));
    map[numsSize] = 0;

    for (int i = 0, sum = 0; i < numsSize; i++)
    {
        sum += (nums[i] ? 1 : -1);
        temp = 0;

        if (map[sum + numsSize] != -1)
            temp = (i + 1) - map[sum + numsSize];
        else
            map[sum + numsSize] = i + 1;

        result = result >= temp ? result : temp;
    }

    return result;
}