/*There is an undirected connected tree with n nodes labeled from 0 to n - 1 and n - 1 edges.

You are given the integer n and the array edges where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree.

Return an array answer of length n where answer[i] is the sum of the distances between the ith node in the tree and all other nodes.

 

Example 1:


Input: n = 6, edges = [[0,1],[0,2],[2,3],[2,4],[2,5]]
Output: [8,12,6,10,10,10]
Explanation: The tree is shown above.
We can see that dist(0,1) + dist(0,2) + dist(0,3) + dist(0,4) + dist(0,5)
equals 1 + 1 + 2 + 2 + 2 = 8.
Hence, answer[0] = 8, and so on.
Example 2:


Input: n = 1, edges = []
Output: [0]
Example 3:


Input: n = 2, edges = [[1,0]]
Output: [1,1]*/
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> g[40000];
    void dfs1(int u, vector<int> &res, vector<int> &count, int par = -1) {
        for (int &x : g[u]) {
            if (x == par) continue;
            dfs1(x, res, count, u);
            count[u] = count[u] + count[x];
            res[u] = res[u] + res[x] + count[x];
        }
        count[u]++;
    }

    void dfs2(int u, vector<int> &res, vector<int> &count, int n, int par = -1) {
        for (int &x : g[u]) {
            if (x == par) continue;
            res[x] = res[u] - count[x] + (n - count[x]);
            dfs2(x, res, count, n, u);
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        for (auto &x : edges) {
            g[x[0]].push_back(x[1]);
            g[x[1]].push_back(x[0]);
        }
        vector<int> res(n, 0), count(n, 0);
        dfs1(0, res, count);
        dfs2(0, res, count, n);
        return res;
    }
};
