/*Given two integers n and k, return the kth lexicographically smallest integer in the range [1, n].

 

Example 1:

Input: n = 13, k = 2
Output: 10
Explanation: The lexicographical order is [1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9], so the second smallest number is 10.
Example 2:

Input: n = 1, k = 1
Output: 1*/
#include <stdio.h>
int findKthNumber(int n, int k) {
    int curr = 1;
    k--;

    while (k > 0) {
        int steps = 0;
        long long first = curr;
        long long last = curr + 1;

        while (first <= n) {
            steps += fmin(n + 1, last) - first;
            first *= 10;
            last *= 10;
        }

        if (steps <= k) {
            curr++;
            k -= steps;
        } else {
            curr *= 10;
            k--;
        }
    }

    return curr;
}
