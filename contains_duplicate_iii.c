// You are given an integer array nums and two integers indexDiff and valueDiff.

// Find a pair of indices (i, j) such that:

// i != j,
// abs(i - j) <= indexDiff.
// abs(nums[i] - nums[j]) <= valueDiff, and
// Return true if such pair exists or false otherwise.

 

// Example 1:

// Input: nums = [1,2,3,1], indexDiff = 3, valueDiff = 0
// Output: true
// Explanation: We can choose (i, j) = (0, 3).
// We satisfy the three conditions:
// i != j --> 0 != 3
// abs(i - j) <= indexDiff --> abs(0 - 3) <= 3
// abs(nums[i] - nums[j]) <= valueDiff --> abs(1 - 1) <= 0
// Example 2:

// Input: nums = [1,5,9,1,5,9], indexDiff = 2, valueDiff = 3
// Output: false
// Explanation: After trying all the possible pairs (i, j), we cannot satisfy the three conditions, so we return false.
#include <stdbool.h>
#define ABS(x) ((x) >= 0 ? (x) : -(x))
typedef struct {
    int num;
    int indx;
} numIndxType;

int cmp(const void* a, const void* b) {
    numIndxType A = *(numIndxType*) a;
    numIndxType B = *(numIndxType*) b;
    return A.num - B.num;
}

bool containsNearbyAlmostDuplicate(int* nums, int numsSize, int indexDiff, int valueDiff){
    bool returnVal = false;
    numIndxType *arr = malloc(numsSize*sizeof(numIndxType));
    for (int i = 0; i < numsSize; i++) {
        arr[i].num = nums[i];
        arr[i].indx = i;
    }
    qsort(arr, numsSize, sizeof(numIndxType), cmp);   
    for (int i = 0; i < numsSize-1; i++) {
        for (int iNext = 1; i + iNext < numsSize && arr[i+iNext].num - arr[i].num <= valueDiff; iNext++) {
            if (ABS(arr[i+iNext].indx - arr[i].indx) <= indexDiff) {
                returnVal = true;
                goto out;
            }
        }
    }
    out:
    free(arr);
    return returnVal;
}