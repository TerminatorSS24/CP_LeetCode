/*Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).



Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
**********LEETCODE POTD(21/09/2023)**********
*/
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        double sum = 0;
        vector<int> nums;
        int i = 0;
        int j = 0;
        while (i < nums1.size() || j < nums2.size())
        {
            if (j == nums2.size())
            {
                nums.push_back(nums1[i]);
                i++;
            }
            else if (i == nums1.size())
            {
                nums.push_back(nums2[j]);
                j++;
            }
            else if (nums1[i] <= nums2[j])
            {
                nums.push_back(nums1[i]);
                i++;
            }
            else
            {
                nums.push_back(nums2[j]);
                j++;
            }
        }

        if (nums.size() % 2 == 1)
        {
            return (double)((double)nums[nums.size() / 2.0]);
        }
        return (double)((double)(nums[(nums.size() / 2) - 1] + nums[nums.size() / 2]) / 2.0);
    }
};