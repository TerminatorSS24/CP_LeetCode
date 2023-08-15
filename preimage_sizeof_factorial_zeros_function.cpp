/*Let f(x) be the number of zeroes at the end of x!. Recall that x! = 1 * 2 * 3 * ... * x and by convention, 0! = 1.

For example, f(3) = 0 because 3! = 6 has no zeroes at the end, while f(11) = 2 because 11! = 39916800 has two zeroes at the end.
Given an integer k, return the number of non-negative integers x have the property that f(x) = k.

 

Example 1:

Input: k = 0
Output: 5
Explanation: 0!, 1!, 2!, 3!, and 4! end with k = 0 zeroes.
Example 2:

Input: k = 5
Output: 0
Explanation: There is no x such that x! ends in k = 5 zeroes.
Example 3:

Input: k = 3
Output: 5*/
#include <iostream>

using namespace std;

#define ll long long

class Solution {
public:
    ll count(ll n) {
        ll cnt = 0;
        while (n >= 5) {
            cnt += n / 5;
            n /= 5;
        }
        return cnt;
    }

    int preimageSizeFZF(int k) {
        ll x_low = 0, x_high = 1e10;
        while (x_low <= x_high) {
            ll mid = x_low + (x_high - x_low) / 2;
            ll res = count(mid);
            if (res == k) {
                return 5;
            } else if (res > k) {
                x_high = mid - 1;
            } else {
                x_low = mid + 1;
            }
        }
        return 0;
    }
};