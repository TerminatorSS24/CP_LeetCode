/*There is a group of n members, and a list of various crimes they could commit. The ith crime generates a profit[i] and requires group[i] members to participate in it. If a member participates in one crime, that member can't participate in another crime.

Let's call a profitable scheme any subset of these crimes that generates at least minProfit profit, and the total number of members participating in that subset of crimes is at most n.

Return the number of schemes that can be chosen. Since the answer may be very large, return it modulo 109 + 7.

 

Example 1:

Input: n = 5, minProfit = 3, group = [2,2], profit = [2,3]
Output: 2
Explanation: To make a profit of at least 3, the group could either commit crimes 0 and 1, or just crime 1.
In total, there are 2 schemes.
Example 2:

Input: n = 10, minProfit = 5, group = [2,3,5], profit = [6,7,8]
Output: 7
Explanation: To make a profit of at least 5, the group could commit any crimes, as long as they commit one.
There are 7 possible schemes: (0), (1), (2), (0,1), (0,2), (1,2), and (0,1,2).*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    int m;
    int mod = 1e9 + 7;

    int helper(int idx, int people, int curr_profit, int n, int minProfit, vector<int>& group, vector<int>& profit,
        vector<vector<vector<int>>>& dp)
    {
        if (people > n) {
            return 0;
        }
        if (idx == m) {
            if (people <= n && curr_profit >= minProfit) {
                return 1;
            }
            else {
                return 0;
            }
        }

        if (dp[idx][people][curr_profit] != -1) {
            return dp[idx][people][curr_profit];
        }

        int take = helper(idx + 1, people + group[idx], min(curr_profit + profit[idx], minProfit), n, minProfit, group, profit, dp);

        int not_take = helper(idx + 1, people, curr_profit, n, minProfit, group, profit, dp);

        return dp[idx][people][curr_profit] = (take + not_take) % mod;
    }

    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit)
    {
        m = group.size();

        int max_profit = 0;

        for (int i = 0; i < m; i++) {
            max_profit += profit[i];
        }

        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n + 1, vector<int>(minProfit + 1, -1)));

        return helper(0, 0, 0, n, minProfit, group, profit, dp);
    }
};
