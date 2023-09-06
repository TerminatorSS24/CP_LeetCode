/*Given an array of strings words, return the smallest string that contains each string in words as a substring. If there are multiple valid strings of the smallest length, return any of them.

You may assume that no string in words is a substring of another string in words.

 

Example 1:

Input: words = ["alex","loves","leetcode"]
Output: "alexlovesleetcode"
Explanation: All permutations of "alex","loves","leetcode" would also be accepted.
Example 2:

Input: words = ["catg","ctaagt","gcta","ttca","atgcatc"]
Output: "gctaagttcatgcatc"*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
    int computeOverlap(string s, string t) {
        int n = s.size();
        int idx = n;

        for (int i = n - 1; i >= 0; i--) {
            if (s.substr(i, (n - i)) == t.substr(0, n - i)) {
                idx = i;
            }
        }
        return n - idx;
    }
    
    string computeUncommonPart(const string &s, const string &t) {
        int n = s.size();
        int idx = n;

        for (int i = n - 1; i >= 0; i--) {
            if (s.substr(i, (n - i)) == t.substr(0, n - i)) {
                idx = i;
            }
        }
        if (idx == n) {
            return s;
        }
        return s.substr(0, idx);
    }

public:
    string shortestSuperstring(vector<string>& words) {
        int n = words.size();
        vector<vector<int>> overlap(n, vector<int>(n));
        vector<vector<int>> parent(1 << n, vector<int>(n, -1));
        vector<vector<int>> dp(1 << n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    overlap[i][j] = computeOverlap(words[i], words[j]);
                }
            }
        }

        for (int mask = 0; mask < (1 << n); mask++) {
            for (int i = 0; i < n; i++) {
                if ((mask) & (1 << i)) {
                    for (int j = 0; j < n; j++) {
                        if (((mask) & (1 << j)) == 0) {
                            if (dp[mask | 1 << j][j] < dp[mask][i] + overlap[i][j]) {
                                dp[mask | 1 << j][j] = dp[mask][i] + overlap[i][j];
                                parent[mask | 1 << j][j] = i;
                            }
                        }
                    }
                }
            }
        }
        int mx = 0;
        int dest = -1;
        for (int i = 0; i < n; i++) {
            if (dp[(1 << n) - 1][i] > mx) {
                mx = dp[(1 << n) - 1][i];
                dest = i;
            }
        }
        vector<bool> visited(n);
        vector<string> res;
        int mask = (1 << n) - 1;
        int src = dest;
        while (dest != -1) {
            res.push_back(words[dest]);
            visited[dest] = true;
            int prev = parent[mask][dest];
            mask ^= (1 << dest);
            dest = prev;
        }

        reverse(res.begin(), res.end());
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                res.push_back(words[i]);
                visited[i] = true;
            }
        }
        string ans = "";
        for (int i = 0; i < n - 1; i++) {
            string uncommonPart = computeUncommonPart(res[i], res[i + 1]);
            ans += uncommonPart;
        }
        ans += res[n - 1];
        return ans;
    }
};
