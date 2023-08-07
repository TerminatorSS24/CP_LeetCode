/*
You are given two integer arrays nums1 and nums2 of lengths m and n respectively. nums1 and nums2 represent the digits of two numbers. You are also given an integer k.

Create the maximum number of length k <= m + n from digits of the two numbers. The relative order of the digits from the same array must be preserved.

Return an array of the k digits representing the answer.

 

Example 1:

Input: nums1 = [3,4,6,5], nums2 = [9,1,2,5,8,3], k = 5
Output: [9,8,6,5,3]
Example 2:

Input: nums1 = [6,7], nums2 = [6,0,4], k = 5
Output: [6,7,6,0,4]
Example 3:

Input: nums1 = [3,9], nums2 = [8,9], k = 3
Output: [9,8,9]
*/
#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    vector<int> maxnum(vector<int> nums, int k){
        stack<int> st;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            while(!st.empty() && nums[st.top()] < nums[i] && n - i + st.size() > k) st.pop();
            if(st.size() < k) st.push(i);
        }
        vector<int> ans;
        while(!st.empty()) ans.push_back(nums[st.top()]), st.pop();
        reverse(ans.begin(), ans.end());
        return ans;
    }

    string merge(vector<int>& n1, vector<int>& n2, int k){
        vector<int> ans(k, 0);
         int i = 0, j = 0, x = 0;
            while(i < n1.size() && j < n2.size()){
                if(n2[j] > n1[i]) ans[x++] = n2[j], j++;
                else if(n2[j] == n1[i]){
                    int indi=i, indj=j;
                    while(indi < n1.size() && indj < n2.size() && n1[indi] == n2[indj]) indi++, indj++;
                    if(indj == n2.size()) ans[x++] = n1[i], i++;
                    else{
                        if(indi < n1.size() && n1[indi] > n2[indj]) ans[x++] = n1[i], i++;
                        else ans[x++] = n2[j], j++;
                    }
                }

                else ans[x++] = n1[i], i++; 
            }
            while(i < n1.size()) ans[x++] = n1[i], i++;
            while(j < n2.size()) ans[x++] = n2[j], j++;
            string s = "";
            for(auto it: ans) s += to_string(it);
            return s;
    }

    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size(), m = nums2.size();
        string mx = "";
        for(int i = 0; i <= k && i <= n; i++){
            if((k-i) > m) continue; 
            vector<int> n1 = maxnum(nums1, i);
            vector<int> n2 = maxnum(nums2, k-i);
            string s = merge(n1, n2, k);
            mx = max(mx, s);
        }
        vector<int> res;
        for(int i = 0; i < mx.size(); i++) res.push_back(mx[i] - '0');
        return res;
    }
};