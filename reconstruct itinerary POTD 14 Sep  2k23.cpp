/*You are given a list of airline tickets where tickets[i] = [fromi, toi] represent the departure and the arrival airports of one flight. Reconstruct the itinerary in order and return it.

All of the tickets belong to a man who departs from "JFK", thus, the itinerary must begin with "JFK". If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string.

For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
You may assume all tickets form at least one valid itinerary. You must use all the tickets once and only once.

 

Example 1:

image: https://assets.leetcode.com/uploads/2021/03/14/itinerary1-graph.jpg

Input: tickets = [["MUC","LHR"],["JFK","MUC"],["SFO","SJC"],["LHR","SFO"]]
Output: ["JFK","MUC","LHR","SFO","SJC"]
Example 2:

image: 

Input: tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
Output: ["JFK","ATL","JFK","SFO","ATL","SFO"]
Explanation: Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"] but it is larger in lexical order.
**********LEETCODE POTD(14/09/2023)**********
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> outdegree;

    void recursion(vector<string>& res, string departure) {
        while (!outdegree[departure].empty()) {
            string top = outdegree[departure].top();
            outdegree[departure].pop();
            recursion(res, top);
        }
        res.push_back(departure);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        
        int n = tickets.size();
        for (int i = 0; i < n; i++) {
            outdegree[tickets[i][0]].push(tickets[i][1]);
        }
        vector<string> res; 
        recursion(res, "JFK");
        reverse(res.begin(),  res.end());
        return res;
    }
};