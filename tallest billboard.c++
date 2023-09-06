/*You are installing a billboard and want it to have the largest height. The billboard will have two steel supports, one on each side. Each steel support must be an equal height.

You are given a collection of rods that can be welded together. For example, if you have rods of lengths 1, 2, and 3, you can weld them together to make a support of length 6.

Return the largest possible height of your billboard installation. If you cannot support the billboard, return 0.

 

Example 1:

Input: rods = [1,2,3,6]
Output: 6
Explanation: We have two disjoint subsets {1,2,3} and {6}, which have the same sum = 6.
Example 2:

Input: rods = [1,2,3,4,5,6]
Output: 10
Explanation: We have two disjoint subsets {2,3,5} and {4,6}, which have the same sum = 10.
Example 3:

Input: rods = [1,2]
Output: 0
Explanation: The billboard cannot be supported, so we return 0.*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int rec(int b, int i, vector<int>&r,vector<vector<int>>&d){
        if(i==r.size()){
            if(b==0) return 0;
            return -5000;
        }
        if(d[i][b+5000]!=-1) return d[i][b+5000];
        return d[i][b+5000]=max(r[i]+max(rec(b+r[i],i+1,r,d),rec(b-r[i],i+1,r,d)),rec(b,i+1,r,d));
    }
    int tallestBillboard(vector<int>& r) {
        vector<vector<int>>d(r.size()+1,vector<int>(10002,-1));
        return rec(0,0,r,d)/2;
    }
};
