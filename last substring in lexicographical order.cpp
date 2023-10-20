/*Given a string s, return the last substring of s in lexicographical order.

 

Example 1:

Input: s = "abab"
Output: "bab"
Explanation: The substrings are ["a", "ab", "aba", "abab", "b", "ba", "bab"]. The lexicographically maximum substring is "bab".
Example 2:

Input: s = "leetcode"
Output: "tcode"*/
#include <iostream>
#include <vector>
#include <string>

const int P = 37, mod = 1e9 + 9;

using namespace std;

class Solution {
public:
    int powmod(int a, int b) {
        int res = 1;
        while (b > 0) {
            if (b % 2) {
                res = (1ll * res * a) % mod;
                b--;
            }
            else {
                a = (1ll * a * a) % mod;
                b /= 2;
            }
        }
        return res;
    }

    int inv(int a) {
        return powmod(a, mod - 2);
    }

    string lastSubstring(string s) {
        int n = s.size();
        vector<int> hash(n);
        hash[0] = s[0] - 'a';
        for (int i = 1; i < n; i++) {
            hash[i] = (1ll * (s[i] - 'a') * powmod(P, i)) % mod;
            hash[i] = (hash[i] + hash[i - 1]) % mod;
        }

        vector<int> inv_P(n + 1);
        for (int i = 0; i <= n; i++) {
            inv_P[i] = inv(powmod(P, i));
        }

        int j = 0;
        for (int i = 1; i < n; i++) {
            if (s[i] != s[j]) {
                if (s[i] < s[j]) {
                    continue;
                }
                else {
                    j = i;
                    continue;
                }
            }
            int l = 1, r = n - i;
            while (l < r) {
                int mid = (l + r + 1) / 2;
                int hsh1 = hash[j + mid - 1];
                if (j - 1 >= 0) {
                    hsh1 = (hsh1 - hash[j - 1] + mod) % mod;
                    hsh1 = (1ll * hsh1 * inv_P[j]) % mod;
                }
                int hsh2 = hash[i + mid - 1];
                if (i - 1 >= 0) {
                    hsh2 = (hsh2 - hash[i - 1] + mod) % mod;
                    hsh2 = (1ll * hsh2 * inv_P[i]) % mod;
                }
                if (hsh1 == hsh2) {
                    l = mid;
                } else {
                    r = mid - 1;
                }
            }
            if (i + l >= n) {
                continue;
            } else {
                if (s[i + l] > s[j + l]) {
                    j = i;
                }
            }
        }

        string ans = "";
        for (int i = j; i < n; i++) {
            ans += s[i];
        }
        return ans;
    }
};