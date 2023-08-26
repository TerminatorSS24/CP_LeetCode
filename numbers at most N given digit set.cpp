/*Given an array of digits which is sorted in non-decreasing order. You can write numbers using each digits[i] as many times as we want. For example, if digits = ['1','3','5'], we may write numbers such as '13', '551', and '1351315'.

Return the number of positive integers that can be generated that are less than or equal to a given integer n.

 

Example 1:

Input: digits = ["1","3","5","7"], n = 100
Output: 20
Explanation: 
The 20 numbers that can be written are:
1, 3, 5, 7, 11, 13, 15, 17, 31, 33, 35, 37, 51, 53, 55, 57, 71, 73, 75, 77.
Example 2:

Input: digits = ["1","4","9"], n = 1000000000
Output: 29523
Explanation: 
We can write 3 one digit numbers, 9 two digit numbers, 27 three digit numbers,
81 four digit numbers, 243 five digit numbers, 729 six digit numbers,
2187 seven digit numbers, 6561 eight digit numbers, and 19683 nine digit numbers.
In total, this is 29523 integers that can be written using the digits array.
Example 3:

Input: digits = ["7"], n = 8
Output: 1*/
#include <iostream>
#include <vector>
#include <set>
#include <cstring>  

using namespace std;

class Solution {
public:
    set<int> st;
    int dp[10][2][2];
    
    int solve(string &s, int ind, int start, int tight) {
        if (ind >= s.size()) {
            return 1;
        }
        auto &res = dp[ind][start][tight];
        if (res != -1) return res;

        int ans = 0;
        if (start) {
            ans += solve(s, ind + 1, 1, 0);
        }

        int ub = tight ? (s[ind] - '0') : 9;

        for (auto i : st) {
            if (i <= ub)
                ans += solve(s, ind + 1, 0, tight & (i == ub));
        }

        return dp[ind][start][tight] = ans;
    }
    
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        for (auto i : digits) this -> st.insert(i[0] - '0');

        memset(dp, -1, sizeof dp);
        string r = to_string(n);
        return solve(r, 0, 1, 1) - 1;
    }
};
