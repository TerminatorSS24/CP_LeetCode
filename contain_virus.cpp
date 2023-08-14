/*A virus is spreading rapidly, and your task is to quarantine the infected area by installing walls.

The world is modeled as an m x n binary grid isInfected, where isInfected[i][j] == 0 represents uninfected cells, and isInfected[i][j] == 1 represents cells contaminated with the virus. A wall (and only one wall) can be installed between any two 4-directionally adjacent cells, on the shared boundary.

Every night, the virus spreads to all neighboring cells in all four directions unless blocked by a wall. Resources are limited. Each day, you can install walls around only one region (i.e., the affected area (continuous block of infected cells) that threatens the most uninfected cells the following night). There will never be a tie.

Return the number of walls used to quarantine all the infected regions. If the world will become fully infected, return the number of walls used.

 

Example 1:

image: https://assets.leetcode.com/uploads/2021/06/01/virus11-grid.jpg

Input: isInfected = [[0,1,0,0,0,0,0,1],[0,1,0,0,0,0,0,1],[0,0,0,0,0,0,0,1],[0,0,0,0,0,0,0,0]]
Output: 10
Explanation: There are 2 contaminated regions.
On the first day, add 5 walls to quarantine the viral region on the left. The board after the virus spreads is:

image: https://assets.leetcode.com/uploads/2021/06/01/virus12edited-grid.jpg

On the second day, add 5 walls to quarantine the viral region on the right. The virus is fully contained.

image: https://assets.leetcode.com/uploads/2021/06/01/virus13edited-grid.jpg

Example 2:

image: https://assets.leetcode.com/uploads/2021/06/01/virus2-grid.jpg

Input: isInfected = [[1,1,1],[1,0,1],[1,1,1]]
Output: 4
Explanation: Even though there is only one cell saved, there are 4 walls built.
Notice that walls are only built on the shared boundary of two different cells.
Example 3:

Input: isInfected = [[1,1,1,0,0,0,0,0,0],[1,0,1,0,1,1,1,1,1],[1,1,1,0,0,0,0,0,0]]
Output: 13
Explanation: The region on the left only builds two new walls.*/
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class Solution {
    int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    int getInfectionCount(vector<vector<int>>& grid, vector<vector<int>>& isVis, vector<pair<int, int>>& areaCells, int areaCode, int i, int j) {
        if (i < 0 or j < 0 or i >= grid.size() or j >= grid[0].size() or isVis[i][j] == areaCode or grid[i][j] == 2) {
            return 0;
        }

        isVis[i][j] = areaCode;
        if (grid[i][j] == 0) {
            return 1;
        }

        areaCells.push_back({i, j});

        int infectedCellsCount = 0;
        for (int d = 0; d < 4; d++) {
            infectedCellsCount += getInfectionCount(grid, isVis, areaCells, areaCode, i + dir[d][0], j + dir[d][1]);
        }

        return infectedCellsCount;
    }

    int infectAndGetWallCount(vector<vector<int>>& grid, vector<pair<int, int>>& areaCells, bool infect) {
        int wallCount = 0;

        for (auto[i, j] : areaCells) {
            if (!infect) {
                grid[i][j] = 2;
            }
            for (int d = 0; d < 4; d++) {
                int ii = i + dir[d][0];
                int jj = j + dir[d][1];

                if (ii < 0 or jj < 0 or ii >= grid.size() or jj >= grid[0].size()) continue;

                if (grid[ii][jj] == 0) {
                    if (infect) {
                        grid[ii][jj] = 1;
                    }
                    else {
                        wallCount++;
                    }
                }
            }
        }

        return wallCount;
    }

public:
    int containVirus(vector<vector<int>>& isInfected) {
        int m = isInfected.size(), n = isInfected[0].size(), totalWalls = 0;

        while (true) {
            int maxInfectionCount = 0, maxArea = -1;
            vector<vector<pair<int, int>>> areas;
            vector<vector<int>> isVis(m, vector<int>(n, 0));
            int areaCode = 1;

            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (isInfected[i][j] == 1 and isVis[i][j] == 0) {
                        vector<pair<int, int>> areaCells;
                        int infectionCount = getInfectionCount(isInfected, isVis, areaCells, areaCode, i, j);
                        areaCode++;

                        if (infectionCount > maxInfectionCount) {
                            maxInfectionCount = infectionCount;
                            maxArea = areas.size();
                        }
                        areas.push_back(areaCells);
                    }
                }
            }

            if (maxArea == -1) break;

            totalWalls += infectAndGetWallCount(isInfected, areas[maxArea], false);
            for (int i = 0; i < areas.size(); i++) {
                if (i == maxArea) continue;
                infectAndGetWallCount(isInfected, areas[i], true);
            }
        }

        return totalWalls;
    }
};