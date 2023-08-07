// You are given an m x n integer matrix matrix with the following two properties:

// Each row is sorted in non-decreasing order.
// The first integer of each row is greater than the last integer of the previous row.
// Given an integer target, return true if target is in matrix or false otherwise.

// You must write a solution in O(log(m * n)) time complexity.

 

// Example 1:

// image: https://assets.leetcode.com/uploads/2020/10/05/mat.jpg

// Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
// Output: true
// Example 2:
 
// image: https://assets.leetcode.com/uploads/2020/10/05/mat2.jpg

// Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
// Output: false
// **********LEETCODE POTD(07/08/2023)**********
# include <stdio.h>
# include <stdbool.h>
bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
    int m = matrixSize;
    int n = *matrixColSize;
    
    int left = 0;
    int right = m * n - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int midValue = matrix[mid / n][mid % n];
        
        if (midValue == target) {
            return true;
        } else if (midValue < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return false;
}
