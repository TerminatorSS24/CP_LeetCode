/*You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1.

Return the size of the largest island in grid after applying this operation.

An island is a 4-directionally connected group of 1s.

 

Example 1:

Input: grid = [[1,0],[0,1]]
Output: 3
Explanation: Change one 0 to 1 and connect two 1s, then we get an island with area = 3.
Example 2:

Input: grid = [[1,1],[1,0]]
Output: 4
Explanation: Change the 0 to 1 and make the island bigger, only one island with area = 4.
Example 3:

Input: grid = [[1,1],[1,1]]
Output: 4
Explanation: Can't change any 0 to 1, only one island with area = 4.*/
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    bool isValid(int i, int j, int n)
    {
        return i >= 0 && i < n && j >= 0 && j < n;
    }

    void dfs(int i, int j, int n, vector<vector<int>>& grid, vector<vector<int>>& vis, int id)
    {
        if(i<0 || i==n || j<0 || j==n || grid[i][j]==0 || vis[i][j])
         return;

        grid[i][j] = id;
        vis[i][j] = 1;

        dfs(i-1,j,n,grid,vis,id);
        dfs(i,j+1,n,grid,vis,id);
        dfs(i+1,j,n,grid,vis,id);
        dfs(i,j-1,n,grid,vis,id);
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size(), id = 2, maxArea = 0;
        vector<vector<int>> vis(n,vector<int>(n,0));
        vector<vector<int>> directions = {{-1,0}, {0,1}, {1,0}, {0,-1}};
        unordered_map<int,int> area;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] == 1 && !vis[i][j])
                { 
                    dfs(i,j,n,grid,vis,id);
                    id++;
                }
            }
        }
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            { 
                area[grid[i][j]]++;
            }
        }
        area[0] = 0;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] == 0) 
                {
                    int curr = 1; 
                    unordered_map<int,bool> adj;

                    for(auto dir : directions)
                    {
                        int r = i + dir[0];
                        int c = j + dir[1];
                        if(isValid(r,c,n) && !adj[grid[r][c]]) 
                        { 
                            int ID = grid[r][c];
                            curr += area[ID]; //add their area
                            adj[ID] = 1;
                        }
                    }
                    maxArea = max(maxArea,curr); 
                }
            }
        }
        return (maxArea == 0) ? n*n : maxArea;
    }
};