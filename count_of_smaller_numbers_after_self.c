/*
Given an integer array nums, return an integer array counts where counts[i] is the number of smaller elements to the right of nums[i].

 

Example 1:

Input: nums = [5,2,6,1]
Output: [2,1,1,0]
Explanation:
To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.
Example 2:

Input: nums = [-1]
Output: [0]
Example 3:

Input: nums = [-1,-1]
Output: [0,0]
*/
#include <stdio.h>
#include <stdlib.h>

void merge(int* nums, int* indices, int* counts, int left, int mid, int right) {
    int temp[right - left + 1];
    int tempIndices[right - left + 1];
    int tempCounts[right - left + 1];

    int i = left, j = mid + 1, k = 0;
    int count = 0;

    while (i <= mid && j <= right) {
        if (nums[indices[i]] > nums[indices[j]]) {
            temp[k] = indices[j];
            tempCounts[k] = counts[j];
            count++;
            j++;
        } else {
            temp[k] = indices[i];
            tempCounts[k] = counts[i] + count;
            i++;
        }
        k++;
    }

    while (i <= mid) {
        temp[k] = indices[i];
        tempCounts[k] = counts[i] + count;
        i++;
        k++;
    }

    while (j <= right) {
        temp[k] = indices[j];
        tempCounts[k] = counts[j];
        j++;
        k++;
    }

    for (int m = 0; m < k; m++) {
        indices[left + m] = temp[m];
        counts[left + m] = tempCounts[m];
    }
}

void mergeSort(int* nums, int* indices, int* counts, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(nums, indices, counts, left, mid);
        mergeSort(nums, indices, counts, mid + 1, right);
        merge(nums, indices, counts, left, mid, right);
    }
}

int* countSmaller(int* nums, int numsSize, int* returnSize) {
    int* indices = (int*)malloc(numsSize * sizeof(int));
    int* counts = (int*)calloc(numsSize, sizeof(int));
    int* result = (int*)malloc(numsSize * sizeof(int));
    
    for (int i = 0; i < numsSize; i++) {
        indices[i] = i;
    }
    
    mergeSort(nums, indices, counts, 0, numsSize - 1);

    for (int i = 0; i < numsSize; i++) {
        result[indices[i]] = counts[i];
    }

    free(indices);
    free(counts);
    
    *returnSize = numsSize;
    return result;
}

