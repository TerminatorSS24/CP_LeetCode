/*You are given a binary string s that contains at least one '1'.

You have to rearrange the bits in such a way that the resulting binary number is the maximum odd binary number that can be created from this combination.

Return a string representing the maximum odd binary number that can be created from the given combination.

Note that the resulting string can have leading zeros.



Example 1:

Input: s = "010"
Output: "001"
Explanation: Because there is just one '1', it must be in the last position. So the answer is "001".
Example 2:

Input: s = "0101"
Output: "1001"
Explanation: One of the '1's must be in the last position. The maximum number that can be made with the remaining digits is "100". So the answer is "1001".
**********LEETCODE POTD(01/03/2024)**********
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char *maximumOddBinaryNumber(char *s)
{

    int i, len = strlen(s), count_one = 0;
    for (i = 0; i < len; i++)
    {
        if (s[i] == '1')
        {
            count_one++;
            s[i] = '0';
        }
    }
    if (count_one > 0)
    {
        s[len - 1] = '1';
        count_one--;
        for (i = 0; i < count_one; i++)
            s[i] = '1';
    }
    return s;
}