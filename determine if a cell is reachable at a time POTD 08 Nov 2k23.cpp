/*You are given four integers sx, sy, fx, fy, and a non-negative integer t.

In an infinite 2D grid, you start at the cell (sx, sy). Each second, you must move to any of its adjacent cells.

Return true if you can reach cell (fx, fy) after exactly t seconds, or false otherwise.

A cell's adjacent cells are the 8 cells around it that share at least one corner with it. You can visit the same cell several times.

 

Example 1:

image: https://assets.leetcode.com/uploads/2023/08/05/example2.svg

Input: sx = 2, sy = 4, fx = 7, fy = 7, t = 6
Output: true
Explanation: Starting at cell (2, 4), we can reach cell (7, 7) in exactly 6 seconds by going through the cells depicted in the picture above. 
Example 2:

image: https://assets.leetcode.com/uploads/2023/08/05/example1.svg

Input: sx = 3, sy = 1, fx = 7, fy = 3, t = 3
Output: false
Explanation: Starting at cell (3, 1), it takes at least 4 seconds to reach cell (7, 3) by going through the cells depicted in the picture above. Hence, we cannot reach cell (7, 3) at the third second.
**********LEETCODE POTD(08/11/2023)**********
*/
#include <iostream>
#include <cmath>
using namespace std;
class Solution
{
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t)
    {
        int x = abs(fx - sx);
        int y = abs(fy - sy);
        if (x == 0 && y == 0 && t == 1)
            return false;
        if (max(x, y) <= t)
            return true;
        return false;
    }
};