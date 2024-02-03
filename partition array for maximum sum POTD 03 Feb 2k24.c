/*
Given an integer array arr, partition the array into (contiguous) subarrays of length at most k. After partitioning, each subarray has their values changed to become the maximum value of that subarray.

Return the largest sum of the given array after partitioning. Test cases are generated so that the answer fits in a 32-bit integer.

 

Example 1:

Input: arr = [1,15,7,9,2,5,10], k = 3
Output: 84
Explanation: arr becomes [15,15,15,9,10,10,10]
Example 2:

Input: arr = [1,4,1,5,7,3,6,1,9,9,3], k = 4
Output: 83
Example 3:

Input: arr = [1], k = 1
Output: 1
**********LEETCODE POTD(03/02/2024)**********
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int max(int a, int b) { return a > b ? a : b; }

int maxSumAfterPartitioning(int *arr, int arrSize, int k)
{
    int *dp = (int *)malloc(sizeof(int) * (arrSize + 1));
    dp[0] = 0;
    int curr_max, curr, re = -1;
    for (int i = 1; i <= arrSize; i++)
    {
        curr_max = arr[i - 1];
        curr = arr[i - 1];
        for (int j = 1; j <= k; j++)
        {
            if (i - j < 0)
                break;
            curr_max = max(curr_max, arr[i - j]);
            curr = max(curr, dp[i - j] + j * curr_max);
        }
        dp[i] = curr;
        re = max(re, dp[i]);
    }

    return re;
}