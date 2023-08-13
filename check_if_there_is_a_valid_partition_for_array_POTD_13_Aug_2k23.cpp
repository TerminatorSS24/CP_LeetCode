/*You are given a 0-indexed integer array nums. You have to partition the array into one or more contiguous subarrays.

We call a partition of the array valid if each of the obtained subarrays satisfies one of the following conditions:

The subarray consists of exactly 2 equal elements. For example, the subarray [2,2] is good.
The subarray consists of exactly 3 equal elements. For example, the subarray [4,4,4] is good.
The subarray consists of exactly 3 consecutive increasing elements, that is, the difference between adjacent elements is 1. For example, the subarray [3,4,5] is good, but the subarray [1,3,5] is not.
Return true if the array has at least one valid partition. Otherwise, return false.

 

Example 1:

Input: nums = [4,4,4,5,6]
Output: true
Explanation: The array can be partitioned into the subarrays [4,4] and [4,5,6].
This partition is valid, so we return true.
Example 2:

Input: nums = [1,1,1,2]
Output: false
Explanation: There is no valid partition for this array.
**********LEETCODE POTD(13/08/2023)**********
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int n;
    vector<int> dp;
    
    bool f(int i, vector<int>& nums) {
        if (i < 0) return true;
        if (i == 0) return false; 
        if (dp[i] != -1) return dp[i] == 1;
        bool b0 = false, b1 = false, b2 = false;
        if (i > 0 && nums[i] == nums[i - 1]) 
            b0 = f(i - 2, nums);
        if (i > 1 && nums[i] == nums[i - 1] && nums[i - 1] == nums[i - 2])
            b1 = f(i - 3, nums);
        if (i > 1 && nums[i] == nums[i - 1] + 1 && nums[i - 1] == nums[i - 2] + 1)
            b2 = f(i - 3, nums);
        return dp[i] = b0 || b1 || b2;
    }
    
    bool validPartition(vector<int>& nums) {
        n = nums.size();
        dp.assign(n, -1);
        return f(n - 1, nums);
    }
};