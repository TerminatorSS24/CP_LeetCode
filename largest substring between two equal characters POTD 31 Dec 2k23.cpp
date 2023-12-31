/*
Given a string s, return the length of the longest substring between two equal characters, excluding the two characters. If there is no such substring return -1.

A substring is a contiguous sequence of characters within a string.

 

Example 1:

Input: s = "aa"
Output: 0
Explanation: The optimal substring here is an empty substring between the two 'a's.
Example 2:

Input: s = "abca"
Output: 2
Explanation: The optimal substring here is "bc".
Example 3:

Input: s = "cbzxy"
Output: -1
Explanation: There are no characters that appear twice in s.
**********POTD (31/12/2023)**********
**********LAST DAY OF 2023, ANOTHER YEAR PASSED**********
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxLengthBetweenEqualCharacters(string s)
    {
        int ans = -1;
        for (int left = 0; left < s.size(); left++)
        {
            for (int right = left + 1; right < s.size(); right++)
            {
                if (s[left] == s[right])
                {
                    ans = max(ans, right - left - 1);
                }
            }
        }

        return ans;
    }
};