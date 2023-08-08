/*
You are given a list of airline tickets where tickets[i] = [fromi, toi] represent the departure and the arrival airports of one flight. Reconstruct the itinerary in order and return it.

All of the tickets belong to a man who departs from "JFK", thus, the itinerary must begin with "JFK". If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string.

For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
You may assume all tickets form at least one valid itinerary. You must use all the tickets once and only once.

 

Example 1:

image: https://assets.leetcode.com/uploads/2021/03/14/itinerary1-graph.jpg

Input: tickets = [["MUC","LHR"],["JFK","MUC"],["SFO","SJC"],["LHR","SFO"]]
Output: ["JFK","MUC","LHR","SFO","SJC"]
Example 2:

image: https://assets.leetcode.com/uploads/2021/03/14/itinerary2-graph.jpg

Input: tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
Output: ["JFK","ATL","JFK","SFO","ATL","SFO"]
Explanation: Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"] but it is larger in lexical order.
*/
#include <iostream>
#include <vector>
#include <string.h>
#include <stack>
#include <map>
#include <queue>
#include <algorithm>
 class Solution {
public:
    vector<string> ans;
    stack<string> s;
    map<string, queue<string>> adj;
    
    void hierthing(string &src){
        s.push(src);
        while (!adj[src].empty()){
            string v = adj[src].front();
            adj[src].pop();
            hierthing(v);
        }
        
        ans.push_back(s.top());
        s.pop();
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        sort(tickets.begin(), tickets.end());
        
        for (auto trip: tickets){
            adj[trip[0]].push(trip[1]);
        }
        
        string s = "JFK";
        hierthing(s);

        reverse(ans.begin(), ans.end());
        return ans;
    }
};