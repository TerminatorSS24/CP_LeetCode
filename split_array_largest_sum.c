/*
Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.

Return the minimized largest sum of the split.

A subarray is a contiguous part of the array.

 

Example 1:

Input: nums = [7,2,5,10,8], k = 2
Output: 18
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8], where the largest sum among the two subarrays is only 18.
Example 2:

Input: nums = [1,2,3,4,5], k = 2
Output: 9
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [1,2,3] and [4,5], where the largest sum among the two subarrays is only 9.
*/
#include <stdio.h>
#include <limits.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int canSplit(int* nums, int numsSize, int k, long long sum) {
    int count = 1;
    long long currentSum = 0;
    
    for (int i = 0; i < numsSize; i++) {
        if (currentSum + nums[i] > sum) {
            count++;
            currentSum = nums[i];
        } else {
            currentSum += nums[i];
        }
    }
    
    return count <= k;
}

int splitArray(int* nums, int numsSize, int k) {
    long long left = 0, right = 0;
    
    for (int i = 0; i < numsSize; i++) {
        left = max(left, nums[i]);
        right += nums[i];
    }
    
    long long result = right;
    
    while (left <= right) {
        long long mid = left + (right - left) / 2;
        
        if (canSplit(nums, numsSize, k, mid)) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    return (int)result;
}

