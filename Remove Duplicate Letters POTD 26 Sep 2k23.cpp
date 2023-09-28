/*Given a string s, remove duplicate letters so that every letter appears once and only once. You must make sure your result is
the smallest in lexicographical order
 among all possible results.



Example 1:

Input: s = "bcabc"
Output: "abc"
Example 2:

Input: s = "cbacdcbc"
Output: "acdb"


Constraints:

1 <= s.length <= 104
s consists of lowercase English letters.
**********LEETCODE POTD(26/09/2023)**********
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    string removeDuplicateLetters(const string &str)
    {
        int sz = str.size(), bm = 0;
        string ans;
        vector<int> ump(26);
        for (int i = 0; i < sz; ++i)
            ump[str[i] - 'a'] = i;
        for (int i = 0; i < sz; ++i)
        {
            const char &ch = str[i];
            if ((bm >> (ch - 'a')) & 1)
                continue;
            while (!ans.empty() && ans.back() > ch && ump[ans.back() - 'a'] > i)
            {
                bm ^= 1 << (ans.back() - 'a');
                ans.pop_back();
            }
            ans.push_back(ch);
            bm |= 1 << (ch - 'a');
        }
        return ans;
    }
};