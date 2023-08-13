/*Given a string n representing an integer, return the closest integer (not including itself), which is a palindrome. If there is a tie, return the smaller one.

The closest is defined as the absolute difference minimized between two integers.

 

Example 1:

Input: n = "123"
Output: "121"
Example 2:

Input: n = "1"
Output: "0"
Explanation: 0 and 2 are the closest palindromes but we return the smallest which is 0.*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool is9x(string s){
        int n = s.length();
        int count = 0;
        for(int i = 0; i < n; i++){
             if(s[i] == '9'){
                 count++;
             }
        }
        return count == n;
    }
    bool is10x(string s){
        int n = s.length();
        int count = 0;
        if(s[0] != '1'){
            return false;
        }
        for(int i = 1; i < n; i++){
             if(s[i] == '0'){
                 count++;
             }
        }
        return count == n-1;
    }
    bool is1x1(string s) {
        if (s[0] != '1' || s[s.size() - 1] != '1') 
            return false;
        
        for (int i = 1; i < s.size() - 1; ++i) {
            if (s[i] != '0') return false;
        }
        return true;
    }
    
    string getReverse(string s, bool odd) {
        if (odd) s.pop_back();
        for (int i = 0, j = s.size() - 1; i < j; ++i, --j)
            swap(s[i], s[j]);
        return s;
    }

    string nearestPalindromic(string s) {
        long long n = s.length();
        if(n == 1){
            if(s[0] == '0'){
                return "1";
            }
            long long x = stoll(s) - 1;
            return to_string(x);
        }
        if(is9x(s)){
            long long x = stoll(s) + 2;
            return to_string(x);
        }
        if(is10x(s)){
            long long x = stoll(s) - 1;
            return to_string(x);
        }
        if(is1x1(s)){
            long long x = stoll(s) - 2;
            return to_string(x);
        }
        long long half;
        //bitwise AND(&) it's checking odd or even;
        if(n & 1){
            half = stoll(s.substr(0,n/2+1));
        }else{
            half = stoll(s.substr(0,n/2));
        }
        long long great = stoll(to_string(half + 1) + getReverse(to_string(half + 1), n & 1));
        long long small = stoll(to_string(half - 1) + getReverse(to_string(half - 1), n & 1));
        long long equal = stoll(to_string(half) + getReverse(to_string(half), n & 1));
        
        long long minDiff = LLONG_MAX;
        long long res;
        if (stoll(s) - small < minDiff) {
            minDiff = stoll(s) - small;
            res = small;
        }
        if (stoll(s) != equal && abs(stoll(s) - equal) < minDiff) {
            minDiff = abs(stoll(s) - equal);
            res = equal;
        }
        if (great - stoll(s) < minDiff) {
            minDiff = great - stoll(s);
            res = great;
        }
        
        return to_string(res);
    }
};
