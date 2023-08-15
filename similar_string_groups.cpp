/*Two strings, X and Y, are considered similar if either they are identical or we can make them equivalent by swapping at most two letters (in distinct positions) within the string X.

For example, "tars" and "rats" are similar (swapping at positions 0 and 2), and "rats" and "arts" are similar, but "star" is not similar to "tars", "rats", or "arts".

Together, these form two connected groups by similarity: {"tars", "rats", "arts"} and {"star"}.  Notice that "tars" and "arts" are in the same group even though they are not similar.  Formally, each group is such that a word is in the group if and only if it is similar to at least one other word in the group.

We are given a list strs of strings where every string in strs is an anagram of every other string in strs. How many groups are there?

 

Example 1:

Input: strs = ["tars","rats","arts","star"]
Output: 2
Example 2:

Input: strs = ["omv","ovm"]
Output: 1*/
#include <vector>
#include <string>

using namespace std;

class UnionFind {
    vector<int> parent, rank;
    int setCount;

public:
    UnionFind(int n) {
        for (int i = 0; i < n; i++) {
            parent.push_back(i);
        }
        setCount = n;
        rank.resize(n, 0);
    }

    int find(int x) {
        int root = x;
        while (root != parent[root])
            root = parent[root];

        while (x != root) {
            int t = parent[x];
            parent[x] = root;
            x = t;
        }
        return root;
    }

    void union_(int x, int y) {
        int xSet = find(x);
        int ySet = find(y);

        if (xSet == ySet)
            return;

        setCount--;
        if (rank[ySet] < rank[xSet])
            parent[ySet] = xSet;
        else {
            parent[xSet] = ySet;
            if (rank[xSet] == rank[ySet])
                rank[ySet]++;
        }
    }

    int get_setCount() {
        return setCount;
    }
};

class Solution {
public:
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        UnionFind obj(n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                int count = 0;
                for (int k = 0; k < strs[j].size(); k++) {
                    if (strs[i][k] != strs[j][k])
                        count++;

                    if (count > 2)
                        break;
                }
                if (count <= 2) {
                    obj.union_(i, j);
                }
            }
        }
        return obj.get_setCount();
    }

    vector<int> g[40000];
    void dfs1(int u, vector<int>& res, vector<int>& count, int par = -1) {
        for (int& x : g[u]) {
            if (x == par)
                continue;
            dfs1(x, res, count, u);
            count[u] = count[u] + count[x];
            res[u] = res[u] + res[x] + count[x];
        }
        count[u]++;
    }

    void dfs2(int u, vector<int>& res, vector<int>& count, int n, int par = -1) {
        for (int& x : g[u]) {
            if (x == par)
                continue;
            res[x] = res[u] - count[x] + (n - count[x]);
            dfs2(x, res, count, n, u);
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        for (auto& x : edges) {
            g[x[0]].push_back(x[1]);
            g[x[1]].push_back(x[0]);
        }
        vector<int> res(n, 0), count(n, 0);
        dfs1(0, res, count);
        dfs2(0, res, count, n);
        return res;
    }
};