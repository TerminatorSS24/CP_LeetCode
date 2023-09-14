/*There is a 2D grid of size n x n where each cell of this grid has a lamp that is initially turned off.

You are given a 2D array of lamp positions lamps, where lamps[i] = [rowi, coli] indicates that the lamp at grid[rowi][coli] is turned on. Even if the same lamp is listed more than once, it is turned on.

When a lamp is turned on, it illuminates its cell and all other cells in the same row, column, or diagonal.

You are also given another 2D array queries, where queries[j] = [rowj, colj]. For the jth query, determine whether grid[rowj][colj] is illuminated or not. After answering the jth query, turn off the lamp at grid[rowj][colj] and its 8 adjacent lamps if they exist. A lamp is adjacent if its cell shares either a side or corner with grid[rowj][colj].

Return an array of integers ans, where ans[j] should be 1 if the cell in the jth query was illuminated, or 0 if the lamp was not.

 

Example 1:

image: https://assets.leetcode.com/uploads/2020/08/19/illu_1.jpg

Input: n = 5, lamps = [[0,0],[4,4]], queries = [[1,1],[1,0]]
Output: [1,0]
Explanation: We have the initial grid with all lamps turned off. In the above picture we see the grid after turning on the lamp at grid[0][0] then turning on the lamp at grid[4][4].
The 0th query asks if the lamp at grid[1][1] is illuminated or not (the blue square). It is illuminated, so set ans[0] = 1. Then, we turn off all lamps in the red square.

image: https://assets.leetcode.com/uploads/2020/08/19/illu_step1.jpg

The 1st query asks if the lamp at grid[1][0] is illuminated or not (the blue square). It is not illuminated, so set ans[1] = 0. Then, we turn off all lamps in the red rectangle.
image: https://assets.leetcode.com/uploads/2020/08/19/illu_step2.jpg

Example 2:

Input: n = 5, lamps = [[0,0],[4,4]], queries = [[1,1],[1,1]]
Output: [1,1]
Example 3:

Input: n = 5, lamps = [[0,0],[0,4]], queries = [[0,4],[0,1],[1,4]]
Output: [1,1,0]*/
#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <utility>  
#include <functional> 

using namespace std;

struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1, T2>& p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);
        return h1 ^ h2;
    }
};

class Solution {
public:
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        multiset<int> row, col, dia1, dia2;
        unordered_set<pair<int, int>, pair_hash> arr;
        
        for (auto i : lamps) {
            if (arr.find({i[0], i[1]}) != arr.end()) continue;
            row.insert(i[0]);
            col.insert(i[1]);
            dia1.insert(i[0] + i[1]);
            dia2.insert(n + i[0] - i[1] - 1);
            arr.insert({i[0], i[1]});
        }
        
        vector<int> ans;
        int dx[] = {1, 1, 1, -1, -1, -1, 0, 0, 0};
        int dy[] = {1, 0, -1, -1, 0, 1, 0, 1, -1};
        
        for (auto i : queries) {
            int r = i[0];
            int c = i[1];
            ans.push_back(0);
            
            if (row.find(r) != row.end() || col.find(c) != col.end() || dia1.find(r + c) != dia1.end() || dia2.find(n + r - c - 1) != dia2.end())
                ans.back() = 1;
            
            for (int j = 0; j < 9; j++) {
                int x = r + dx[j];
                int y = c + dy[j];
                
                if (x >= 0 && y >= 0 && x < n && y < n && arr.find({x, y}) != arr.end()) {
                    row.erase(row.find(x));
                    col.erase(col.find(y));
                    dia1.erase(dia1.find(x + y));
                    dia2.erase(dia2.find(n + x - y - 1));
                    arr.erase({x, y});
                }
            }
        }
        return ans;
    }
};
