/*Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]
**********LEETCODE POTD(09/10/2023)**********
*/
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> v;
        int m = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == target)
                m++;
        }
        if (m == 0)
        {
            v.push_back(-1);
            v.push_back(-1);
        }
        else
        {
            for (int i = 0; i < nums.size(); i++)
            {
                if (nums[i] == target)
                {
                    v.push_back(i);
                    break;
                }
            }
            v.push_back(v[0] + m - 1);
        }
        return v;
    }
};