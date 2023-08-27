/*A frog is crossing a river. The river is divided into some number of units, and at each unit, there may or may not exist a stone. The frog can jump on a stone, but it must not jump into the water.

Given a list of stones' positions (in units) in sorted ascending order, determine if the frog can cross the river by landing on the last stone. Initially, the frog is on the first stone and assumes the first jump must be 1 unit.

If the frog's last jump was k units, its next jump must be either k - 1, k, or k + 1 units. The frog can only jump in the forward direction.

 

Example 1:

Input: stones = [0,1,3,5,6,8,12,17]
Output: true
Explanation: The frog can jump to the last stone by jumping 1 unit to the 2nd stone, then 2 units to the 3rd stone, then 2 units to the 4th stone, then 3 units to the 6th stone, 4 units to the 7th stone, and 5 units to the 8th stone.
Example 2:

Input: stones = [0,1,2,3,4,8,9,11]
Output: false
Explanation: There is no way to jump to the last stone as the gap between the 5th and 6th stone is too large.
**********LEETCODE POTD(27/08/2023)**********
*/
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    bool util(vector<int> &stones,int val,int end,int jump,vector<bool> &exists,map<pair<int,int>,bool> &dp) {
        if (val==end) return true;
        if (dp.find({val,jump})!=dp.end()) return dp[{val,jump}];
        bool less = false;
        if (exists[val] && (jump-1)>0 && (val+jump-1)<=end && exists[val+jump-1]) less = util(stones,val+jump-1,end,jump-1,exists,dp);
        bool more = false;
        if (exists[val] && (val+jump+1)<=end && exists[val+jump+1]) more = util(stones,val+jump+1,end,jump+1,exists,dp);
        bool cur = false;
        if (exists[val] && jump>0 && (val+jump)<=end && exists[val+jump]) cur = util(stones,val+jump,end,jump,exists,dp);
        return dp[{val,jump}] = (less | more | cur);
    }

    bool canCross(vector<int>& stones) {
        int j=stones[stones.size()-1];
        vector<bool> exists(j,false);
        map<pair<int,int>,bool> dp;
        for (int i=0; i<stones.size(); i++) {
            exists[stones[i]] = true;
        }
        return util(stones,1,j,1,exists,dp);
    }
};
