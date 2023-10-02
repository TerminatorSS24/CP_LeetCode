/*There is a 1 million by 1 million grid on an XY-plane, and the coordinates of each grid square are (x, y).

We start at the source = [sx, sy] square and want to reach the target = [tx, ty] square. There is also an array of blocked squares, where each blocked[i] = [xi, yi] represents a blocked square with coordinates (xi, yi).

Each move, we can walk one square north, east, south, or west if the square is not in the array of blocked squares. We are also not allowed to walk outside of the grid.

Return true if and only if it is possible to reach the target square from the source square through a sequence of valid moves.

 

Example 1:

Input: blocked = [[0,1],[1,0]], source = [0,0], target = [0,2]
Output: false
Explanation: The target square is inaccessible starting from the source square because we cannot move.
We cannot move north or east because those squares are blocked.
We cannot move south or west because we cannot go outside of the grid.
Example 2:

Input: blocked = [], source = [0,0], target = [999999,999999]
Output: true
Explanation: Because there are no blocked cells, it is possible to reach the target square.*/
#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;
class Solution
{
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};
    bool solve(int x, int y, vector<int> &last, unordered_set<long long> &isBlocked)
    {
        queue<long long> q;
        unordered_set<long long> vis;
        q.push(x * 1e6 + y);
        vis.insert(x * 1e6 + y);
        int dis = 0;
        while (!q.empty())
        {
            int size = q.size();
            while (size--)
            {
                long long curr = q.front();
                q.pop();

                int row = curr / 1e6, col = curr % 1000000;

                // if we can cross 200 cells or we have reached our destination cell
                if (dis >= 200 || (row == last[0] && col == last[1]))
                    return true;

                for (int k = 0; k < 4; k++)
                {
                    int i = row + dx[k];
                    int j = col + dy[k];
                    long long currCell = i * 1e6 + j;
                    if (i >= 0 && i < 1e6 && j >= 0 && j < 1e6 && (vis.find(currCell) == vis.end()) && (isBlocked.find(currCell) == isBlocked.end()))
                    {
                        q.push(currCell);
                        vis.insert(currCell);
                    }
                }
            }
            dis++;
        }
        return false;
    }

public:
    bool isEscapePossible(vector<vector<int>> &blocked, vector<int> &source, vector<int> &target)
    {
        if (blocked.size() == 0) // edge case
            return true;
        unordered_set<long long> isBlocked;
        for (auto it : blocked)
        {
            isBlocked.insert(it[0] * 1e6 + it[1]);
        }
        return solve(source[0], source[1], target, isBlocked) && solve(target[0], target[1], source, isBlocked);
    }
};