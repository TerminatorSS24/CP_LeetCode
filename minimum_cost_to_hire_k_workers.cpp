/*There are n workers. You are given two integer arrays quality and wage where quality[i] is the quality of the ith worker and wage[i] is the minimum wage expectation for the ith worker.

We want to hire exactly k workers to form a paid group. To hire a group of k workers, we must pay them according to the following rules:

Every worker in the paid group should be paid in the ratio of their quality compared to other workers in the paid group.
Every worker in the paid group must be paid at least their minimum wage expectation.
Given the integer k, return the least amount of money needed to form a paid group satisfying the above conditions. Answers within 10-5 of the actual answer will be accepted.



Example 1:

Input: quality = [10,20,5], wage = [70,50,30], k = 2
Output: 105.00000
Explanation: We pay 70 to 0th worker and 35 to 2nd worker.
Example 2:

Input: quality = [3,1,10,10,1], wage = [4,8,2,2,7], k = 3
Output: 30.66667
Explanation: We pay 4 to 0th worker, 13.33333 to 2nd and 3rd workers separately.*/
#include <climits>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Solution
{
public:
    double mincostToHireWorkers(vector<int> &quality, vector<int> &wage, int k)
    {
        vector<pair<double, int>> avg(quality.size());
        for (int i = 0; i < quality.size(); i++)
        {
            double value = (double)wage[i] / quality[i];
            avg[i] = {value, i};
        }
        sort(avg.begin(), avg.end());
        double ans = INT_MAX;
        priority_queue<int> pq;
        double sum = 0;
        int i = 0;
        while (i < quality.size())
        {
            int indx = avg[i].second;
            if (pq.size() < k)
            {
                sum += quality[indx];
                pq.push(quality[indx]);
                if (pq.size() == k)
                {
                    double value = (double)sum * avg[i].first;
                    ans = min(ans, value);
                    double val = pq.top();
                    sum -= val;
                    pq.pop();
                }
            }
            i++;
        }
        return ans;
    }
};