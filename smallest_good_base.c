/*Given an integer n represented as a string, return the smallest good base of n.

We call k >= 2 a good base of n, if all digits of n base k are 1's.

 

Example 1:

Input: n = "13"
Output: "3"
Explanation: 13 base 3 is 111.
Example 2:

Input: n = "4681"
Output: "8"
Explanation: 4681 base 8 is 11111.
Example 3:

Input: n = "1000000000000000000"
Output: "999999999999999999"
Explanation: 1000000000000000000 base 999999999999999999 is 11.*/
#include <stdlib.h>
#include <string.h>
#include <math.h>

char* smallestGoodBase(char* n) {
    long long num = atoll(n);
    long long ans = num - 1;

    for (int m = 60; m >= 2; m--) {
        long long k = pow(num, 1.0 / m);
        if (k <= 1)
            continue;

        long long sum = 1, cur = 1;
        for (int i = 1; i <= m; i++) {
            cur *= k;
            sum += cur;
        }

        if (sum == num) {
            ans = k;
            break;
        }
    }

    char* result = (char*)malloc(21 * sizeof(char));
    snprintf(result, 21, "%lld", ans);
    return result;
}
