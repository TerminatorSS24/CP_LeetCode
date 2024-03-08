/*You are given an array nums consisting of positive integers.

Return the total frequencies of elements in nums such that those elements all have the maximum frequency.

The frequency of an element is the number of occurrences of that element in the array.



Example 1:

Input: nums = [1,2,2,3,1,4]
Output: 4
Explanation: The elements 1 and 2 have a frequency of 2 which is the maximum frequency in the array.
So the number of elements in the array with maximum frequency is 4.
Example 2:

Input: nums = [1,2,3,4,5]
Output: 5
Explanation: All elements of the array have a frequency of 1 which is the maximum.
So the number of elements in the array with maximum frequency is 5.
**********LEETCODE POTD(08/03/2024)**********
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int maxFrequencyElements(int *nums, int numsSize)
{
    int i, max, total_occurance = 0;
    int occurance[101] = {0};
    max = nums[0];
    for (i = 0; i < numsSize; i++)
    {
        occurance[nums[i]]++;
        if (nums[i] > max)
            max = nums[i];
    }
    int temp = max;
    max = occurance[1];
    for (i = 2; i <= temp; i++)
        if (occurance[i] > max)
            max = occurance[i];
    for (i = 1; i <= temp; i++)
        if (occurance[i] == max)
            total_occurance += max;
    return total_occurance;
}