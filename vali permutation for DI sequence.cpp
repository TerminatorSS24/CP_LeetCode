/*You are given a string s of length n where s[i] is either:

'D' means decreasing, or
'I' means increasing.
A permutation perm of n + 1 integers of all the integers in the range [0, n] is called a valid permutation if for all valid i:

If s[i] == 'D', then perm[i] > perm[i + 1], and
If s[i] == 'I', then perm[i] < perm[i + 1].
Return the number of valid permutations perm. Since the answer may be large, return it modulo 109 + 7.

 

Example 1:

Input: s = "DID"
Output: 5
Explanation: The 5 valid permutations of (0, 1, 2, 3) are:
(1, 0, 3, 2)
(2, 0, 3, 1)
(2, 1, 3, 0)
(3, 0, 2, 1)
(3, 1, 2, 0)
Example 2:

Input: s = "D"
Output: 1*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int mod = 1e9 + 7;

    long long hope(int index, int prev, vector<int> &curr, vector<int> &visited, string &s, int &n, vector<vector<long long>> &dp) {
        if (index >= s.length() && curr.size() == n + 1) return 1;
        if (dp[index + 1][prev + 1] != -1) return dp[index + 1][prev + 1];
        long long ans = 0;
        
        if (index == -1) {
            for (int i = 0; i <= n; i++) {
                curr.push_back(i);
                visited[i] = -1;
                ans = (ans % mod + hope(index + 1, i, curr, visited, s, n, dp) % mod) % mod;
                curr.pop_back();
                visited[i] = 0;
            }
        } else if (index != -1) {
            if (s[index] == 'I') {
                int previous = prev;
                for (int i = previous + 1; i <= n; i++) {
                    if (visited[i] != -1) {
                        curr.push_back(i);
                        visited[i] = -1;
                        ans = (ans % mod + hope(index + 1, i, curr, visited, s, n, dp) % mod) % mod;
                        curr.pop_back();
                        visited[i] = 0;
                    }
                }
            } else if (s[index] == 'D') {
                int previous = prev;
                for (int i = 0; i < previous; i++) {
                    if (visited[i] != -1) {
                        curr.push_back(i);
                        visited[i] = -1;
                        ans = (ans % mod + hope(index + 1, i, curr, visited, s, n, dp) % mod) % mod;
                        curr.pop_back();
                        visited[i] = 0;
                    }
                }
            }
        }
        return dp[index + 1][prev + 1] = ans % mod;
    }

    int numPermsDISequence(string s) {
        int n = s.length();
        vector<int> visited(s.length() + 1, 0);
        vector<int> curr;
        vector<vector<long long>> dp(202, vector<long long>(202, -1));
        long long fa = hope(-1, -1, curr, visited, s, n, dp) % mod;
        int answer = fa;
        return answer;
    }
};