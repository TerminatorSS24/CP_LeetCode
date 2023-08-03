// The set [1, 2, 3, ..., n] contains a total of n! unique permutations.

// By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

// "123"
// "132"
// "213"
// "231"
// "312"
// "321"
// Given n and k, return the kth permutation sequence.

 

// Example 1:

// Input: n = 3, k = 3
// Output: "213"
// Example 2:

// Input: n = 4, k = 9
// Output: "2314"
// Example 3:

// Input: n = 3, k = 1
// Output: "123"
#include <stdio.h>
#include <stdlib.h>

int factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

char *getPermutation(int n, int k) {
    char *result = (char *)malloc((n + 1) * sizeof(char));
    int *available = (int *)malloc(n * sizeof(int));
    int i, index, fact = factorial(n - 1);

    for (i = 0; i < n; i++) {
        available[i] = i + 1;
    }

    k--; 

    for (i = 0; i < n; i++) {
        index = k / fact;
        result[i] = '0' + available[index];
        for (int j = index; j < n - i - 1; j++) {
            available[j] = available[j + 1];
        }
        k %= fact;
        if (n - i - 1 > 0) {
            fact /= n - i - 1;
        }
    }

    result[n] = '\0';
    free(available);

    return result;
}

