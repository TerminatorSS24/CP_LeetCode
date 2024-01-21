/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

Example 1:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
Example 2:

Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.
**********LEETCODE POTD(21/01/2024)**********
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}
int rob(int *nums, int numsSize)
{
    int dp[110], i;
    if (numsSize == 1)
        return nums[0];
    else if (numsSize == 2)
        return max(nums[0], nums[1]);
    dp[0] = nums[0];
    dp[1] = nums[1];
    dp[2] = nums[2] + nums[0];
    for (i = 3; i < (numsSize + 2); i++)
    {
        dp[i] = max(dp[i - 2], dp[i - 3]);
        if (i < numsSize)
            dp[i] += nums[i];
        printf("%d ", dp[i]);
    }
    return max(dp[i - 1], dp[i - 2]);
}