/*You are given k identical eggs and you have access to a building with n floors labeled from 1 to n.

You know that there exists a floor f where 0 <= f <= n such that any egg dropped at a floor higher than f will break, and any egg dropped at or below floor f will not break.

Each move, you may take an unbroken egg and drop it from any floor x (where 1 <= x <= n). If the egg breaks, you can no longer use it. However, if the egg does not break, you may reuse it in future moves.

Return the minimum number of moves that you need to determine with certainty what the value of f is.

 

Example 1:

Input: k = 1, n = 2
Output: 2
Explanation: 
Drop the egg from floor 1. If it breaks, we know that f = 0.
Otherwise, drop the egg from floor 2. If it breaks, we know that f = 1.
If it does not break, then we know f = 2.
Hence, we need at minimum 2 moves to determine with certainty what the value of f is.
Example 2:

Input: k = 2, n = 6
Output: 3
Example 3:

Input: k = 3, n = 14
Output: 4*/
#include <iostream>
#include <vector>
#include <climits> 

using namespace std;

class Solution {
public:
    int solve(int k, int n, vector<vector<int>> &dp){
        if(n==1 || n==0) return n;

        if(k==1) return n;

        if(dp[k][n]!=-1) return dp[k][n];

        int ans = INT_MAX, s = 1, e = n;

        while(s<=e){
            int mid = s + (e-s)/2;
            int left = solve(k-1,mid-1,dp);
            int right = solve(k,n-mid,dp);
            int temp = 1 + max(left,right);
            if(left < right)
                s = mid + 1;
            else
                e = mid - 1;
            ans = min(ans,temp);
        }
        return dp[k][n] = ans;
    }

    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(k+1, vector<int>(n+1, -1));
        return solve(k, n, dp);
    }
};
