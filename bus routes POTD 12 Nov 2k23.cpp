/*You are given an array routes representing bus routes where routes[i] is a bus route that the ith bus repeats forever.

For example, if routes[0] = [1, 5, 7], this means that the 0th bus travels in the sequence 1 -> 5 -> 7 -> 1 -> 5 -> 7 -> 1 -> ... forever.
You will start at the bus stop source (You are not on any bus initially), and you want to go to the bus stop target. You can travel between bus stops by buses only.

Return the least number of buses you must take to travel from source to target. Return -1 if it is not possible.

 

Example 1:

Input: routes = [[1,2,7],[3,6,7]], source = 1, target = 6
Output: 2
Explanation: The best strategy is take the first bus to the bus stop 7, then take the second bus to the bus stop 6.
Example 2:

Input: routes = [[7,12],[4,5,15],[6],[15,19],[9,12,13]], source = 15, target = 12
Output: -1
**********LEETCODE POTD(12/11/2023)**********
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;
class Solution
{
public:
    int numBusesToDestination(vector<vector<int>> &routes, int source, int target)
    {
        if (source == target)
            return 0;
        int n = routes.size();
        unordered_map<int, int> vis;
        queue<int> q;
        unordered_map<int, int> route;
        unordered_map<int, vector<int>> graph;
        unordered_map<int, vector<int>> bus;
        int ct = 0;
        for (auto it : routes)
        {
            for (auto ty : it)
            {
                graph[ty].push_back(ct);
                bus[ct].push_back(ty);
            }
            ct++;
        }
        for (auto it : graph[source])
            q.push(it);
        ct = 1;
        while (!q.empty())
        {
            int sz = q.size();
            for (int i = 0; i < sz; i++)
            {
                int x = q.front();
                q.pop();
                for (auto it : bus[x])
                {
                    if (it == target)
                        return ct;
                    if (route[it] == 0)
                    {
                        route[it]++;
                        for (auto ty : graph[it])
                        {
                            if (!vis[ty])
                            {
                                vis[ty]++;
                                q.push(ty);
                            }
                        }
                    }
                }
            }
            ct++;
        }
        return -1;
    }
};
