/*Given two integers left and right that represent the range [left, right], return the bitwise AND of all numbers in this range, inclusive.



Example 1:

Input: left = 5, right = 7
Output: 4
Example 2:

Input: left = 0, right = 0
Output: 0
Example 3:

Input: left = 1, right = 2147483647
Output: 0
**********LEETCODE POTD(21/02/2024)**********
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int rangeBitwiseAnd(int left, int right)
{
    int temp = left;
    if (left <= 2147483646)
    {
        for (int i = left; i <= right; i++)
        {
            if (i == 2147483646)
                break;
            if ((temp & i) == 0)
                return 0;
            else
                temp &= i;
        }
        return temp;
    }
    else
        return left;
    return 0;
}