/*Given a string s, return the number of homogenous substrings of s. Since the answer may be too large, return it modulo 109 + 7.

A string is homogenous if all the characters of the string are the same.

A substring is a contiguous sequence of characters within a string.

 

Example 1:

Input: s = "abbcccaa"
Output: 13
Explanation: The homogenous substrings are listed as below:
"a"   appears 3 times.
"aa"  appears 1 time.
"b"   appears 2 times.
"bb"  appears 1 time.
"c"   appears 3 times.
"cc"  appears 2 times.
"ccc" appears 1 time.
3 + 1 + 2 + 1 + 3 + 2 + 1 = 13.
Example 2:

Input: s = "xy"
Output: 2
Explanation: The homogenous substrings are "x" and "y".
Example 3:

Input: s = "zzzzz"
Output: 15
**********LEETCODE POTD(09/11/2023)**********
*/
int countHomogenous(char *s)
{
    int return_count = 0;
    char comp = s[0];
    int repeatability = 0;
    for (int ptr = 0; ptr < strlen(s); ptr++)
    {
        if (comp != s[ptr])
        {
            comp = s[ptr];
            while (repeatability > 0)
            {
                return_count += repeatability--;
                return_count = return_count % 1000000007;
            }
            repeatability++;
        }
        else
            repeatability++;
    }
    while (repeatability > 0)
    {
        return_count += repeatability--;
        return_count = return_count % 1000000007;
    }
    return return_count;
}