/*
Given an integer array nums and two integers lower and upper, return the number of range sums that lie in [lower, upper] inclusive.

Range sum S(i, j) is defined as the sum of the elements in nums between indices i and j inclusive, where i <= j.

 

Example 1:

Input: nums = [-2,5,-1], lower = -2, upper = 2
Output: 3
Explanation: The three ranges are: [0,0], [2,2], and [0,2] and their respective sums are: -2, -1, 2.
Example 2:

Input: nums = [0], lower = 0, upper = 0
Output: 1
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    typedef vector<long long int> Pii;
    typedef Pii :: iterator Pit;
    int l, u;
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        
        int n = nums.size() ;
        Pii x(n + 1, 0);
        
        int res = 0;
        l = lower , u = upper;
                
        for(int i = 0; i < n ; i ++)
            x[i + 1] = x[i] + nums[i];
        
        merge(x.begin() , x.end() , res);
        return res;
    }
    
    void merge(Pit beg , Pit end , int& res){
        
        if(end - beg <= 1)
            return;
        
        auto mid = beg + (end - beg) / 2;
        
        merge(beg , mid , res);
        merge(mid , end , res);
        
        auto j = mid , k = mid;
        for(auto i = beg ; i != mid ; i++){
            
            while(j != end && *j - *i  < l)
                j++;
            while(k != end && *k - *i  <= u)
                k++;
            
            res += k - j;
            
        }
        
        inplace_merge(beg , mid, end);
        
    }
};