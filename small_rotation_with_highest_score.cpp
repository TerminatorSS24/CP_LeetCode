/*You are given an array nums. You can rotate it by a non-negative integer k so that the array becomes [nums[k], nums[k + 1], ... nums[nums.length - 1], nums[0], nums[1], ..., nums[k-1]]. Afterward, any entries that are less than or equal to their index are worth one point.

For example, if we have nums = [2,4,1,3,0], and we rotate by k = 2, it becomes [1,3,0,2,4]. This is worth 3 points because 1 > 0 [no points], 3 > 1 [no points], 0 <= 2 [one point], 2 <= 3 [one point], 4 <= 4 [one point].
Return the rotation index k that corresponds to the highest score we can achieve if we rotated nums by it. If there are multiple answers, return the smallest such index k.

 

Example 1:

Input: nums = [2,3,1,4,0]
Output: 3
Explanation: Scores for each k are listed below: 
k = 0,  nums = [2,3,1,4,0],    score 2
k = 1,  nums = [3,1,4,0,2],    score 3
k = 2,  nums = [1,4,0,2,3],    score 3
k = 3,  nums = [4,0,2,3,1],    score 4
k = 4,  nums = [0,2,3,1,4],    score 3
So we should choose k = 3, which has the highest score.
Example 2:

Input: nums = [1,3,0,2,4]
Output: 0
Explanation: nums will always have 3 points no matter how it shifts.
So we will choose the smallest k, which is 0.*/
#include <iostream>
#include <vector>
#include <climits>

class Solution {
public:
    int bestRotation(std::vector<int>& nums) {
        
        std::vector<int> vk(nums.size()+3, 0);
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > i) {
                vk[i+1] += 1;
                vk[i+1 + ((nums.size()-1) - (nums[i]) + 1)] -= 1;
            } else if (nums[i] <= i) {
                vk[0] += 1;
                vk[i - nums[i] + 1] -= 1;
                vk[i+1] += 1;
                vk[nums.size()] -= 1;
            }
        }

        int maxi = INT_MIN, sum = 0, ans = -1;
        for (int i = 0; i < nums.size(); i++) {
            sum += vk[i];
            if (maxi < sum) {
                maxi = sum;
                ans = i;
            }
        }
        return ans;
    }
};

