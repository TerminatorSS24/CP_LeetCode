/*The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle values.

For examples, if arr = [2,3,4], the median is 3.
For examples, if arr = [1,2,3,4], the median is (2 + 3) / 2 = 2.5.
You are given an integer array nums and an integer k. There is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the median array for each window in the original array. Answers within 10-5 of the actual value will be accepted.

 

Example 1:

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [1.00000,-1.00000,-1.00000,3.00000,5.00000,6.00000]
Explanation: 
Window position                Median
---------------                -----
[1  3  -1] -3  5  3  6  7        1
 1 [3  -1  -3] 5  3  6  7       -1
 1  3 [-1  -3  5] 3  6  7       -1
 1  3  -1 [-3  5  3] 6  7        3
 1  3  -1  -3 [5  3  6] 7        5
 1  3  -1  -3  5 [3  6  7]       6
Example 2:

Input: nums = [1,2,3,4,2,3,1,4,2], k = 3
Output: [2.00000,3.00000,3.00000,3.00000,2.00000,3.00000,2.00000]*/
#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    int b;
    double picaro;
    multiset<long long> halfmin, halfmax;
    vector<double> ans;

    void huy(int v) {
        b = 0;
        if (halfmin.size() == halfmax.size()) {
            b = 1;
            if (v > *halfmax.begin()) halfmax.insert(v);
            else halfmin.insert(v);
        }
        if (halfmin.size() > halfmax.size() && b == 0) {
            if (v >= *halfmin.rbegin()) halfmax.insert(v);
            if (v < *halfmin.rbegin()) {
                int huy = *halfmin.rbegin();
                halfmin.erase(halfmin.find(huy));
                halfmax.insert(huy);
                halfmin.insert(v);
            }
        }
        if (halfmin.size() < halfmax.size() && b == 0) {
            if (v <= *halfmax.begin()) halfmin.insert(v);
            if (v > *halfmax.begin()) {
                int huy = *halfmax.begin();
                halfmax.erase(halfmax.find(huy));
                halfmin.insert(huy);
                halfmax.insert(v);
            }
        }
    }

    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        if (nums.size() == 1) {
            ans.push_back(nums[0]);
            return ans;
        }
        if (k == 1) {
            for (int i = 0; i <= nums.size() - 1; i++) ans.push_back(nums[i]);
            return ans;
        }
        if (k == 2) {
            for (int i = 1; i <= nums.size() - 1; i++) {
                long long g = long(nums[i]) + long(nums[i - 1]);
                ans.push_back(double(g) / 2);
            }
            return ans;
        }
        for (int i = 0; i <= nums.size() - 1; i++) {
            if (i <= k - 1) {
                if (i == 0) halfmin.insert(nums[i]);
                if (i == 1) {
                    halfmax.insert(nums[i]);
                    if (*halfmax.begin() < *halfmin.rbegin())
                        halfmax.swap(halfmin);
                }
                if (i > 1) {
                    huy(nums[i]);
                }
                if (i == k - 1) {
                    if (k % 2 == 0) {
                        picaro = double(double(*halfmin.rbegin()) + double(*halfmax.begin())) / 2;
                        ans.push_back(picaro);
                    }
                    if (k % 2 == 1) {
                        if (halfmin.size() > halfmax.size())
                            ans.push_back(*halfmin.rbegin());
                        if (halfmin.size() < halfmax.size())
                            ans.push_back(*halfmax.begin());
                    }
                }
            } else {
                if (halfmin.count(nums[i - k]) == 0 && halfmax.count(nums[i - k]) != 0)
                    halfmax.erase(halfmax.find(nums[i - k]));
                if (halfmin.count(nums[i - k]) != 0)
                    halfmin.erase(halfmin.find(nums[i - k]));
                huy(nums[i]);
                if (k % 2 == 0) {
                    picaro = double(double(*halfmin.rbegin()) + double(*halfmax.begin())) / 2;
                    ans.push_back(picaro);
                }
                if (k % 2 == 1) {
                    if (halfmin.size() > halfmax.size())
                        ans.push_back(*halfmin.rbegin());
                    if (halfmin.size() < halfmax.size())
                        ans.push_back(*halfmax.begin());
                }
            }
        }
        return ans;
    }
};
