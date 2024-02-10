/*Given a string s, return the number of palindromic substrings in it.

A string is a palindrome when it reads the same backward as forward.

A substring is a contiguous sequence of characters within the string.



Example 1:

Input: s = "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
Example 2:

Input: s = "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
**********LEETCODE POTD(10/02/2024)**********
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int countSubstrings(char *s)
{
    int n = strlen(s);
    int counter = n;
    int offset;
    int i;

    for (i = 1; i < n; i++)
    {
        if (i < n && s[i - 1] == s[i])
        {
            counter++;
            offset = 1;
            while (i - offset - 1 >= 0 && i + offset < n && s[(i - 1) - offset] == s[i + offset])
            {
                counter++;
                offset++;
            }
        }
        offset = 1;
        while (0 <= i - offset && i + offset < n && s[i - offset] == s[i + offset])
        {
            counter++;
            offset++;
        }
    }
    return counter;
}