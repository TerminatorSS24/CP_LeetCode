/*Given an integer n, return true if it is a power of two. Otherwise, return false.

An integer n is a power of two, if there exists an integer x such that n == 2x.

 

Example 1:

Input: n = 1
Output: true
Explanation: 20 = 1
Example 2:

Input: n = 16
Output: true
Explanation: 24 = 16
Example 3:

Input: n = 3
Output: false
**********LEETCODE POTD(19/02/2024)**********
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isPowerOfTwo(int n)
{
    int t;
    int lookup[32] = {
        1,
        2,
        4,
        8,
        16,
        32,
        64,
        128,
        256,
        512,
        1024,
        2048,
        4096,
        8192,
        16384,
        32768,
        65536,
        131072,
        262144,
        524288,
        1048576,
        2097152,
        4194304,
        8388608,
        16777216,
        33554432,
        67108864,
        134217728,
        268435456,
        536870912,
        1073741824};
    for (int x = 0; x < 31; x++)
        if ((n == lookup[x]) || (n == -lookup[x]))
            if ((n > 0) || ((n < 0) && (n == lookup[x])))
                return true;
    return false;
}