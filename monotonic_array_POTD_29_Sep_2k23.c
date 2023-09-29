/*An array is monotonic if it is either monotone increasing or monotone decreasing.

An array nums is monotone increasing if for all i <= j, nums[i] <= nums[j]. An array nums is monotone decreasing if for all i <= j, nums[i] >= nums[j].

Given an integer array nums, return true if the given array is monotonic, or false otherwise.

 

Example 1:

Input: nums = [1,2,2,3]
Output: true
Example 2:

Input: nums = [6,5,4,4]
Output: true
Example 3:

Input: nums = [1,3,2]
Output: false
**********LEETCODE POTD(29/09/2023)**********
*/
#include <stdbool.h>
bool isMonotonic(int *nums, int numsSize)
{
    int i, j;
    bool is_decreasing = false;
    bool is_increasing = false;
    if (numsSize <= 2)
        return true;
    for (i = 0, j = 1; j < numsSize; i++, j++)
    {
        if (nums[i] == nums[j])
            continue;
        if (nums[i] < nums[j])
            is_increasing = true;
        else
            is_decreasing = true;
        if ((nums[j] < nums[i]) && is_increasing)
            return false;
        if ((nums[j] > nums[i]) && is_decreasing)
            return false;
    }
    return true;
}