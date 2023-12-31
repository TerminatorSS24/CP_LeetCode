/*You are given an array nums that consists of non-negative integers. Let us define rev(x) as the reverse of the non-negative integer x. For example, rev(123) = 321, and rev(120) = 21. A pair of indices (i, j) is nice if it satisfies all of the following conditions:

0 <= i < j < nums.length
nums[i] + rev(nums[j]) == nums[j] + rev(nums[i])
Return the number of nice pairs of indices. Since that number can be too large, return it modulo 109 + 7.



Example 1:

Input: nums = [42,11,1,97]
Output: 2
Explanation: The two pairs are:
 - (0,3) : 42 + rev(97) = 42 + 79 = 121, 97 + rev(42) = 97 + 24 = 121.
 - (1,2) : 11 + rev(1) = 11 + 1 = 12, 1 + rev(11) = 1 + 11 = 12.
Example 2:

Input: nums = [13,10,35,24,76]
Output: 4
**********LEETCODEP POTD(21/11/2023)**********
*/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    int reverse(int n)
    {
        int rev = 0;
        while (n)
        {
            rev = rev * 10 + n % 10;
            n /= 10;
        }
        return rev;
    }

    int countNicePairs(vector<int> &nums)
    {
        int mod = 1e9 + 7;
        int ans = 0;
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++)
        {
            nums[i] -= reverse(nums[i]);
            ans = (ans + mp[nums[i]]) % mod;
            mp[nums[i]]++;
        }

        return ans;
    }
};