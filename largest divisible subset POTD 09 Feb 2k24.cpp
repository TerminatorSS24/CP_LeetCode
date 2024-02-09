/*
Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:

answer[i] % answer[j] == 0, or
answer[j] % answer[i] == 0
If there are multiple solutions, return any of them.

 

Example 1:

Input: nums = [1,2,3]
Output: [1,2]
Explanation: [1,3] is also accepted.
Example 2:

Input: nums = [1,2,4,8]
Output: [1,2,4,8]
**********LEETCODE POTD(09/02/2024)**********
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> v;
        vector<int> result;
        for (int i = 0; i < nums.size(); i++)
        {
            vector<int> temp;
            for (int j = 0; j < i; j++)
                if (nums[i] % nums[j] == 0)
                    if (v[j].size() > temp.size())
                        temp = v[j];
            temp.push_back(nums[i]);
            v.push_back(temp);
            if (result.size() < temp.size())
                result = temp;
        }

        return result;
    }
};