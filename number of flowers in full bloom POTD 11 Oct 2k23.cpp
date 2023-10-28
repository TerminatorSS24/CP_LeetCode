/*You are given a 0-indexed 2D integer array flowers, where flowers[i] = [starti, endi] means the ith flower will be in full bloom from starti to endi (inclusive). You are also given a 0-indexed integer array people of size n, where people[i] is the time that the ith person will arrive to see the flowers.

Return an integer array answer of size n, where answer[i] is the number of flowers that are in full bloom when the ith person arrives.

 

Example 1:

image : https://assets.leetcode.com/uploads/2022/03/02/ex1new.jpg

Input: flowers = [[1,6],[3,7],[9,12],[4,13]], people = [2,3,7,11]
Output: [1,2,2,2]
Explanation: The figure above shows the times when the flowers are in full bloom and when the people arrive.
For each person, we return the number of flowers in full bloom during their arrival.
Example 2:

image: https://assets.leetcode.com/uploads/2022/03/02/ex2new.jpg

Input: flowers = [[1,10],[3,3]], people = [3,3,2]
Output: [2,2,1]
Explanation: The figure above shows the times when the flowers are in full bloom and when the people arrive.
For each person, we return the number of flowers in full bloom during their arrival.
**********LEETCODE POTD(11/10/2023)**********
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>&> flowers, vector<int>& people) {
        vector<int> start;
        vector<int> end, ans;

        for (int i = 0; i < flowers.size(); i++) {
            start.push_back(flowers[i][0]);
            end.push_back(flowers[i][1]);
        }

        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        for (int i = 0; i < people.size(); i++) {
            int starti, endi;
            starti = upper_bound(start.begin(), start.end(), people[i]) - start.begin();
            endi = lower_bound(end.begin(), end.end(), people[i]) - end.begin();

            int cnt = starti - endi;

            ans.push_back(cnt);
        }
        return ans;
    }
};