/*Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.



Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2
**********LEETCODE POTD(12/02/2024)*********
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int majorityElement(int *nums, int numsSize)
{
    int candidate = nums[0];
    int count = 1;

    for (int i = 1; i < numsSize; i++)
    {
        if (nums[i] == candidate)
            count++;
        else
        {
            count--;
            if (count == 0)
            {
                candidate = nums[i];
                count = 1;
            }
        }
    }

    return candidate;
}
