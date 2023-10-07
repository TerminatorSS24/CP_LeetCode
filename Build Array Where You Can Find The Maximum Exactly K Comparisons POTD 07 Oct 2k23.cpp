/*You are given three integers n, m and k. Consider the following algorithm to find the maximum element of an array of positive integers:

image: https://assets.leetcode.com/uploads/2020/04/02/e.png

You should build the array arr which has the following properties:

arr has exactly n integers.
1 <= arr[i] <= m where (0 <= i < n).
After applying the mentioned algorithm to arr, the value search_cost is equal to k.
Return the number of ways to build the array arr under the mentioned conditions. As the answer may grow large, the answer must be computed modulo 109 + 7.

 

Example 1:

Input: n = 2, m = 3, k = 1
Output: 6
Explanation: The possible arrays are [1, 1], [2, 1], [2, 2], [3, 1], [3, 2] [3, 3]
Example 2:

Input: n = 5, m = 2, k = 3
Output: 0
Explanation: There are no possible arrays that satisify the mentioned conditions.
Example 3:

Input: n = 9, m = 1, k = 1
Output: 1
Explanation: The only possible array is [1, 1, 1, 1, 1, 1, 1, 1, 1]*/
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int numOfArrays(int n, int m, int k)
    {
        const int mod = 1e9 + 7;

        vector<vector<int>> dp(m + 1, vector<int>(k + 1, 0));
        vector<vector<int>> prefix(m + 1, vector<int>(k + 1, 0));
        vector<vector<int>> prevDp(m + 1, vector<int>(k + 1, 0));
        vector<vector<int>> prevPrefix(m + 1, vector<int>(k + 1, 0));

        for (int j = 1; j <= m; j++)
        {
            prevDp[j][1] = 1;
            prevPrefix[j][1] = j;
        }

        for (int _ = 2; _ <= n; _++)
        {
            dp.assign(m + 1, vector<int>(k + 1, 0));
            prefix.assign(m + 1, vector<int>(k + 1, 0));

            for (int maxNum = 1; maxNum <= m; maxNum++)
            {
                for (int cost = 1; cost <= k; cost++)
                {
                    dp[maxNum][cost] = (static_cast<long long>(maxNum) * prevDp[maxNum][cost]) % mod;

                    if (maxNum > 1 && cost > 1)
                    {
                        dp[maxNum][cost] = (dp[maxNum][cost] + prevPrefix[maxNum - 1][cost - 1]) % mod;
                    }

                    prefix[maxNum][cost] = (prefix[maxNum - 1][cost] + dp[maxNum][cost]) % mod;
                }
            }

            prevDp = dp;
            prevPrefix = prefix;
        }

        return prefix[m][k];
    }
};

int main()
{
    Solution solution;
    int n = 3, m = 3, k = 3;
    int result = solution.numOfArrays(n, m, k);
    cout << "Result: " << result << endl;
    return 0;
}
