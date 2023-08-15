/*You are given an m x n binary grid, where each 1 represents a brick and 0 represents an empty space. A brick is stable if:

It is directly connected to the top of the grid, or
At least one other brick in its four adjacent cells is stable.
You are also given an array hits, which is a sequence of erasures we want to apply. Each time we want to erase the brick at the location hits[i] = (rowi, coli). The brick on that location (if it exists) will disappear. Some other bricks may no longer be stable because of that erasure and will fall. Once a brick falls, it is immediately erased from the grid (i.e., it does not land on other stable bricks).

Return an array result, where each result[i] is the number of bricks that will fall after the ith erasure is applied.

Note that an erasure may refer to a location with no brick, and if it does, no bricks drop.

 

Example 1:

Input: grid = [[1,0,0,0],[1,1,1,0]], hits = [[1,0]]
Output: [2]
Explanation: Starting with the grid:
[[1,0,0,0],
 [1,1,1,0]]
We erase the underlined brick at (1,0), resulting in the grid:
[[1,0,0,0],
 [0,1,1,0]]
The two underlined bricks are no longer stable as they are no longer connected to the top nor adjacent to another stable brick, so they will fall. The resulting grid is:
[[1,0,0,0],
 [0,0,0,0]]
Hence the result is [2].
Example 2:

Input: grid = [[1,0,0,0],[1,1,0,0]], hits = [[1,1],[1,0]]
Output: [0,0]
Explanation: Starting with the grid:
[[1,0,0,0],
 [1,1,0,0]]
We erase the underlined brick at (1,1), resulting in the grid:
[[1,0,0,0],
 [1,0,0,0]]
All remaining bricks are still stable, so no bricks fall. The grid remains the same:
[[1,0,0,0],
 [1,0,0,0]]
Next, we erase the underlined brick at (1,0), resulting in the grid:
[[1,0,0,0],
 [0,0,0,0]]
Once again, all remaining bricks are still stable, so no bricks fall.
Hence the result is [0,0].*/
#include <vector>

class Solution {
public:
    std::vector<int> parent, size;
    std::vector<std::vector<int>> dict = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    
    std::vector<int> hitBricks(std::vector<std::vector<int>>& grid, std::vector<std::vector<int>>& hits) {
        int n = grid.size();
        int m = grid[0].size();
        parent.resize(m * n, 0);
        size.resize(m * n, 1);
        
        for (int i = 0; i < m * n; i++) {
            parent[i] = i;
        }
        
        std::vector<int> vec(hits.size(), 0);
        
        for (auto& x : hits) {
            grid[x[0]][x[1]]--;
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] > 0) {
                    for (int k = 0; k < 4; k++) {
                        int x = i + dict[k][0];
                        int y = j + dict[k][1];
                        if (x >= 0 && y >= 0 && x < n && y < m && grid[x][y] > 0) {
                            find_union(i * m + j, x * m + y);
                        }
                    }
                }
            }
        }
        
        for (int i = static_cast<int>(hits.size()) - 1; i >= 0; i--) {
            int x = hits[i][0];
            int y = hits[i][1];
            int flag = 0;
            
            if (++grid[x][y] > 0) {
                if (x == 0) {
                    flag = 1;
                }
                
                for (int k = 0; k < 4; k++) {
                    int p = x + dict[k][0];
                    int q = y + dict[k][1];
                    if (p >= 0 && q >= 0 && p < n && q < m && grid[p][q] > 0) {
                        if (find_p(p * m + q) < m) {
                            flag = 1;
                        } else if (find_p(x * m + y) != find_p(p * m + q)) {
                            vec[i] += size[find_p(p * m + q)];
                        }
                        find_union(x * m + y, p * m + q);
                    }
                }
            }
            
            vec[i] *= flag;
        }
        
        return vec;
    }
    
    int find_p(int node) {
        if (parent[node] == node) {
            return node;
        }
        
        return parent[node] = find_p(parent[node]);
    }
    
    void find_union(int u, int v) {
        int ulp_u = find_p(u);
        int ulp_v = find_p(v);
        
        if (ulp_u == ulp_v) {
            return;
        }
        
        if (ulp_u < ulp_v) { 
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        } else {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
    }
};
