/*Given an array of integers nums and an integer k, return the number of contiguous subarrays where the product of all the elements in the subarray is strictly less than k.

 

Example 1:

Input: nums = [10,5,2,6], k = 100
Output: 8
Explanation: The 8 subarrays that have product less than 100 are:
[10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6]
Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.
Example 2:

Input: nums = [1,2,3], k = 0
Output: 0
**********LEETCODE POTD(27/03/2024)**********
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int numSubarrayProductLessThanK(int *nums, int numsSize, int k)
{
    int result = 0;

    for (unsigned int i = 0, j = 0, prod = 1; i < numsSize; i++)
    {
        for (prod *= nums[i]; j <= i && prod >= k; prod /= nums[j++])
            ;

        result += (i + 1) - j;
    }

    return result;
}