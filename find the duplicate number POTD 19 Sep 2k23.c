/*Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.

 

Example 1:

Input: nums = [1,3,4,2,2]
Output: 2
Example 2:

Input: nums = [3,1,3,4,2]
Output: 3
**********LEETCODE POTD(19/09/2023)**********
*/
int findDuplicate(int* nums, int numsSize){
    int* seen = (int*)malloc((numsSize + 1) * sizeof(int));
    memset(seen, 0, (numsSize + 1) * sizeof(int));

    for (int i = 0; i < numsSize; i++) {
        if (seen[nums[i]] == 1) {
            free(seen);
            return nums[i];
        } else {
            seen[nums[i]] = 1;
        }
    }

    free(seen);
    return -1;
}