/*The width of a sequence is the difference between the maximum and minimum elements in the sequence.

Given an array of integers nums, return the sum of the widths of all the non-empty subsequences of nums. Since the answer may be very large, return it modulo 109 + 7.

A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements. For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].

 

Example 1:

Input: nums = [2,1,3]
Output: 6
Explanation: The subsequences are [1], [2], [3], [2,1], [2,3], [1,3], [2,1,3].
The corresponding widths are 0, 0, 0, 1, 1, 2, 2.
The sum of these widths is 6.
Example 2:

Input: nums = [2]
Output: 0*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    #define ll long long
    int mod = 1e9+7;
    int power(ll x, ll y) {
        int res = 1;  
        x = x % mod; 
        if (x == 0) return 0;
    
        while (y > 0) {
            if (y & 1)
                res = (res*x) % mod;
    
            y = y>>1; 
            x = (x*x) % mod;
        }
        return res;
    }
public:
    int sumSubseqWidths(vector<int>& nums) {
        ll ans = 0, n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i = 0 ; i<n ; ++i) {
            ans = (ans + nums[i]*1ll*power(2,i))%mod;
            ans = (ans - nums[i]*1ll*power(2,n-i-1))%mod;
        }
        return ans;
    }
};
