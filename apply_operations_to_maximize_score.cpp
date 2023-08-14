/*You are given an array nums of n positive integers and an integer k.

Initially, you start with a score of 1. You have to maximize your score by applying the following operation at most k times:

Choose any non-empty subarray nums[l, ..., r] that you haven't chosen previously.
Choose an element x of nums[l, ..., r] with the highest prime score. If multiple such elements exist, choose the one with the smallest index.
Multiply your score by x.
Here, nums[l, ..., r] denotes the subarray of nums starting at index l and ending at the index r, both ends being inclusive.

The prime score of an integer x is equal to the number of distinct prime factors of x. For example, the prime score of 300 is 3 since 300 = 2 * 2 * 3 * 5 * 5.

Return the maximum possible score after applying at most k operations.

Since the answer may be large, return it modulo 109 + 7.

 

Example 1:

Input: nums = [8,3,9,3,8], k = 2
Output: 81
Explanation: To get a score of 81, we can apply the following operations:
- Choose subarray nums[2, ..., 2]. nums[2] is the only element in this subarray. Hence, we multiply the score by nums[2]. The score becomes 1 * 9 = 9.
- Choose subarray nums[2, ..., 3]. Both nums[2] and nums[3] have a prime score of 1, but nums[2] has the smaller index. Hence, we multiply the score by nums[2]. The score becomes 9 * 9 = 81.
It can be proven that 81 is the highest score one can obtain.
Example 2:

Input: nums = [19,12,14,6,10,18], k = 3
Output: 4788
Explanation: To get a score of 4788, we can apply the following operations: 
- Choose subarray nums[0, ..., 0]. nums[0] is the only element in this subarray. Hence, we multiply the score by nums[0]. The score becomes 1 * 19 = 19.
- Choose subarray nums[5, ..., 5]. nums[5] is the only element in this subarray. Hence, we multiply the score by nums[5]. The score becomes 19 * 18 = 342.
- Choose subarray nums[2, ..., 3]. Both nums[2] and nums[3] have a prime score of 2, but nums[2] has the smaller index. Hence, we multipy the score by nums[2]. The score becomes 342 * 14 = 4788.
It can be proven that 4788 is the highest score one can obtain.*/
#include <iostream>
#include <vector>
#include <stack>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    int primefactors(int t){
        int count = 0;
        int flag = 0;
        while(t % 2 == 0 && t > 0){
            t = t / 2;
            flag = 1;
        }
        if(flag == 1){
            count++;
        }
        flag = 0;
        
        for(int i = 3; i <= sqrt(t); i += 2){
            while(t % i == 0){
                t = t / i;
                flag = 1;
            }
            if(flag == 1){
                count++;
            }
            flag = 0;
        }
        if(t > 2){
            count++;
        }
        return count;
    }
    
    int mod = 1e9 + 7;
    long long power(int t, int x){
        long long res = 1;
        while(x > 0){
            if(x % 2 == 0){
                t = (long long)t * t % mod;
                x = x / 2;
            }
            else{
                res = res * t % mod;
                x -= 1;
            }
        }
        return res % mod;
    }
    
    vector<int> next1(vector<pair<int, int>> &nums){
        int n = nums.size();
        stack<pair<int, int>> s;
        vector<int> res(n);
        for(int i = n - 1; i >= 0; i--){
            while(!s.empty() && s.top().first <= nums[i].second){
                s.pop();
            }
            if(s.empty()){
                res[i] = n;
            }
            else{
                res[i] = s.top().second;
            }
            s.push({nums[i].second, i});
        }
        return res;
    }
    
    vector<int> previous(vector<pair<int, int>> &nums){
        int n = nums.size();
        stack<pair<int, int>> s;
        vector<int> res(n);
        for(int i = 0; i < n; i++){
            while(!s.empty() && s.top().first < nums[i].second){
                s.pop();
            }
            if(s.empty()){
                res[i] = -1;
            }
            else{
                res[i] = s.top().second;
            }
            s.push({nums[i].second, i});
        }
        return res;
    }
    
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        vector<pair<int, int>> v(n);
        for(int i = 0; i < nums.size(); i++){
            int x = primefactors(nums[i]);
            v[i] = {nums[i], x};
        }
        
        vector<int> prev = previous(v);
        vector<int> next = next1(v);
        
        long long score = 1;
        vector<vector<int>> v1(n);
        for(int i = 0; i < n; i++){
            v1[i] = {v[i].first, v[i].second, next[i], prev[i], i};
        }
        sort(v1.rbegin(), v1.rend());
        
        for(int i = 0; i < n; i++){
            int r = v1[i][2];
            int l = v1[i][3];
            int ind = v1[i][4];
            int impact = min(((ind - l) * (r - ind)), k);
            k -= impact;
            score = ((long long)score * ((long long)power(v1[i][0], impact) % mod)) % mod;
            if(k == 0){
                return score % mod;
            }
        }
        return score % mod;
    }
};