/*You are given a 0-indexed integer array nums of even length consisting of an equal number of positive and negative integers.

You should rearrange the elements of nums such that the modified array follows the given conditions:

Every consecutive pair of integers have opposite signs.
For all integers with the same sign, the order in which they were present in nums is preserved.
The rearranged array begins with a positive integer.
Return the modified array after rearranging the elements to satisfy the aforementioned conditions.



Example 1:

Input: nums = [3,1,-2,-5,2,-4]
Output: [3,-2,1,-5,2,-4]
Explanation:
The positive integers in nums are [3,1,2]. The negative integers are [-2,-5,-4].
The only possible way to rearrange them such that they satisfy all conditions is [3,-2,1,-5,2,-4].
Other ways such as [1,-2,2,-5,3,-4], [3,1,2,-2,-5,-4], [-2,3,-5,1,-4,2] are incorrect because they do not satisfy one or more conditions.
Example 2:

Input: nums = [-1,1]
Output: [1,-1]
Explanation:
1 is the only positive integer and -1 the only negative integer in nums.
So nums is rearranged to [1,-1].
**********LEETCODE POTD(15/02/2024)**********
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &nums)
    {
        vector<int> a, b, c;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
                a.push_back(nums[i]);
            else
                b.push_back(nums[i]);
        }

        int count = 0, c1 = 0, c2 = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (count % 2 == 0)
            {
                int n = a[c1++];
                c.push_back(n);
            }
            else
            {
                int n = b[c2++];
                c.push_back(n);
            }
            count++;
        }

        return c;
    }
};
