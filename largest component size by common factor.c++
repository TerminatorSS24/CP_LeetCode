/*You are given an integer array of unique positive integers nums. Consider the following graph:

There are nums.length nodes, labeled nums[0] to nums[nums.length - 1],
There is an undirected edge between nums[i] and nums[j] if nums[i] and nums[j] share a common factor greater than 1.
Return the size of the largest connected component in the graph.

 

Example 1:

image: https://assets.leetcode.com/uploads/2018/12/01/ex1.png

Input: nums = [4,6,15,35]
Output: 4
Example 2:

image: https://assets.leetcode.com/uploads/2018/12/01/ex2.png

Input: nums = [20,50,9,63]
Output: 2
Example 3:


image: https://assets.leetcode.com/uploads/2018/12/01/ex3.png
Input: nums = [2,3,6,7,4,12,21,39]
Output: 8*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>

using namespace std;

struct dsu{
    vector<int> par;
    vector<int> lvl;
    dsu(){
        par.resize(100001);
        iota(par.begin(), par.end(),0);
        lvl.assign(100001,0);
    }
    int get(int a){
        if(par[a]==a) return a;
        return get(par[a]);
    }
    void unite(int a, int b){
        a=get(a);
        b=get(b);
        if(a==b) return;
        if(lvl[a]<lvl[b]){
            swap(a,b);
        }
        if(lvl[a]==lvl[b]) lvl[a]++;
        par[b]=a;
        return ;
    }
};

class Solution {
public:
    vector<int> primefactors(int n){
        vector<int> v;
        for(int i=2; i*i<=n; i++){
            if(n%i==0){
                while(n%i==0){
                    n=n/i;
                }
                v.push_back(i);
            }
        }
        if(n>1) v.push_back(n);
        return v;
    }
    int largestComponentSize(vector<int>& nums) {
        dsu graph;
        int groups=0;
        for(auto u: nums){
            if(u==1){
                groups=1;
                continue;
            }
            vector<int> v=primefactors(u);
            int n=v.size();
            for(int i=0; i<n; i++){
                for(int j=i+1; j<n; j++){
                    graph.unite(v[i],v[j]);
                }
            }
        }
        map<int,int> mp;
        for(auto u: nums){
            if(u==1) continue;
            vector<int> v=primefactors(u);
            int k=graph.get(v[0]);
            mp[k]++;
            groups=max(groups, mp[k]);
        }
        return groups;
    }
};
