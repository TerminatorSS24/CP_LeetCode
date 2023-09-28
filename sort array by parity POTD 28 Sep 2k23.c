/*Given an integer array nums, move all the even integers at the beginning of the array followed by all the odd integers.

Return any array that satisfies this condition.

 

Example 1:

Input: nums = [3,1,2,4]
Output: [2,4,3,1]
Explanation: The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.
Example 2:

Input: nums = [0]
Output: [0]
**********LEETCODE POTD(28/09/2023)**********
*/
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *sortArrayByParity(int *nums, int numsSize, int *returnSize)
{
    *returnSize = numsSize;
    int s;
    for (int i = 0; i < numsSize - 1; i++)
    {
        if (nums[i] % 2 == 0)
            continue;
        else
        {
            for (int j = i + 1; j < numsSize; j++)
            {
                if (nums[j] % 2 == 0)
                {
                    s = nums[i];
                    nums[i] = nums[j];
                    nums[j] = s;
                    break;
                }
            }
        }
    }
    return nums;
}