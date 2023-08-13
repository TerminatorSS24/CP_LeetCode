/*Given a positive integer n, return the number of the integers in the range [0, n] whose binary representations do not contain consecutive ones.

 

Example 1:

Input: n = 5
Output: 5
Explanation:
Here are the non-negative integers <= 5 with their corresponding binary representations:
0 : 0
1 : 1
2 : 10
3 : 11
4 : 100
5 : 101
Among them, only integer 3 disobeys the rule (two consecutive ones) and the other 5 satisfy the rule. 
Example 2:

Input: n = 1
Output: 2
Example 3:

Input: n = 2
Output: 3*/
#include <iostream>
#include <string>
#include <bitset>
#include <cmath>
#include <cstring>

using namespace std;

class Solution {
public:
    int dp[2][2][33] ;

    int f(int i, int prev, int constraint, string &s) {
        int n = s.size();
        if (i >= n)
            return 1 ;

        if (dp[prev][constraint][i] != -1)
            return dp[prev][constraint][i] ;

        int answer = 0 ;
        int ub = constraint ? s[i] - '0' : 1 ;

        for (int x = 0; x <= ub; x++) {
            if (prev == 1) {
                if (x == 0)
                    answer += f(i+1, x, (constraint && (x == ub)), s);
            }
            else {
                answer += f(i+1, x, (constraint && (x == ub)), s);
            }
        }
        return dp[prev][constraint][i] = answer ;
    }

    int findIntegers(int n) {
        bitset<32> b(n);
        string st = b.to_string();
        int sz = log2(n) + 1;
        string s;

        for (int i = 32 - sz; i < 32; i++) {
            s.push_back(st[i]);
        }
        
        memset(dp, -1, sizeof dp);
        int ans = f(0, 0, 1, s);
        return ans;
    }
};