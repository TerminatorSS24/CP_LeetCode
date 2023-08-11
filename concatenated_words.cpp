/*Given an array of strings words (without duplicates), return all the concatenated words in the given list of words.

A concatenated word is defined as a string that is comprised entirely of at least two shorter words (not necesssarily distinct) in the given array.

 

Example 1:

Input: words = ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]
Output: ["catsdogcats","dogcatsdog","ratcatdogcat"]
Explanation: "catsdogcats" can be concatenated by "cats", "dog" and "cats"; 
"dogcatsdog" can be concatenated by "dog", "cats" and "dog"; 
"ratcatdogcat" can be concatenated by "rat", "cat", "dog" and "cat".
Example 2:

Input: words = ["cat","dog","catdog"]
Output: ["catdog"]*/
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <functional> 

using namespace std;

class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> ans;
        int n = words.size();
        unordered_map<string, int> mp;
        for (auto it : words) mp[it] = 1;

        vector<int> dp;
        function<int(int, int, string)> f = [&](int i, int cnt, string s) {
            int N = s.size();
            if (i == N) return (int)(cnt >= 2);
            if (dp[i] != -1) return dp[i];

            string str = "";
            for (int j = i; j <= N - 1; j++) {
                str += s[j];
                bool ans;
                if (mp.find(str) != mp.end()) {
                    ans = f(j + 1, cnt + 1, s);
                }
                if (ans) return dp[i] = true;
            }
            return dp[i] = false;
        };

        for (auto it : words) {
            dp = vector<int>(it.size(), -1);
            if (f(0, 0, it)) ans.push_back(it);
        }
        return ans;
    }
};

