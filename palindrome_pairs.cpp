/*
You are given a 0-indexed array of unique strings words.

A palindrome pair is a pair of integers (i, j) such that:

0 <= i, j < words.length,
i != j, and
words[i] + words[j] (the concatenation of the two strings) is a 
palindrome
.
Return an array of all the palindrome pairs of words.

 

Example 1:

Input: words = ["abcd","dcba","lls","s","sssll"]
Output: [[0,1],[1,0],[3,2],[2,4]]
Explanation: The palindromes are ["abcddcba","dcbaabcd","slls","llssssll"]
Example 2:

Input: words = ["bat","tab","cat"]
Output: [[0,1],[1,0]]
Explanation: The palindromes are ["battab","tabbat"]
Example 3:

Input: words = ["a",""]
Output: [[0,1],[1,0]]
Explanation: The palindromes are ["a","a"]
*/
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <map>
class Solution {
public:
    inline bool isPalindrome(const string &s, int l, int r) {
        while(l < r && s[l] == s[r]) {
            l++;
            r--;
        }
        return l >= r;
    }
    
    vector<vector<int>> palindromePairs(vector<string>& words) {
        map<int, unordered_map<string, int>> mm;
        for(int i=0; i<words.size(); i++) {
            mm[words[i].size()][string(words[i].rbegin(), words[i].rend())] = i;
        }
        
        vector<vector<int>> res;
        for(int i=0; i < words.size(); i++) {
            auto w = words[i];
            
            for(auto & [k, m] : mm) {
                if (k > w.size()) break;
                if (k == w.size()) {
                    if (m.count(w) && m[w] != i) {
                        res.push_back({i, m[w]});
                    }
                    break;
                }
                if (isPalindrome(w, k, w.size() - 1)) {
                    auto tgt = w.substr(0, k);
                    if (m.count(tgt)) {
                        res.push_back({i, m[tgt]});
                    }
                }
                if (isPalindrome(w, 0, w.size() - k - 1)) {
                    auto tgt = w.substr(w.size() - k);
                    if (m.count(tgt)) {
                        res.push_back({m[tgt], i});
                    }
                }
            }
        }

        return res;
    }
};
