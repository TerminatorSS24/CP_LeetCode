/*
Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.

Return the sorted string. If there are multiple answers, return any of them.

 

Example 1:

Input: s = "tree"
Output: "eert"
Explanation: 'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input: s = "cccaaa"
Output: "aaaccc"
Explanation: Both 'c' and 'a' appear three times, so both "cccaaa" and "aaaccc" are valid answers.
Note that "cacaca" is incorrect, as the same characters must be together.
Example 3:

Input: s = "Aabb"
Output: "bbAa"
Explanation: "bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.
**********LEETCODE POTD(07/02/2024)**********
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:    
    static bool chal(pair<char,int> p1,pair<char,int> p2)
    {
        return p1.second>p2.second;   
    }
    
    string frequencySort(string s) 
    {
        string ans="";

        unordered_map<char,int> mp;
        vector<pair<char,int>> v1;
        
        for(auto c:s) mp[c]++;
        
        for(auto x:mp) v1.push_back(make_pair(x.first,x.second));
        
        sort(v1.begin(),v1.end(),chal);
        
        for(auto x:v1)
        {
            int temp=x.second;
            while(temp--)
                ans+=x.first;
        }
        return ans;
    }
};