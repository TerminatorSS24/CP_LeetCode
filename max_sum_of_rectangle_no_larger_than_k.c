/*Given an m x n matrix matrix and an integer k, return the max sum of a rectangle in the matrix such that its sum is no larger than k.

It is guaranteed that there will be a rectangle with a sum no larger than k.

 

Example 1:


Input: matrix = [[1,0,1],[0,-2,3]], k = 2
Output: 2
Explanation: Because the sum of the blue rectangle [[0, 1], [-2, 3]] is 2, and 2 is the max number no larger than k (k = 2).
Example 2:

Input: matrix = [[2,2,-1]], k = 3
Output: 3*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int maxSumSubmatrix(int** matrix, int matrixSize, int* matrixColSize, int k) {
    int rows = matrixSize;
    int cols = matrixColSize[0];
    int maxSum = INT_MIN;
    
    for (int left = 0; left < cols; left++) {
        int rowSum[rows];
        for (int i = 0; i < rows; i++) {
            rowSum[i] = 0;
        }
        
        for (int right = left; right < cols; right++) {
            for (int i = 0; i < rows; i++) {
                rowSum[i] += matrix[i][right];
            }
            
            int currSum = 0;
            int maxCurrSum = INT_MIN;
            
            for (int i = 0; i < rows; i++) {
                currSum = (currSum > 0) ? currSum + rowSum[i] : rowSum[i];
                maxCurrSum = (maxCurrSum > currSum) ? maxCurrSum : currSum;
            }
            
            if (maxCurrSum <= k) {
                maxSum = (maxSum > maxCurrSum) ? maxSum : maxCurrSum;
            } else {
                for (int i = 0; i < rows; i++) {
                    int sum = 0;
                    for (int j = i; j < rows; j++) {
                        sum += rowSum[j];
                        if (sum <= k && sum > maxSum) {
                            maxSum = sum;
                        }
                    }
                }
            }
        }
    }
    
    return maxSum;
}
