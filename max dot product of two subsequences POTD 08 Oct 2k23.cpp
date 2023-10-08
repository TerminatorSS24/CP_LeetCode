/*Given two arrays nums1 and nums2.

Return the maximum dot product between non-empty subsequences of nums1 and nums2 with the same length.

A subsequence of a array is a new array which is formed from the original array by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, [2,3,5] is a subsequence of [1,2,3,4,5] while [1,5,3] is not).

 

Example 1:

Input: nums1 = [2,1,-2,5], nums2 = [3,0,-6]
Output: 18
Explanation: Take subsequence [2,-2] from nums1 and subsequence [3,-6] from nums2.
Their dot product is (2*3 + (-2)*(-6)) = 18.
Example 2:

Input: nums1 = [3,-2], nums2 = [2,-6,7]
Output: 21
Explanation: Take subsequence [3] from nums1 and subsequence [7] from nums2.
Their dot product is (3*7) = 21.
Example 3:

Input: nums1 = [-1,-1], nums2 = [1,1]
Output: -1
Explanation: Take subsequence [-1] from nums1 and subsequence [1] from nums2.
Their dot product is -1.
**********LEETCODE POTD(08/10/2023)**********
*/
// #include<bits/stdc++.h>
#include <vector>
#include <algorithm>

class Solution {
public:
    int maxDotProduct(std::vector<int>& nums1, std::vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        std::vector<std::vector<int>> dp(n, std::vector<int>(m));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(i == 0 && j == 0) {
                    dp[i][j] = nums1[i] * nums2[j];
                } else if(i == 0) {
                    dp[i][j] = std::max(dp[i][j - 1], nums1[i] * nums2[j]);
                } else if(j == 0) {
                    dp[i][j] = std::max(dp[i - 1][j], nums1[i] * nums2[j]);
                } else {
                    dp[i][j] = std::max(nums1[i] * nums2[j], dp[i - 1][j - 1] + nums1[i] * nums2[j]);
                    dp[i][j] = std::max(dp[i][j], dp[i][j - 1]);
                    dp[i][j] = std::max(dp[i][j], dp[i - 1][j]);
                }
            }
        }
        return dp[n - 1][m - 1];
    }
};
