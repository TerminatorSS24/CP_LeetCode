// Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].

// You may return the answer in any order.

 

// Example 1:

// Input: n = 4, k = 2
// Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
// Explanation: There are 4 choose 2 = 6 total combinations.
// Note that combinations are unordered, i.e., [1,2] and [2,1] are considered to be the same combination.
// Example 2:

// Input: n = 1, k = 1
// Output: [[1]]
// Explanation: There is 1 choose 1 = 1 total combination.
//**********LEETCODE POTD(01/08/2023)**********
#include<vector>

class Solution {
public:
    
    void solve(int n, int k, int num, vector<int> &sub_ans, vector<vector<int>> &ans){
        if(k==0){
            ans.push_back(sub_ans);
            return;
        }
        if(num == n+1) return;
        
        // skip
        solve(n,k,num+1,sub_ans,ans);
        
        // acquire
        sub_ans.push_back(num);
        solve(n,k-1,num+1,sub_ans,ans);
        sub_ans.pop_back();
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> sub_ans;
        
        solve(n,k,1,sub_ans,ans);
        
        return ans;
    }
};