/*You are given an array of integers nums (0-indexed) and an integer k.

The score of a subarray (i, j) is defined as min(nums[i], nums[i+1], ..., nums[j]) * (j - i + 1). A good subarray is a subarray where i <= k <= j.

Return the maximum possible score of a good subarray.

 

Example 1:

Input: nums = [1,4,3,7,4,5], k = 3
Output: 15
Explanation: The optimal subarray is (1, 5) with a score of min(4,3,7,4,5) * (5-1+1) = 3 * 5 = 15. 
Example 2:

Input: nums = [5,5,4,5,4,1,1,1], k = 0
Output: 20
Explanation: The optimal subarray is (0, 4) with a score of min(5,5,4,5,4) * (4-0+1) = 4 * 5 = 20.
 
**********LEETCODE POTD(22/10/2023)********** 
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maximumScore(vector<int> &nums, int k)
    {
        int ans1 = 0, ans2 = 0;
        int n = nums.size();
        int *left = new int[k];
        int *right = new int[n - k];
        if (k > 0)
            left[k - 1] = nums[k - 1];
        for (int i = k - 2; i >= 0; i--)
            left[i] = min(nums[i], left[i + 1]);
        right[0] = nums[k];
        for (int i = 1; i < n - k; i++)
            right[i] = min(nums[k + i], right[i - 1]);
        int i = 0;
        int j = k - 1;
        int temp;
        while (i < n - k)
        {
            int mini = right[i];
            temp = right[i];
            while (j >= 0 && mini <= left[j])
                j--;
            temp *= (k - j + i);
            ans1 = max(ans1, temp);
            i++;
        }
        delete[] left, right;
        int *left1 = new int[k + 1];
        int *right1 = new int[n - k - 1];

        left1[k] = nums[k];

        for (int i = k - 1; i >= 0; i--)
        {
            left1[i] = min(nums[i], left1[i + 1]);
        }
        if (k + 1 < n)
            right1[0] = nums[k + 1];
        for (int i = 1; i < n - k - 1; i++)
        {
            right1[i] = min(nums[k + 1 + i], right1[i - 1]);
        }
        i = 0;
        j = k;
        while (j >= 0)
        {
            int mini = left1[j];
            temp = left1[j];
            while (i < n - k - 1 && mini <= right1[i])
                i++;
            temp *= (k + 1 - j + i);
            ans2 = max(ans2, temp);
            j--;
        }
        delete[] left1, right1;
        return max(ans1, ans2);
    }
};