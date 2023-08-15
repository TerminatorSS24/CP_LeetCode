/*You are given an integer array nums.

You should move each element of nums into one of the two arrays A and B such that A and B are non-empty, and average(A) == average(B).

Return true if it is possible to achieve that and false otherwise.

Note that for an array arr, average(arr) is the sum of all the elements of arr over the length of arr.

 

Example 1:

Input: nums = [1,2,3,4,5,6,7,8]
Output: true
Explanation: We can split the array into [1,4,5,8] and [2,3,6,7], and both of them have an average of 4.5.
Example 2:

Input: nums = [3,1]
Output: false*/
#include <iostream>
#include <vector>
#include <numeric>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool splitArraySameAverage(vector<int>& nums) {
        int n = nums.size();
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        vector<int> left(nums.begin(), nums.begin()+n/2);
        vector<int> right(nums.begin()+n/2, nums.end());

        vector<vector<int>> leftSums(left.size()+1);

        for(int bitmask=0; bitmask<(1<<left.size()); bitmask++) {
            int setbits = __builtin_popcount(bitmask);
            int sum = 0;

            for(int i=0; i<left.size(); i++) {
                if(bitmask & (1<<i)) sum += left[i];
            }

            leftSums[setbits].push_back(sum);
        }

        vector<unordered_set<int>> rightSums(right.size()+1);

        for(int bitmask=0; bitmask<(1<<right.size()); bitmask++) {
            int setbits = __builtin_popcount(bitmask);
            int sum = 0;

            for(int i=0; i<right.size(); i++) {
                if(bitmask & (1<<i)) sum += right[i];
            }

            rightSums[setbits].insert(n * sum);
        }

        for(int i=0; i<=left.size(); i++) {
            for(int sum : leftSums[i]) {
                for(int l=max(i, 1); l<i+right.size(); l++) {
                    int leftlen = i;
                    int rightlen = l - i;

                    if(rightSums[rightlen].count((totalSum * l) - (n * sum))) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};

