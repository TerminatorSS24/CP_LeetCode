/*A positive integer is magical if it is divisible by either a or b.

Given the three integers n, a, and b, return the nth magical number. Since the answer may be very large, return it modulo 109 + 7.

Example 1:

Input: n = 1, a = 2, b = 3
Output: 2

Example 2:

Input: n = 4, a = 2, b = 3
Output: 6*/
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        const int m = 1e9 + 7;
        long long g = __gcd(a, b);
        long long l = (a * b) / g;
        auto check = [&](long long mid) {
            long long x = mid / a, y = mid / b;
            long long k = x + y - (mid / l);
            return k < n;
        };

        long long low = 1, high = 1e18, ans = 1;
        while (low <= high) {
            long long mid = (low + (high - low) / 2);
            if (check(mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return (ans + 1) % m;
    }
};