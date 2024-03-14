/*Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.

A subarray is a contiguous part of the array.



Example 1:

Input: nums = [1,0,1,0,1], goal = 2
Output: 4
Explanation: The 4 subarrays are bolded and underlined below:
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
Example 2:

Input: nums = [0,0,0,0,0], goal = 0
Output: 15
**********LEETCODE POTD(14/03/2024)**********
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int numSubarraysWithSum(int *nums, int numsSize, int goal)
{
    int ans = 0, *freq = (int *)calloc(1, sizeof(int) * (numsSize + 1));

    for (int i = 0, sum = 0; i < numsSize; i++)
    {

        sum += nums[i];

        if (sum == goal)
        {
            ans++;
        }

        if (sum >= goal)
        {
            ans += freq[sum - goal];
        }

        freq[sum]++;
    }

    free(freq);

    return ans;
}