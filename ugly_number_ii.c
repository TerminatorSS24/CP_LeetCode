// An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.

// Given an integer n, return the nth ugly number.

 

// Example 1:

// Input: n = 10
// Output: 12
// Explanation: [1, 2, 3, 4, 5, 6, 8, 9, 10, 12] is the sequence of the first 10 ugly numbers.
// Example 2:

// Input: n = 1
// Output: 1
// Explanation: 1 has no prime factors, therefore all of its prime factors are limited to 2, 3, and 5.
#include <stdio.h>
#include <stdlib.h>

int min(int a, int b) {
    return a < b ? a : b;
}

int nthUglyNumber(int n) {
    int* uglyNumbers = (int*)malloc(n * sizeof(int));
    uglyNumbers[0] = 1;

    int idx2 = 0, idx3 = 0, idx5 = 0;
    int next2 = 2, next3 = 3, next5 = 5;

    for (int i = 1; i < n; i++) {
        int nextUgly = min(next2, min(next3, next5));
        uglyNumbers[i] = nextUgly;

        if (nextUgly == next2) {
            idx2++;
            next2 = uglyNumbers[idx2] * 2;
        }
        if (nextUgly == next3) {
            idx3++;
            next3 = uglyNumbers[idx3] * 3;
        }
        if (nextUgly == next5) {
            idx5++;
            next5 = uglyNumbers[idx5] * 5;
        }
    }

    int nthUgly = uglyNumbers[n - 1];
    free(uglyNumbers);
    return nthUgly;
}


