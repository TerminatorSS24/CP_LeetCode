/*Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.



Example 1:

Input: nums = [3,0,1]
Output: 2
Explanation: n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number in the range since it does not appear in nums.
Example 2:

Input: nums = [0,1]
Output: 2
Explanation: n = 2 since there are 2 numbers, so all numbers are in the range [0,2]. 2 is the missing number in the range since it does not appear in nums.
Example 3:

Input: nums = [9,6,4,2,3,5,7,0,1]
Output: 8
Explanation: n = 9 since there are 9 numbers, so all numbers are in the range [0,9]. 8 is the missing number in the range since it does not appear in nums.
**********LEETCODE POTD(20/02/2024)**********
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int missingNumber(int *nums, int numsSize)
{

    for (int i = 0; i < numsSize; i++)
    {
        int j = 0;
        while (nums[j] != i)
        {
            if (j == numsSize - 1)
                return i;
            if (j + 1 <= numsSize - 1)
                j++;
        }
        if (i == numsSize - 1)
            return i + 1;
    }

    return 0;
}