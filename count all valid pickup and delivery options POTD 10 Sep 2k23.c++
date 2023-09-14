/*Given n orders, each order consist in pickup and delivery services. 

Count all valid pickup/delivery possible sequences such that delivery(i) is always after of pickup(i). 

Since the answer may be too large, return it modulo 10^9 + 7.

 

Example 1:

Input: n = 1
Output: 1
Explanation: Unique order (P1, D1), Delivery 1 always is after of Pickup 1.
Example 2:

Input: n = 2
Output: 6
Explanation: All possible orders: 
(P1,P2,D1,D2), (P1,P2,D2,D1), (P1,D1,P2,D2), (P2,P1,D1,D2), (P2,P1,D2,D1) and (P2,D2,P1,D1).
This is an invalid order (P1,D2,P2,D1) because Pickup 2 is after of Delivery 2.
Example 3:

Input: n = 3
Output: 90
**********LEETCODE POTD(10/09/2023)**********
*/
#include<iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int mod = 1e9 + 7;

    unsigned long int helper(int n, int p, int d, vector<vector<long long>>& dp) {
        if (p == n && d == n) return 1;
        if (dp[p][d] != -1) return dp[p][d];

        if (p > d) {
            if (p < n) {
                unsigned long int a = ((n - p) * helper(n, p + 1, d, dp)) % mod;
                unsigned long int b = ((p - d) * helper(n, p, d + 1, dp)) % mod;
                return dp[p][d] = (a + b) % mod;
            } else {
                unsigned long int a = ((p - d) * helper(n, p, d + 1, dp)) % mod;
                return dp[p][d] = a;
            }
        } else {
            unsigned long int a = ((n - p) * helper(n, p + 1, d, dp)) % mod;
            return dp[p][d] = a;
        }
    }

    int countOrders(int n) {
        vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, -1));
        return static_cast<int>(helper(n, 0, 0, dp));
    }
};
