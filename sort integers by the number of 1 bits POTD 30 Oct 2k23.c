/*You are given an integer array arr. Sort the integers in the array in ascending order by the number of 1's in their binary representation and in case of two or more integers have the same number of 1's you have to sort them in ascending order.

Return the array after sorting it.

 

Example 1:

Input: arr = [0,1,2,3,4,5,6,7,8]
Output: [0,1,2,4,8,3,5,6,7]
Explantion: [0] is the only integer with 0 bits.
[1,2,4,8] all have 1 bit.
[3,5,6] have 2 bits.
[7] has 3 bits.
The sorted array by bits is [0,1,2,4,8,3,5,6,7]
Example 2:

Input: arr = [1024,512,256,128,64,32,16,8,4,2,1]
Output: [1,2,4,8,16,32,64,128,256,512,1024]
Explantion: All integers have 1 bit in the binary representation, you should just sort them in ascending order.
**********LEETCODE POTD(30/10/2023)**********
*/
#include<stdio.h>
#include<stdlib.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int asscend_bits(const void* nums1, const void * nums2){
    int temp_nums1 = *(int*)nums1;
    int temp_nums2 = *(int*)nums2;
    int count_bits_nums1 = 0;
    int count_bits_nums2 = 0;
    while(temp_nums1){
        temp_nums1 &= (temp_nums1 - 1);
        count_bits_nums1++;
    }
    while(temp_nums2){
        temp_nums2 &= (temp_nums2 - 1);
        count_bits_nums2++;
    }
    if(count_bits_nums1 > count_bits_nums2){
        return 1;
    }else if(count_bits_nums1 < count_bits_nums2){
        return -1;
    }else{
        return *(int*)nums1 - *(int*)nums2;
    }
} 
int* sortByBits(int* arr, int arrSize, int* returnSize){
  *returnSize = arrSize;
  qsort(arr,arrSize,sizeof(int),asscend_bits);
  return arr;
}