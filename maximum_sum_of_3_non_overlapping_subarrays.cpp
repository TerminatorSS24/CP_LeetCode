/*Given an integer array nums and an integer k, find three non-overlapping subarrays of length k with maximum sum and return them.

Return the result as a list of indices representing the starting position of each interval (0-indexed). If there are multiple answers, return the lexicographically smallest one.

 

Example 1:

Input: nums = [1,2,1,2,6,7,5,1], k = 2
Output: [0,3,5]
Explanation: Subarrays [1, 2], [2, 6], [7, 5] correspond to the starting indices [0, 3, 5].
We could have also taken [2, 1], but an answer of [1, 3, 5] would be lexicographically larger.
Example 2:

Input: nums = [1,2,1,2,1,2,1,2,1], k = 2
Output: [0,2,4]*/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size()-k+1;
        int subArraySum[n];
        subArraySum[0] = 0;
        for (int i = 0; i < k; i++)
            subArraySum[0] += nums[i];
        
        for (int i = 1; i < n; i++)
            subArraySum[i] = subArraySum[i-1]-nums[i-1]+nums[i+k-1];

        int leftBest[n];
        int best = 0;
        for (int i = 0; i < n; i++){
            if(subArraySum[i] > subArraySum[best])
                best = i;
            leftBest[i] = best;
        }
        int rightBest[n];
        best = n-1;
        for (int i = n-1; i >= 0; i--){
            if(subArraySum[i] >= subArraySum[best])
                best = i;
            rightBest[i] = best;
        }
    vector<int> res = {0,k,2*k};
    best = subArraySum[0] + subArraySum[k] + subArraySum[k*2];

    for(int i = k; i <= (nums.size()-(2*k)); i++){
        int actual = subArraySum[leftBest[i-k]] + subArraySum[i] + subArraySum[rightBest[i+k]]; 
        if (actual > best){
            best = actual;
            res[0] = leftBest[i-k];
            res[1] = i;
            res[2] = rightBest[i+k];
        }
    }
    return res;
    }
};