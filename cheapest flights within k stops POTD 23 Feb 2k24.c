/*
There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.

You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.



Example 1:

image:https://assets.leetcode.com/uploads/2022/03/18/cheapest-flights-within-k-stops-3drawio.png

Input: n = 4, flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], src = 0, dst = 3, k = 1
Output: 700
Explanation:
The graph is shown above.
The optimal path with at most 1 stop from city 0 to 3 is marked in red and has cost 100 + 600 = 700.
Note that the path through cities [0,1,2,3] is cheaper but is invalid because it uses 2 stops.
Example 2:

image: https://assets.leetcode.com/uploads/2022/03/18/cheapest-flights-within-k-stops-1drawio.png

Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 1
Output: 200
Explanation:
The graph is shown above.
The optimal path with at most 1 stop from city 0 to 2 is marked in red and has cost 100 + 100 = 200.
Example 3:

image:https://assets.leetcode.com/uploads/2022/03/18/cheapest-flights-within-k-stops-2drawio.png

Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 0
Output: 500
Explanation:
The graph is shown above.
The optimal path with no stops from city 0 to 2 is marked in red and has cost 500.
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <climits.h>

#define INF (INT_MAX >> 2)

int findCheapestPrice(int n, int **flights, int flightsSize, int *flightsColSize, int src, int dst, int k)
{
    int *dist = (int *)malloc(n * sizeof(int));
    int *dist_temp = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        dist[i] = INF;
        dist_temp[i] = INF;
    }
    dist[src] = 0;
    for (int k_iter = 0; k_iter <= k; k_iter++)
    {
        memcpy(&dist_temp[0], &dist[0], n * sizeof(int));
        for (int i = 0; i < flightsSize; i++)
        {
            int from = flights[i][0];
            int to = flights[i][1];
            int price = flights[i][2];

            if (dist_temp[to] > dist[from] + price && dist[from] != INF)
                dist_temp[to] = dist[from] + price;
        }

        memcpy(&dist[0], &dist_temp[0], n * sizeof(int));

        for (int i = 0; i < n; i++)
            if (dist[i] != INF && dist[i] < dist_temp[i])
                return -1;
    }

    int ret = dist[dst];
    free(dist);
    free(dist_temp);
    if (ret == INF)
        return -1;
    return ret;
}