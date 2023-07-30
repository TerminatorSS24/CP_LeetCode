// You are given an integer array nums and an integer k. Find the maximum subarray sum of all the subarrays of nums that meet the following conditions:

// The length of the subarray is k, and
// All the elements of the subarray are distinct.
// Return the maximum subarray sum of all the subarrays that meet the conditions. If no subarray meets the conditions, return 0.

// A subarray is a contiguous non-empty sequence of elements within an array.

 

// Example 1:

// Input: nums = [1,5,4,2,9,9,9], k = 3
// Output: 15
// Explanation: The subarrays of nums with length 3 are:
// - [1,5,4] which meets the requirements and has a sum of 10.
// - [5,4,2] which meets the requirements and has a sum of 11.
// - [4,2,9] which meets the requirements and has a sum of 15.
// - [2,9,9] which does not meet the requirements because the element 9 is repeated.
// - [9,9,9] which does not meet the requirements because the element 9 is repeated.
// We return 15 because it is the maximum subarray sum of all the subarrays that meet the conditions
// Example 2:

// Input: nums = [4,4,4], k = 3
// Output: 0
// Explanation: The subarrays of nums with length 3 are:
// - [4,4,4] which does not meet the requirements because the element 4 is repeated.
// We return 0 because no subarrays meet the conditions.
#include <stdio.h>
#include <stdbool.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

long long maximumSubarraySum(int* nums, int numsSize, int k) {
    long long result = 0;

    int left = 0, right = 0;
    long long currentSum = 0;
    int seen[100001] = {0}; 

    while (right < numsSize) {
        while (right < numsSize && (right - left) < k && !seen[nums[right]]) {
            currentSum += nums[right];
            seen[nums[right]] = 1;
            right++;
        }

        if ((right - left) == k) {
            result = MAX(result, currentSum);
        }

        if (left < right) {
            if (seen[nums[left]]) {
                currentSum -= nums[left];
                seen[nums[left]] = 0;
            }
            left++;
        }
    }

    return result;
}

