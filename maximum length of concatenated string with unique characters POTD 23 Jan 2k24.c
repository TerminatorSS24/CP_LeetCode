/*
You are given an array of strings arr. A string s is formed by the concatenation of a subsequence of arr that has unique characters.

Return the maximum possible length of s.

A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.



Example 1:

Input: arr = ["un","iq","ue"]
Output: 4
Explanation: All the valid concatenations are:
- ""
- "un"
- "iq"
- "ue"
- "uniq" ("un" + "iq")
- "ique" ("iq" + "ue")
Maximum length is 4.
Example 2:

Input: arr = ["cha","r","act","ers"]
Output: 6
Explanation: Possible longest valid concatenations are "chaers" ("cha" + "ers") and "acters" ("act" + "ers").
Example 3:

Input: arr = ["abcdefghijklmnopqrstuvwxyz"]
Output: 26
Explanation: The only string in arr has all 26 characters.
**********LEETCODE POTD(23/01/2024)**********
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int maxLength(char **arr, int arrSize)
{
    int *bitMaskArr = malloc(arrSize * sizeof(int));

    for (int i = 0; i < arrSize; i++)
    {
        char *string = arr[i];
        bitMaskArr[i] = 0;
        for (int j = 0; string[j]; j++)
        {
            char c = string[j];
            if (bitMaskArr[i] & 1 << (c - 'a'))
            {
                bitMaskArr[i] = 0;
                break;
            }
            bitMaskArr[i] |= 1 << (c - 'a');
        }
    }

    return maxLength_Foo(bitMaskArr, arrSize, 0);
}

int countBits(int n)
{
    int count = 0;
    while (n)
    {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

int maxLength_Foo(int *bitMaskArr, int bitMaskArrSize, int start)
{
    int res = countBits(start);
    for (int i = 0; i < bitMaskArrSize; i++)
    {
        if (start & bitMaskArr[i])
            continue;
        int new_res = maxLength_Foo(bitMaskArr + i + 1, bitMaskArrSize - i - 1, start + bitMaskArr[i]);
        if (new_res > res)
            res = new_res;
    }
    return res;
}