/*Given an integer array nums and an integer k, return the maximum sum of a non-empty subsequence of that array such that for every two consecutive integers in the subsequence, nums[i] and nums[j], where i < j, the condition j - i <= k is satisfied.

A subsequence of an array is obtained by deleting some number of elements (can be zero) from the array, leaving the remaining elements in their original order.

 

Example 1:

Input: nums = [10,2,-10,5,20], k = 2
Output: 37
Explanation: The subsequence is [10, 2, 5, 20].
Example 2:

Input: nums = [-1,-2,-3], k = 1
Output: -1
Explanation: The subsequence must be non-empty, so we choose the largest number.
Example 3:

Input: nums = [10,-2,-10,-5,20], k = 2
Output: 23
Explanation: The subsequence is [10, -2, -5, 20].
**********LEETCODE POTD(21/10/2023)**********
*/
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        deque<int> q;
        int ans = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            if (q.size() > 0) {
                int t = max(nums[i], nums[q.front()] + nums[i]);
                nums[i] = t;
                ans = max(ans, t);
                while (q.size() && nums[q.back()] <= t) {
                    q.pop_back();
                }
                q.push_back(i);
            } else {
                q.push_back(i);
                ans = max(ans, nums[i]);
            }
            if (i - q.front() >= k) {
                q.pop_front();
            }
        }
        return ans;
    }
};