/*You are given an n x n integer matrix grid where each value grid[i][j] represents the elevation at that point (i, j).

The rain starts to fall. At time t, the depth of the water everywhere is t. You can swim from a square to another 4-directionally adjacent square if and only if the elevation of both squares individually are at most t. You can swim infinite distances in zero time. Of course, you must stay within the boundaries of the grid during your swim.

Return the least time until you can reach the bottom right square (n - 1, n - 1) if you start at the top left square (0, 0).

 

Example 1:

image: https://assets.leetcode.com/uploads/2021/06/29/swim1-grid.jpg

Input: grid = [[0,2],[1,3]]
Output: 3
Explanation:
At time 0, you are in grid location (0, 0).
You cannot go anywhere else because 4-directionally adjacent neighbors have a higher elevation than t = 0.
You cannot reach point (1, 1) until time 3.
When the depth of water is 3, we can swim anywhere inside the grid.
Example 2:

image: https://assets.leetcode.com/uploads/2021/06/29/swim2-grid-1.jpg

Input: grid = [[0,1,2,3,4],[24,23,22,21,5],[12,13,14,15,16],[11,17,18,19,20],[10,9,8,7,6]]
Output: 16
Explanation: The final route is shown.
We need to wait until time 16 so that (0, 0) and (4, 4) are connected.*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int swimInWater(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> time(n , vector<int>(m , INT_MAX));

        time[0][0] = heights[0][0];

        priority_queue<vector<int>, vector<vector<int>> , greater<vector<int>>> pq;

        pq.push({time[0][0],0,0});
        int rows[] = {1,0,0,-1};
        int cols[] = {0,1,-1,0};
        while(!pq.empty()){
            int r = pq.top()[1];
            int c = pq.top()[2];

            int ef = pq.top()[0];
            pq.pop();
            for(int i=0;i<4;i++){
                int x = r + rows[i];
                int y = c + cols[i];

                if(x >= 0 && y >=0 && x < n && y< m){
                    int finalEf = max(heights[x][y], ef);
                    if(time[x][y] > finalEf){
                        time[x][y] = finalEf;
                        pq.push({time[x][y], x, y});
                    }
                }
            }
        }

        return time[n-1][m-1];
    }
};

