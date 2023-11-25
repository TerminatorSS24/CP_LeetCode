/*You are given an integer array nums sorted in non-decreasing order.

Build and return an integer array result with the same length as nums such that result[i] is equal to the summation of absolute differences between nums[i] and all the other elements in the array.

In other words, result[i] is equal to sum(|nums[i]-nums[j]|) where 0 <= j < nums.length and j != i (0-indexed).



Example 1:

Input: nums = [2,3,5]
Output: [4,3,5]
Explanation: Assuming the arrays are 0-indexed, then
result[0] = |2-2| + |2-3| + |2-5| = 0 + 1 + 3 = 4,
result[1] = |3-2| + |3-3| + |3-5| = 1 + 0 + 2 = 3,
result[2] = |5-2| + |5-3| + |5-5| = 3 + 2 + 0 = 5.
Example 2:

Input: nums = [1,4,6,8,10]
Output: [24,15,13,15,21]
**********LEETCODE POTD(25/11/2023)**********
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> getSumAbsoluteDifferences(vector<int> &nums)
    {
        vector<int> sum;
        int pre = 0;
        for (int i : nums)
        {
            pre += i;
            sum.push_back(pre);
        }
        vector<int> ans;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int part1 = (nums[i] * (i + 1)) - sum[i];
            int part2 = (sum[n - 1] - sum[i]) - (nums[i] * (n - 1 - i));
            ans.push_back(part1 + part2);
        }
        return ans;
    }
};