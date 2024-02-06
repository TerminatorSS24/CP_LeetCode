/*
Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.

 

Example 1:

Input: s = "leetcode"
Output: 0
Example 2:

Input: s = "loveleetcode"
Output: 2
Example 3:

Input: s = "aabb"
Output: -1
**********LEETCODE POTD(06/02/2024)**********
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int firstUniqChar(char *s)
{

    long map[256] = {0};
    long size = strlen(s);

    for (int i = 0; i < size; i++)
        map[s[i]] += 1;

    for (int i = 0; i < size; i++)
        if (map[s[i]] == 1)
            return i;
    return -1;
}