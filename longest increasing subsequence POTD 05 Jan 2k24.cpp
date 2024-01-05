/*Given an integer array nums, return the length of the longest strictly increasing SUBSEQUENCE[A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.]
 

Example 1:

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
Example 2:

Input: nums = [0,1,0,3,2,3]
Output: 4
Example 3:

Input: nums = [7,7,7,7,7,7,7]
Output: 1
**********LEETCODE POTD(05/01/2024)**********
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> ret{};
        for(size_t i = 0; i < nums.size(); ++i)
        {
            auto it = lower_bound(ret.begin(), ret.end(), nums[i]);
            if(it == ret.end())
                ret.push_back(nums[i]);
            else
                *it = nums[i];
        }
        return ret.size();
    }
};