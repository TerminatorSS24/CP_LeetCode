/*You are given an integer array nums and an integer x. In one operation, you can either remove the leftmost or the rightmost element from the array nums and subtract its value from x. Note that this modifies the array for future operations.

Return the minimum number of operations to reduce x to exactly 0 if it is possible, otherwise, return -1.

 

Example 1:

Input: nums = [1,1,4,2,3], x = 5
Output: 2
Explanation: The optimal solution is to remove the last two elements to reduce x to zero.
Example 2:

Input: nums = [5,6,7,8,9], x = 4
Output: -1
Example 3:

Input: nums = [3,2,20,1,1,3], x = 10
Output: 5
Explanation: The optimal solution is to remove the last three elements and the first two elements (5 operations in total) to reduce x to zero.
**********LEETCODE POTD(20/09/2023)**********
*/
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int start = 0, end = 0;
        int sum = accumulate(nums.begin(), nums.end(), 0) - x;
        int ans = 0;
        int tempSum = 0;
        int n = nums.size();
        bool akash = false;
        for (end; end < n; end++) {
            tempSum += nums[end];
            if (tempSum == sum) {
                akash = true;
                ans = max(ans, end - start + 1);
            } else if (tempSum > sum) {
                while (tempSum > sum && start <= end) {
                    tempSum -= nums[start];
                    start++;
                }
            }
            if (tempSum == sum) {
                akash = true;
                ans = max(ans, end - start + 1);
            }
        }
        if (ans == 0 && !akash) return -1;
        return n - ans;
    }
};