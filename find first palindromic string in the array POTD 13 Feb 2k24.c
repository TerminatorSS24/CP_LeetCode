/*Given an array of strings words, return the first palindromic string in the array. If there is no such string, return an empty string "".

A string is palindromic if it reads the same forward and backward.



Example 1:

Input: words = ["abc","car","ada","racecar","cool"]
Output: "ada"
Explanation: The first string that is palindromic is "ada".
Note that "racecar" is also palindromic, but it is not the first.
Example 2:

Input: words = ["notapalindrome","racecar"]
Output: "racecar"
Explanation: The first and only string that is palindromic is "racecar".
Example 3:

Input: words = ["def","ghi"]
Output: ""
Explanation: There are no palindromic strings, so the empty string is returned.
**********LEETCODE POTD(13/02/2024)**********
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
void reverse(char *str)
{
    int len = strlen(str) - 1;
    char temp;
    for (int i = 0; i < len; i++)
    {
        temp = str[i];
        str[i] = str[len];
        str[len] = temp;
        len--;
    }
    return;
}

bool isPalindrome(char s[])
{
    char sReversed[1024];
    strcpy(sReversed, s);
    reverse(sReversed);
    return strcmp(s, sReversed) == 0;
}

char *firstPalindrome(char **words, int wordsSize)
{
    for (int i = 0; i < wordsSize; i++)
        if (isPalindrome(words[i]))
            return words[i];
    return "";
}