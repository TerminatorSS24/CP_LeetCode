/*There is an integer array nums that consists of n unique elements, but you have forgotten it. However, you do remember every pair of adjacent elements in nums.

You are given a 2D integer array adjacentPairs of size n - 1 where each adjacentPairs[i] = [ui, vi] indicates that the elements ui and vi are adjacent in nums.

It is guaranteed that every adjacent pair of elements nums[i] and nums[i+1] will exist in adjacentPairs, either as [nums[i], nums[i+1]] or [nums[i+1], nums[i]]. The pairs can appear in any order.

Return the original array nums. If there are multiple solutions, return any of them.

 

Example 1:

Input: adjacentPairs = [[2,1],[3,4],[3,2]]
Output: [1,2,3,4]
Explanation: This array has all its adjacent pairs in adjacentPairs.
Notice that adjacentPairs[i] may not be in left-to-right order.
Example 2:

Input: adjacentPairs = [[4,-2],[1,4],[-3,1]]
Output: [-2,4,1,-3]
Explanation: There can be negative numbers.
Another solution is [-3,1,4,-2], which would also be accepted.
Example 3:

Input: adjacentPairs = [[100000,-100000]]
Output: [100000,-100000]
**********LEETCODE POTD(10/11/2023)**********
*/
#include<stdio.h>
#define OFFSET 1e5
int* restoreArray(int** adjacentPairs, int adjacentPairsSize, int* adjacentPairsColSize, int* returnSize){
    int** hash = (int**)calloc(2*1e5+1, sizeof(int*));
    int num;
    for(int i = 0; i < adjacentPairsSize; i++){
        for(int j = 0; j < 2; j++){
            num = adjacentPairs[i][j] + OFFSET;
            if(hash[num] == NULL){
                hash[num] = (int*)calloc(3, sizeof(int));
            }
            hash[num][++hash[num][0]] = adjacentPairs[i][j ^ 1] + OFFSET;
        }
    }
    int* ans = (int*)calloc(adjacentPairsSize+1, sizeof(int));
    int next, prevNext;
    num = adjacentPairsSize;
    for(int i = 0; i < 2*1e5+1; i++){
        if(hash[i] && hash[i][0] == 1){
            ans[num] = i - OFFSET;
            next = hash[i][1];
            free(hash[i]);
            if(num == 0)
                break;
            num = 0;        
        }
    } 
    num = 1;
    while(num < adjacentPairsSize){
        for(int i = 1; i < 3; i++){
            if(hash[next][i] != ans[num-1] + OFFSET){
                ans[num++] = next - OFFSET;
                prevNext = next;
                next = hash[next][i];
                free(hash[prevNext]);
                break;
            }
        }
    }
    free(hash);
    *returnSize = adjacentPairsSize + 1;
    return ans;
}