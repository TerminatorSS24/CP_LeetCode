/*Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.



Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Explanation: [4,9] is also accepted.*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *intersection(int *nums1, int nums1Size, int *nums2, int nums2Size, int *returnSize)
{
    int *nums = (int *)malloc(sizeof(int) * 300);
    int arr1[1001] = {0}, k = 0, i, arr2[1001] = {0};
    for (i = 0; i < nums1Size; i++)
    {
        if (arr1[nums1[i]])
            continue;
        else
            arr1[nums1[i]]++;
    }
    for (i = 0; i < nums2Size; i++)
    {
        if (arr2[nums2[i]])
            continue;
        else
            arr2[nums2[i]]++;
    }
    for (i = 0; i < 1001; i++)
    {
        if (arr1[i] == 1 && arr2[i] == 1)
            nums[k++] = i;
    }
    *returnSize = k;
    return nums;
}