/*Given an integer array nums and an integer k, return the length of the shortest non-empty subarray of nums with a sum of at least k. If there is no such subarray, return -1.

A subarray is a contiguous part of an array.

 

Example 1:

Input: nums = [1], k = 1
Output: 1
Example 2:

Input: nums = [1,2], k = 4
Output: -1
Example 3:

Input: nums = [2,-1,2], k = 3
Output: 3*/
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        deque<pair<long long, long long>> dq;
        long long sum = 0;
        long long shortest = INT_MAX;

        for (long long i = 0; i < n; ++i) {
            sum += nums[i];
            if (sum >= k) shortest = min(shortest, i + 1);
            pair<long long, long long> curr = {INT_MIN, INT_MIN};
            while (!dq.empty() and (sum - dq.front().second >= k)) {
                curr = dq.front();
                dq.pop_front();
            }
            if (curr.second != INT_MIN)
                shortest = min(shortest, (i - curr.first));

            while (!dq.empty() and sum <= dq.back().second)
                dq.pop_back();
            dq.push_back({i, sum});
        }
        return shortest == INT_MAX ? -1 : shortest;
    }
};
