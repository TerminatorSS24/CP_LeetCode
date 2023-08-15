/*You are given two integer arrays of the same length nums1 and nums2. In one operation, you are allowed to swap nums1[i] with nums2[i].

For example, if nums1 = [1,2,3,8], and nums2 = [5,6,7,4], you can swap the element at i = 3 to obtain nums1 = [1,2,3,4] and nums2 = [5,6,7,8].
Return the minimum number of needed operations to make nums1 and nums2 strictly increasing. The test cases are generated so that the given input always makes it possible.

An array arr is strictly increasing if and only if arr[0] < arr[1] < arr[2] < ... < arr[arr.length - 1].

 

Example 1:

Input: nums1 = [1,3,5,4], nums2 = [1,2,3,7]
Output: 1
Explanation: 
Swap nums1[3] and nums2[3]. Then the sequences are:
nums1 = [1, 3, 5, 7] and nums2 = [1, 2, 3, 4]
which are both strictly increasing.
Example 2:

Input: nums1 = [0,3,5,8,9], nums2 = [2,1,4,6,9]
Output: 1*/
#include <iostream>
#include <vector>
#include <cstring> // For memset

class Solution {
public:
   int dp[100001][2];
   
   int helper(std::vector<int>& nums1, std::vector<int>& nums2, int i, int swp) {
       if (i == nums1.size()) return 0;
       if (dp[i][swp] != -1) return dp[i][swp];
       
       int prev1 = 0;
       int prev2 = 0;
       if (swp) {
           prev1 = nums2[i - 1];
           prev2 = nums1[i - 1];
       } else {
           prev1 = nums1[i - 1];
           prev2 = nums2[i - 1];
       }
       
       int ans = 1e6;
       if (nums1[i] > prev1 && nums2[i] > prev2) {
           ans = std::min(ans, helper(nums1, nums2, i + 1, 0));
       }

       if (nums1[i] > prev2 && nums2[i] > prev1) {
           ans = std::min(ans, helper(nums1, nums2, i + 1, 1) + 1);
       }

       return dp[i][swp] = ans;
   }
   
   int minSwap(std::vector<int>& nums1, std::vector<int>& nums2) {
       std::memset(dp, -1, sizeof(dp));
       nums1.insert(nums1.begin(), -1);
       nums2.insert(nums2.begin(), -1);
       return helper(nums1, nums2, 1, 0);
   }
};