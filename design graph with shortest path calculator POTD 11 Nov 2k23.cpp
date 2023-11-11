/*There is a directed weighted graph that consists of n nodes numbered from 0 to n - 1. The edges of the graph are initially represented by the given array edges where edges[i] = [fromi, toi, edgeCosti] meaning that there is an edge from fromi to toi with the cost edgeCosti.

Implement the Graph class:

Graph(int n, int[][] edges) initializes the object with n nodes and the given edges.
addEdge(int[] edge) adds an edge to the list of edges where edge = [from, to, edgeCost]. It is guaranteed that there is no edge between the two nodes before adding this one.
int shortestPath(int node1, int node2) returns the minimum cost of a path from node1 to node2. If no path exists, return -1. The cost of a path is the sum of the costs of the edges in the path.
 

Example 1:


Input
["Graph", "shortestPath", "shortestPath", "addEdge", "shortestPath"]
[[4, [[0, 2, 5], [0, 1, 2], [1, 2, 1], [3, 0, 3]]], [3, 2], [0, 3], [[1, 3, 4]], [0, 3]]
Output
[null, 6, -1, null, 6]

Explanation
Graph g = new Graph(4, [[0, 2, 5], [0, 1, 2], [1, 2, 1], [3, 0, 3]]);
g.shortestPath(3, 2); // return 6. The shortest path from 3 to 2 in the first diagram above is 3 -> 0 -> 1 -> 2 with a total cost of 3 + 2 + 1 = 6.
g.shortestPath(0, 3); // return -1. There is no path from 0 to 3.
g.addEdge([1, 3, 4]); // We add an edge from node 1 to node 3, and we get the second diagram above.
g.shortestPath(0, 3); // return 6. The shortest path from 0 to 3 now is 0 -> 1 -> 3 with a total cost of 2 + 4 = 6.
**********LEETCOPDE POTD(11/11/2023)**********
*/
#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Graph {
    using int2 = pair<int, int>;
    vector<vector<int2>> adj;
    int n;

public:
    Graph(int n, vector<vector<int>>& edges) : n(n) {
        adj.resize(n);
        for (auto& edge : edges) {
            adj[edge[0]].emplace_back(edge[2], edge[1]);
        }
    }

    void addEdge(vector<int> edge) {
        adj[edge[0]].emplace_back(edge[2], edge[1]);
    }

    int shortestPath(int node1, int node2) {
        priority_queue<int2, vector<int2>, greater<int2>> pq; //minHeap
        vector<int> dist(n, INT_MAX);
        dist[node1] = 0;
        pq.emplace(0, node1);

        while (!pq.empty()) {
            int d, i;
            tie(d, i) = pq.top();
            pq.pop();

            if (i == node2) {
                addEdge({node1, node2, d}); // Add this edge
                return d;
            }

            if (d > dist[i]) continue;

            int d2;

            for (auto [w, j] : adj[i]) {
                int d2 = d + w;
                if (d2 < dist[j]) {
                    dist[j] = d2;
                    pq.emplace(d2, j);
                }
            }
        }
        return -1;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */
