/*You are given a 0-indexed array nums of length n containing distinct positive integers. Return the minimum number of right shifts required to sort nums and -1 if this is not possible.

A right shift is defined as shifting the element at index i to index (i + 1) % n, for all indices.*/
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int minimumRightShifts(vector<int> &nums)
    {
        int n = nums.size();
        int ct = 0;
        for (int i = 1; i < n; i++)
        {
            if (nums[i] < nums[i - 1])
            {
                ct = i;
                break;
            }
        }
        if (ct == 0)
            return 0;
        int mx = nums[0];
        int min = nums[ct] - 1;
        for (int i = ct; i < n; i++)
        {
            if (nums[i] < mx && nums[i] > min)
                min = nums[i];
            else
                return -1;
        }
        return n - ct;
    }
};