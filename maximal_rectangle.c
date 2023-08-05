// Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

 

// Example 1:


// Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
// Output: 6
// Explanation: The maximal rectangle is shown in the above picture.
// Example 2:

// Input: matrix = [["0"]]
// Output: 0
// Example 3:

// Input: matrix = [["1"]]
// Output: 1
#include <stdio.h>
#include <stdlib.h>

int maximalRectangle(char** matrix, int matrixSize, int* matrixColSize) {
    if (matrix == NULL || matrixSize == 0 || matrixColSize == NULL || matrixColSize[0] == 0) {
        return 0;
    }
    
    int maxArea = 0;
    int* heights = (int*)malloc(sizeof(int) * matrixColSize[0]);
    
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixColSize[0]; j++) {
            if (matrix[i][j] == '1') {
                heights[j] = (i == 0) ? 1 : heights[j] + 1;
            } else {
                heights[j] = 0;
            }
        }
        
        maxArea = maxRectangleInHistogram(heights, matrixColSize[0], maxArea);
    }
    
    free(heights);
    return maxArea;
}

int maxRectangleInHistogram(int* heights, int size, int maxArea) {
    int* stack = (int*)malloc(sizeof(int) * (size + 1));
    int top = -1;
    
    for (int i = 0; i <= size; i++) {
        int h = (i == size) ? 0 : heights[i];
        
        while (top != -1 && h < heights[stack[top]]) {
            int height = heights[stack[top--]];
            int width = (top == -1) ? i : (i - stack[top] - 1);
            maxArea = (maxArea > height * width) ? maxArea : height * width;
        }
        
        stack[++top] = i;
    }
    
    free(stack);
    return maxArea;
}

