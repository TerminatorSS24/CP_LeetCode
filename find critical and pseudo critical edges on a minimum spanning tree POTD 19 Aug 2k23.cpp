/*Given a weighted undirected connected graph with n vertices numbered from 0 to n - 1, and an array edges where edges[i] = [ai, bi, weighti] represents a bidirectional and weighted edge between nodes ai and bi. A minimum spanning tree (MST) is a subset of the graph's edges that connects all vertices without cycles and with the minimum possible total edge weight.

Find all the critical and pseudo-critical edges in the given graph's minimum spanning tree (MST). An MST edge whose deletion from the graph would cause the MST weight to increase is called a critical edge. On the other hand, a pseudo-critical edge is that which can appear in some MSTs but not all.

Note that you can return the indices of the edges in any order.

 

Example 1:

image: https://assets.leetcode.com/uploads/2020/06/04/ex1.png

Input: n = 5, edges = [[0,1,1],[1,2,1],[2,3,2],[0,3,2],[0,4,3],[3,4,3],[1,4,6]]
Output: [[0,1],[2,3,4,5]]
Explanation: The figure above describes the graph.
The following figure shows all the possible MSTs:

image: https://assets.leetcode.com/uploads/2020/06/04/msts.png

Notice that the two edges 0 and 1 appear in all MSTs, therefore they are critical edges, so we return them in the first list of the output.
The edges 2, 3, 4, and 5 are only part of some MSTs, therefore they are considered pseudo-critical edges. We add them to the second list of the output.
Example 2:

image: https://assets.leetcode.com/uploads/2020/06/04/ex2.png

Input: n = 4, edges = [[0,1,1],[1,2,1],[2,3,1],[0,3,1]]
Output: [[],[0,1,2,3]]
Explanation: We can observe that since all 4 edges have equal weight, choosing any 3 edges from the given 4 will yield an MST. Therefore all 4 edges are pseudo-critical.
**********LEETCODE POTD(19/08/2023)**********
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class DSU {
    int* parent;
    int* rank;
    int groupsCount;

public:
    DSU(int n) {
        parent = new int[n];
        rank = new int[n];
        groupsCount = n;

        for (int i = 0; i < n; i++) {
            parent[i] = -1;
            rank[i] = 1;
        }
    }

    int find(int i) {
        if (parent[i] == -1)
            return i;

        return parent[i] = find(parent[i]);
    }

    void unite(int x, int y) {
        int s1 = find(x);
        int s2 = find(y);

        if (s1 != s2) {
            if (rank[s1] < rank[s2]) {
                parent[s1] = s2;
            } else if (rank[s1] > rank[s2]) {
                parent[s2] = s1;
            } else {
                parent[s2] = s1;
                rank[s1] += 1;
            }
            groupsCount--;
        }
    }

    int getGroupsCount() const { 
        return groupsCount;
    }
};

class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        for (int i = 0; i < m; ++i) {
            edges[i].push_back(i);
        }
        sort(edges.begin(), edges.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
        });

        int originalMST = 0;
        DSU originalDSU(n);
        for (int i = 0; i < m; ++i) {
            int w = edges[i][2];
            int x = edges[i][0];
            int y = edges[i][1];

            if (originalDSU.find(x) != originalDSU.find(y)) {
                originalDSU.unite(x, y);
                originalMST += w;
            }
        }

        vector<vector<int>> result(2);

        for (int i = 0; i < m; ++i) {
            DSU dsu(n);
            int weightWithoutEdge = 0;
            for (int j = 0; j < m; ++j) {
                if (i != j) {
                    int w = edges[j][2];
                    int x = edges[j][0];
                    int y = edges[j][1];

                    if (dsu.find(x) != dsu.find(y)) {
                        dsu.unite(x, y);
                        weightWithoutEdge += w;
                    }
                }
            }
            if (dsu.getGroupsCount() > 1 || weightWithoutEdge > originalMST) {
                result[0].push_back(edges[i][3]);
                continue;
            }

            dsu = DSU(n);
            dsu.unite(edges[i][0], edges[i][1]);
            int weightWithEdge = edges[i][2];
            for (int j = 0; j < m; ++j) {
                if (i != j) {
                    int w = edges[j][2];
                    int x = edges[j][0];
                    int y = edges[j][1];

                    if (dsu.find(x) != dsu.find(y)) {
                        dsu.unite(x, y);
                        weightWithEdge += w;
                    }
                }
            }
            if (weightWithEdge == originalMST) {
                result[1].push_back(edges[i][3]);
            }
        }

        return result; 
    }
};