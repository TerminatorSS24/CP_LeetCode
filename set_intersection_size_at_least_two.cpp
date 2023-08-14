/*You are given a 2D integer array intervals where intervals[i] = [starti, endi] represents all the integers from starti to endi inclusively.

A containing set is an array nums where each interval from intervals has at least two integers in nums.

For example, if intervals = [[1,3], [3,7], [8,9]], then [1,2,4,7,8,9] and [2,3,4,8,9] are containing sets.
Return the minimum possible size of a containing set.

 

Example 1:

Input: intervals = [[1,3],[3,7],[8,9]]
Output: 5
Explanation: let nums = [2, 3, 4, 8, 9].
It can be shown that there cannot be any containing array of size 4.
Example 2:

Input: intervals = [[1,3],[1,4],[2,5],[3,5]]
Output: 3
Explanation: let nums = [2, 3, 4].
It can be shown that there cannot be any containing array of size 2.
Example 3:

Input: intervals = [[1,2],[2,3],[2,4],[4,5]]
Output: 5
Explanation: let nums = [1, 2, 3, 4, 5].
It can be shown that there cannot be any containing array of size 4.*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    static bool compare(vector<int>& a, vector<int>& b) {
        if (a[1] == b[1]) return a[0] < b[0];
        else return a[1] < b[1];
    }

    int intersectionSizeTwo(vector<vector<int>>& inter) {
        int n = inter.size();

        sort(inter.begin(), inter.end(), compare);
        vector<int> res;

        res.push_back(inter[0][1] - 1);
        res.push_back(inter[0][1]);

        for (int i = 1; i < n; i++) {
            int strt = inter[i][0];
            int end = inter[i][1];

            if (strt > res.back()) {
                res.push_back(end - 1);
                res.push_back(end);
            }
            else if (strt == res.back()) {
                res.push_back(end);
            }
            else if (strt > res[res.size() - 2]) {
                res.push_back(end);
            }
        }
        return res.size();
    }
};
