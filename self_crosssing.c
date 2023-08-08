/*
You are given an array of integers distance.

You start at the point (0, 0) on an X-Y plane, and you move distance[0] meters to the north, then distance[1] meters to the west, distance[2] meters to the south, distance[3] meters to the east, and so on. In other words, after each move, your direction changes counter-clockwise.

Return true if your path crosses itself or false if it does not.

 

Example 1:

image: https://assets.leetcode.com/uploads/2022/12/21/11.jpg

Input: distance = [2,1,1,2]
Output: true
Explanation: The path crosses itself at the point (0, 1).
Example 2:

image: https://assets.leetcode.com/uploads/2022/12/21/22.jpg

Input: distance = [1,2,3,4]
Output: false
Explanation: The path does not cross itself at any point.
Example 3:

image: https://assets.leetcode.com/uploads/2022/12/21/33.jpg

Input: distance = [1,1,1,2,1]
Output: true
Explanation: The path crosses itself at the point (0, 0).
*/
#include <stdio.h>
#include <stdbool.h>
bool isSelfCrossing(int* distance, int distanceSize) {
    if (distanceSize < 4) {
        return false;
    }

    for (int i = 3; i < distanceSize; i++) {
        if (distance[i] >= distance[i - 2] && distance[i - 1] <= distance[i - 3]) {
            return true;
        }
        if (i >= 4 && distance[i - 1] == distance[i - 3] && distance[i] + distance[i - 4] >= distance[i - 2]) {
            return true;
        }
        if (i >= 5 && distance[i - 2] >= distance[i - 4] && distance[i] + distance[i - 4] >= distance[i - 2] &&
            distance[i - 1] <= distance[i - 3] && distance[i - 1] + distance[i - 5] >= distance[i - 3]) {
            return true;
        }
    }

    return false;
}
