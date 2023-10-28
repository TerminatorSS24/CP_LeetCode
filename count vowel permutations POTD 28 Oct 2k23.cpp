/*Given an integer n, your task is to count how many strings of length n can be formed under the following rules:

Each character is a lower case vowel ('a', 'e', 'i', 'o', 'u')
Each vowel 'a' may only be followed by an 'e'.
Each vowel 'e' may only be followed by an 'a' or an 'i'.
Each vowel 'i' may not be followed by another 'i'.
Each vowel 'o' may only be followed by an 'i' or a 'u'.
Each vowel 'u' may only be followed by an 'a'.
Since the answer may be too large, return it modulo 10^9 + 7.

 

Example 1:

Input: n = 1
Output: 5
Explanation: All possible strings are: "a", "e", "i" , "o" and "u".
Example 2:

Input: n = 2
Output: 10
Explanation: All possible strings are: "ae", "ea", "ei", "ia", "ie", "io", "iu", "oi", "ou" and "ua".
Example 3: 

Input: n = 5
Output: 68
**********LEETCODE POTD(28/10/2023)**********
*/
#include<iostream>
using namespace std;
class Solution {
public:
    int countVowelPermutation(int n) {
        long long prevA = 1, prevE = 1, prevI = 1, prevO = 1, prevU = 1;
        int mod = 1e9 + 7; 
        for (int length = 2; length <= n; length++) {
            long long nextA = (prevE + prevU + prevI) % mod;
            long long nextE = (prevA + prevI) % mod;
            long long nextI = (prevE + prevO) % mod;
            long long nextO = prevI;
            long long nextU = (prevO + prevI) % mod;
            prevA = nextA;
            prevE = nextE;
            prevI = nextI;
            prevO = nextO;
            prevU = nextU;
        }
        return (prevA + prevE + prevI + prevO + prevU) % mod;
    }
};