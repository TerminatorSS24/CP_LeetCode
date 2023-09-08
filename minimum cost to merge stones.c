/*There are n piles of stones arranged in a row. The ith pile has stones[i] stones.

A move consists of merging exactly k consecutive piles into one pile, and the cost of this move is equal to the total number of stones in these k piles.

Return the minimum cost to merge all piles of stones into one pile. If it is impossible, return -1.



Example 1:

Input: stones = [3,2,4,1], k = 2
Output: 20
Explanation: We start with [3, 2, 4, 1].
We merge [3, 2] for a cost of 5, and we are left with [5, 4, 1].
We merge [4, 1] for a cost of 5, and we are left with [5, 5].
We merge [5, 5] for a cost of 10, and we are left with [10].
The total cost was 20, and this is the minimum possible.
Example 2:

Input: stones = [3,2,4,1], k = 3
Output: -1
Explanation: After any merge operation, there are 2 piles left, and we can't merge anymore.  So the task is impossible.
Example 3:

Input: stones = [3,5,1,2,6], k = 3
Output: 25
Explanation: We start with [3, 5, 1, 2, 6].
We merge [5, 1, 2] for a cost of 8, and we are left with [3, 8, 6].
We merge [3, 8, 6] for a cost of 17, and we are left with [17].
The total cost was 25, and this is the minimum possible.*/
#include <stdio.h>
#define MAXCOUNT 30
int mergeStones(int *stones, int stonesSize, int k)
{
    if ((stonesSize - 1) % (k - 1) != 0)
        return -1;

    int sum = 0;
    int i;
    int j;
    int dp[MAXCOUNT][MAXCOUNT] = {0};
    int sumarr[MAXCOUNT + 1] = {0};

    for (i = 0; i < stonesSize; i++)
        sum = sumarr[i] = sum + stones[i];

    for (i = 0; i < stonesSize; i++)
    {
        j = i + k - 1;
        if (j < stonesSize)
        {
            dp[i][j] = sumarr[j];
            if (i > 0)
                dp[i][j] -= sumarr[i - 1];
        }
    }

    for (int p = 0; p < (stonesSize - k); p++)
        for (i = 0, j = k + p; j < stonesSize; i++, j++)
        {
            dp[i][j] = 0x7FFFFFFF;

            for (int mid = i; mid < j; mid += (k - 1))
            {
                int res = dp[i][mid] + dp[mid + 1][j];
                dp[i][j] = (res < dp[i][j]) ? res : dp[i][j];
            }

            if ((j - i) % (k - 1) == 0)
            {
                dp[i][j] += (sumarr[j]);
                if (i > 0)
                    dp[i][j] -= sumarr[i - 1];
            }
        }

    return dp[0][stonesSize - 1];
}