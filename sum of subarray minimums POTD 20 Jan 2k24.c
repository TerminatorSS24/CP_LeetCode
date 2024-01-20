/*
Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. Since the answer may be large, return the answer modulo 109 + 7.

 

Example 1:

Input: arr = [3,1,2,4]
Output: 17
Explanation: 
Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
Sum is 17.
Example 2:

Input: arr = [11,81,94,43,3]
Output: 444
**********LEETCODE POTD(20/01/2024)**********
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int sumSubarrayMins(int *arr, int arrSize)
{
    const int MOD = 1000000007;
    int stack[arrSize];
    int top = -1;
    long long result = 0;

    for (int i = 0; i <= arrSize; ++i)
    {
        while (top != -1 && (i == arrSize || arr[i] < arr[stack[top]]))
        {
            int j = stack[top--];
            int prev = (top == -1) ? -1 : stack[top];
            result += (long long)(i - j) * (j - prev) * arr[j];
            result %= MOD;
        }

        if (i < arrSize)
            stack[++top] = i;
    }

    return (int)result;
}