/*Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

Can you solve it without sorting?

 

Example 1:

Input: nums = [3,2,1,5,6,4], k = 2
Output: 5
Example 2:

Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4
**********LEETCODE POTD(14/08/2023)**********
*/
#include <stdlib.h>

int partition(int* arr, int left, int right) {
    int pivot = arr[right];
    int i = left - 1;

    for (int j = left; j < right; j++) {
        if (arr[j] >= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[right];
    arr[right] = temp;

    return i + 1;
}

int findKthLargest(int* nums, int numsSize, int k) {
    int left = 0, right = numsSize - 1;

    while (left <= right) {
        int partitionIndex = partition(nums, left, right);

        if (partitionIndex == k - 1) {
            return nums[partitionIndex];
        } else if (partitionIndex < k - 1) {
            left = partitionIndex + 1;
        } else {
            right = partitionIndex - 1;
        }
    }

    return -1; 
}
