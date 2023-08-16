/*Strings s1 and s2 are k-similar (for some non-negative integer k) if we can swap the positions of two letters in s1 exactly k times so that the resulting string equals s2.

Given two anagrams s1 and s2, return the smallest k for which s1 and s2 are k-similar.

 

Example 1:

Input: s1 = "ab", s2 = "ba"
Output: 1
Explanation: The two string are 1-similar because we can use one swap to change s1 to s2: "ab" --> "ba".
Example 2:

Input: s1 = "abc", s2 = "bca"
Output: 2
Explanation: The two strings are 2-similar because we can use two swaps to change s1 to s2: "abc" --> "bac" --> "bca".*/
#include <iostream>
#include <vector>
#include <map>
#include <tuple>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<pair<int, int> > edges;
    int n, m;
    map<tuple<int, int, int>, int> memo;
    int dfs(int bitmask, int v, int start) {
        if (v == -1) {
            for (int i = 0; i < m; ++i) {
                if (!(bitmask >> i & 1)) {
                    return dfs(bitmask | (1<<i), edges[i].second, edges[i].first) + 1;
                }
            }
        }
        if (bitmask == (1<<m) - 1) {
            return 0;
        }
        assert(v!=-1 && start!=-1);

        if (memo.count({bitmask, v, start})) {
            return memo[{bitmask, v, start}];
        }
        int result = m;
        for (int i = 0; i < edges.size(); ++i) {
            if (bitmask>>i&1) continue;
            if (edges[i].first != v) continue;
            if (edges[i].second == start) {
                result = min(result, dfs(bitmask | (1<<i), -1, -1));
                break;
            }
        }
        if (result == m) {
            for (int i = 0; i < edges.size(); ++i) {
                if (bitmask>>i&1) continue;
                if (edges[i].first != v) continue;
                result = min(result, dfs(bitmask | (1<<i), edges[i].second, start) + 1);
            }
        }
        return memo[{bitmask, v, start}] = result;
    }
    int kSimilarity(string s1, string s2) {
        n = s1.size();
        for (int i = 0; i < n; ++i) {
            if (s1[i] != s2[i]) {
                edges.push_back({s1[i] - 'a', s2[i] - 'a'});
            }
        }
        m = edges.size();

        return dfs(0, -1, -1);
    }
};
