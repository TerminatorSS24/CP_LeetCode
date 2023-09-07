/*An array is squareful if the sum of every pair of adjacent elements is a perfect square.

Given an integer array nums, return the number of permutations of nums that are squareful.

Two permutations perm1 and perm2 are different if there is some index i such that perm1[i] != perm2[i].

 

Example 1:

Input: nums = [1,17,8]
Output: 2
Explanation: [1,8,17] and [17,8,1] are the valid permutations.
Example 2:

Input: nums = [2,2,2]
Output: 1*/
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        int sqrtNum = sqrt(num);
        return sqrtNum * sqrtNum == num;
    }

    void solveForAllPossibleCombination(vector<int>& nums, int& count, int i) {
        if (i == nums.size()) {
            count++;
            return;
        }

        unordered_set<int> used;
        for (int j = i; j < nums.size(); j++) {
            if (used.find(nums[j]) != used.end()) {
                continue;
            }
            if (i == 0 || isPerfectSquare(nums[i - 1] + nums[j])) {
                swap(nums[i], nums[j]);
                solveForAllPossibleCombination(nums, count, i + 1);
                swap(nums[i], nums[j]);
            }
            used.insert(nums[j]);
        }
    }

    int numSquarefulPerms(vector<int>& nums) {
        int count = 0;
        int i = 0;
        sort(nums.begin(), nums.end());
        solveForAllPossibleCombination(nums, count, i);

        return count;
    }
};