/*You are given an undirected graph (the "original graph") with n nodes labeled from 0 to n - 1. You decide to subdivide each edge in the graph into a chain of nodes, with the number of new nodes varying between each edge.

The graph is given as a 2D array of edges where edges[i] = [ui, vi, cnti] indicates that there is an edge between nodes ui and vi in the original graph, and cnti is the total number of new nodes that you will subdivide the edge into. Note that cnti == 0 means you will not subdivide the edge.

To subdivide the edge [ui, vi], replace it with (cnti + 1) new edges and cnti new nodes. The new nodes are x1, x2, ..., xcnti, and the new edges are [ui, x1], [x1, x2], [x2, x3], ..., [xcnti-1, xcnti], [xcnti, vi].

In this new graph, you want to know how many nodes are reachable from the node 0, where a node is reachable if the distance is maxMoves or less.

Given the original graph and maxMoves, return the number of nodes that are reachable from node 0 in the new graph.

 

Example 1:

https://s3-lc-upload.s3.amazonaws.com/uploads/2018/08/01/origfinal.png

Input: edges = [[0,1,10],[0,2,1],[1,2,2]], maxMoves = 6, n = 3
Output: 13
Explanation: The edge subdivisions are shown in the image above.
The nodes that are reachable are highlighted in yellow.
Example 2:

Input: edges = [[0,1,4],[1,2,6],[0,2,8],[1,3,1]], maxMoves = 10, n = 4
Output: 23
Example 3:

Input: edges = [[1,2,4],[1,4,5],[1,3,1],[2,3,4],[3,4,5]], maxMoves = 17, n = 5
Output: 1
Explanation: Node 0 is disconnected from the rest of the graph, so only node 0 is reachable.*/
#include <iostream>
#include <vector>
#include <set>
#include <utility>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<pair<int,int>>> graph;
    vector<int> dp;
    
    void dijkstra(int n){
        vector<bool> visited(n);
        multiset<pair<int,int>, greater<pair<int,int>>> s;
        s.insert({dp[0], 0});
        while(!s.empty()){
            pair<int,int> p = *s.begin();
            s.erase(s.begin());
            int x = p.second;
            if(visited[x]) continue;
            visited[x] = true;
            for(auto neigh : graph[x]){
                int node = neigh.first;
                int weigh = neigh.second;
                if(dp[x] - weigh > dp[node]){
                    dp[node] = dp[x] - weigh;
                    s.insert({dp[node], node});
                }
            }
        }
    }
    
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        int m = edges.size();
        graph = vector<vector<pair<int,int>>>(n);
        dp = vector<int>(n , -1);
        for(int i = 0; i < m; i++){
            int x = edges[i][0];
            int y = edges[i][1];
            int w = edges[i][2];
            graph[x].push_back({y, w + 1});
            graph[y].push_back({x, w + 1});
        }
        dp[0] = maxMoves;
        dijkstra(n);

        int ans = 0;
        int tot = 0;
        int zer = 0;
        for(int i = 0; i < m; i++){
            int x = edges[i][0];
            int y = edges[i][1];
            int w = edges[i][2];
            if(x == 0 || y == 0) zer++;
            if(dp[x] == -1 && dp[y] == -1){
                ans += w;
            }
            else if(dp[x] == -1 && dp[y] != -1){
                ans += (w - dp[y]);
            }
            else if(dp[x] != -1 && dp[y] == -1){
                ans += (w - dp[x]);
            }
            else if(dp[x] != -1 && dp[y] != -1){
                ans += max(0, w - (dp[x] + dp[y]));
            }
            tot += w;
        }
        int x = 0;
        for(int i = 0; i < n; i++){
            if(dp[i] == -1) ans++;
        }
        tot += n;
        if(!zer) return 1;
        return tot - ans;
    }
};
