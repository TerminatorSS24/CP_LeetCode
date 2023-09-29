/*You have an undirected, connected graph of n nodes labeled from 0 to n - 1. You are given an array graph where graph[i] is a list of all the nodes connected with node i by an edge.

Return the length of the shortest path that visits every node. You may start and stop at any node, you may revisit nodes multiple times, and you may reuse edges.



Example 1:

image: https://assets.leetcode.com/uploads/2021/05/12/shortest1-graph.jpg

Input: graph = [[1,2,3],[0],[0],[0]]
Output: 4
Explanation: One possible path is [1,0,2,0,3]
Example 2:

image: https://assets.leetcode.com/uploads/2021/05/12/shortest2-graph.jpg

Input: graph = [[1],[0,2,4],[1,3,4],[2],[1,2]]
Output: 4
Explanation: One possible path is [0,1,4,2,3]
**********LEETCODE POTD(17/09/2023)**********
*/
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <utility>

using namespace std;

class Solution
{
public:
    int shortestPathLength(vector<vector<int>> &graph)
    {
        int i, n = graph.size(), j, ans = 0;
        queue<vector<int>> q;
        set<pair<int, int>> s;
        for (i = 0; i < n; i++)
        {
            vector<int> v(3, 0);
            int mask = (1 << i);
            int node = i;
            int cost = 0;
            v[0] = cost;
            v[1] = node;
            v[2] = mask;
            q.push(v);
            s.insert({node, mask});
        }

        while (q.size() > 0)
        {
            auto z = q.front();
            q.pop();
            if (z[2] == (1 << n) - 1)
            {
                ans = z[0];
                break;
            }

            for (auto j : graph[z[1]])
            {
                int mask = z[2] | (1 << j);
                if (s.find({j, mask}) == s.end())
                {
                    s.insert({j, mask});
                    vector<int> v(3, 0);
                    v[0] = z[0] + 1;
                    v[1] = j;
                    v[2] = mask;
                    q.push(v);
                }
            }
        }
        return ans;
    }
};