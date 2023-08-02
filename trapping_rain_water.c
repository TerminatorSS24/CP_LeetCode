// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
// image = https://assets.leetcode.com/uploads/2018/10/22/rainwatertrap.png


// Example 1:
// Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
// Output: 6
// Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
// Example 2:

// Input: height = [4,2,0,3,2,5]
// Output: 9
#include<stdio.h>
int trap(int* height, int heightSize) {
    if (height == NULL || heightSize <= 2) {
        return 0;
    }

    int left = 0;
    int right = heightSize - 1;
    int leftMax = 0;
    int rightMax = 0;
    int trappedWater = 0;

    while (left < right) {
        if (height[left] < height[right]) {
            if (height[left] >= leftMax) {
                leftMax = height[left];
            } else {
                trappedWater += leftMax - height[left];
            }
            left++;
        } else {
            if (height[right] >= rightMax) {
                rightMax = height[right];
            } else {
                trappedWater += rightMax - height[right];
            }
            right--;
        }
    }

    return trappedWater;
}
