/*Along a long library corridor, there is a line of seats and decorative plants. You are given a 0-indexed string corridor of length n consisting of letters 'S' and 'P' where each 'S' represents a seat and each 'P' represents a plant.

One room divider has already been installed to the left of index 0, and another to the right of index n - 1. Additional room dividers can be installed. For each position between indices i - 1 and i (1 <= i <= n - 1), at most one divider can be installed.

Divide the corridor into non-overlapping sections, where each section has exactly two seats with any number of plants. There may be multiple ways to perform the division. Two ways are different if there is a position with a room divider installed in the first way but not in the second way.

Return the number of ways to divide the corridor. Since the answer may be very large, return it modulo 109 + 7. If there is no way, return 0.

 

Example 1:

image: https://assets.leetcode.com/uploads/2021/12/04/1.png

Input: corridor = "SSPPSPS"
Output: 3
Explanation: There are 3 different ways to divide the corridor.
The black bars in the above image indicate the two room dividers already installed.
Note that in each of the ways, each section has exactly two seats.
Example 2:

image: https://assets.leetcode.com/uploads/2021/12/04/2.png

Input: corridor = "PPSPSP"
Output: 1
Explanation: There is only 1 way to divide the corridor, by not installing any additional dividers.
Installing any would create some section that does not have exactly two seats.
Example 3:

image: https://assets.leetcode.com/uploads/2021/12/12/3.png

Input: corridor = "S"
Output: 0
Explanation: There is no way to divide the corridor because there will always be a section that does not have exactly two seats.
**********LEETCODE POTD(28/11/2023)**********
*/
#include <stdio.h>
#include <stdlib.h>
int dfs(int i, int count, int **cache, char *corridor, int n)
{
    const int Mod = 1e9 + 7;
    if (i == n)
        return (count == 2) ? 1 : 0;
    count += ((corridor[i] == 'S') ? 1 : 0);
    if (count > 2)
        return 0;
    if (cache[i][count] != -1)
        return cache[i][count];
    int result = dfs(i + 1, count, cache, corridor, n);
    if (count == 2)
    {
        result += dfs(i + 1, 0, cache, corridor, n);
        result %= Mod;
    }
    cache[i][count] = result;
    return result;
}
int numberOfWays(char *corridor)
{
    const int n = strlen(corridor);
    int **cache = (int **)calloc(n, sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        cache[i] = (int *)calloc(3, sizeof(int));
        for (int j = 0; j < 3; j++)
            cache[i][j] = -1;
    }
    int result = dfs(0, 0, cache, corridor, n);
    for (int i = 0; i < n; i++)
        free(cache[i]);
    free(cache);
    return result;
}