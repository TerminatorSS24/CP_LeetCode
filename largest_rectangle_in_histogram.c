// Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.
// Example 1:

// image: https://assets.leetcode.com/uploads/2021/01/04/histogram.jpg

// Input: heights = [2,1,5,6,2,3]
// Output: 10
// Explanation: The above is a histogram where width of each bar is 1.
// The largest rectangle is shown in the red area, which has an area = 10 units.
// Example 2:

// image: https://assets.leetcode.com/uploads/2021/01/04/histogram-1.jpg

// Input: heights = [2,4]
// Output: 4
#include <stdio.h>
#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int largestRectangleArea(int* heights, int heightsSize) {
    int* stack = (int*)malloc((heightsSize + 1) * sizeof(int)); 
    int top = -1; 
    int maxArea = 0;

    for (int i = 0; i <= heightsSize; i++) {
        while (top >= 0 && (i == heightsSize || heights[i] < heights[stack[top]])) {
            int h = heights[stack[top--]];
            int w = (top >= 0) ? (i - stack[top] - 1) : i;
            maxArea = MAX(maxArea, h * w);
        }
        stack[++top] = i;
    }

    free(stack);
    return maxArea;
}

