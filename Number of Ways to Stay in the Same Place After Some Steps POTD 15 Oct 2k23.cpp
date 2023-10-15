/*You have a pointer at index 0 in an array of size arrLen. At each step, you can move 1 position to the left, 1 position to the right in the array, or stay in the same place (The pointer should not be placed outside the array at any time).

Given two integers steps and arrLen, return the number of ways such that your pointer is still at index 0 after exactly steps steps. Since the answer may be too large, return it modulo 109 + 7.

 

Example 1:

Input: steps = 3, arrLen = 2
Output: 4
Explanation: There are 4 differents ways to stay at index 0 after 3 steps.
Right, Left, Stay
Stay, Right, Left
Right, Stay, Left
Stay, Stay, Stay
Example 2:

Input: steps = 2, arrLen = 4
Output: 2
Explanation: There are 2 differents ways to stay at index 0 after 2 steps
Right, Left
Stay, Stay
Example 3:

Input: steps = 4, arrLen = 2
Output: 8
**********LEETCODE POTD(15/10/2023)**********
*/
#include <iostream>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    unordered_map<int, unordered_map<int, int>> dp;
    const int mod = 1e9 + 7;

    int solve(int steps, int idx, int &n)
    {
        if (idx < 0 || idx >= n || steps < 0 || idx > steps)
            return 0;
        if (steps == 0)
            return idx == 0;
        if (dp[steps].find(idx) != dp[steps].end())
            return dp[steps][idx];
        int ans = solve(steps - 1, idx, n);
        ans %= mod;
        ans += solve(steps - 1, idx - 1, n);
        ans %= mod;
        ans += solve(steps - 1, idx + 1, n);
        ans %= mod;
        return dp[steps][idx] = ans;
    }
    int numWays(int steps, int arrLen)
    {
        return solve(steps, 0, arrLen);
    }
};