/*
Given an array of integers arr, return true if the number of occurrences of each value in the array is unique or false otherwise.

 

Example 1:

Input: arr = [1,2,2,1,1,3]
Output: true
Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the same number of occurrences.
Example 2:

Input: arr = [1,2]
Output: false
Example 3:

Input: arr = [-3,0,1,-3,1,1,1,-3,10,0]
Output: true
**********LEETCODE POTD(17/01/2024)**********
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

#define SEEN_SZ 2001
#define UQ_SZ 1001

static int16_t seen[SEEN_SZ];
static uint16_t uq[UQ_SZ];
static inline size_t seen_idx(int n)
{
    return n >= 0 ? n : n + SEEN_SZ;
}

bool uniqueOccurrences(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        int num = arr[i];
        size_t si = seen_idx(num);
        int16_t occ = ++seen[si];
        if (occ > 1)
            --uq[occ - 1];
        ++uq[occ];
    }
    bool res = true;
    for (int i = 1; i < 1001; i++)
        if (uq[i] > 1)
        {
            res = false;
            break;
        }
    for (int i = 0; i < n; i++)
    {
        int num = arr[i];
        size_t si = seen_idx(num);
        uint16_t occ = seen[si];
        seen[si] = 0;
        uq[occ] = 0;
    }
    return res;
}