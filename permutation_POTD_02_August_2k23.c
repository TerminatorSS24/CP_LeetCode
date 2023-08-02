// Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

 

// Example 1:

// Input: nums = [1,2,3]
// Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
// Example 2:

// Input: nums = [0,1]
// Output: [[0,1],[1,0]]
// Example 3:

// Input: nums = [1]
// Output: [[1]]
//**********LEETCODE POTD(02/08/2023)**********
#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void backtrack(int* nums, int start, int size, int** result, int* resultIdx) {
    if (start == size) {
        for (int i = 0; i < size; i++) {
            result[*resultIdx][i] = nums[i];
        }
        (*resultIdx)++;
        return;
    }

    for (int i = start; i < size; i++) {
        swap(&nums[start], &nums[i]);
        backtrack(nums, start + 1, size, result, resultIdx);
        swap(&nums[start], &nums[i]); 
    }
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int totalPermutations = 1;
    for (int i = 1; i <= numsSize; i++) {
        totalPermutations *= i;
    }

    int** result = (int**)malloc(totalPermutations * sizeof(int*));
    for (int i = 0; i < totalPermutations; i++) {
        result[i] = (int*)malloc(numsSize * sizeof(int));
    }

    int resultIdx = 0;
    backtrack(nums, 0, numsSize, result, &resultIdx);

    *returnSize = totalPermutations;
    *returnColumnSizes = (int*)malloc(totalPermutations * sizeof(int));
    for (int i = 0; i < totalPermutations; i++) {
        (*returnColumnSizes)[i] = numsSize;
    }

    return result;
}

