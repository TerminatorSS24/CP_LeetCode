/*Given an array of n integers nums, a 132 pattern is a subsequence of three integers nums[i], nums[j] and nums[k] such that i < j < k and nums[i] < nums[k] < nums[j].

Return true if there is a 132 pattern in nums, otherwise, return false.

 

Example 1:

Input: nums = [1,2,3,4]
Output: false
Explanation: There is no 132 pattern in the sequence.
Example 2:

Input: nums = [3,1,4,2]
Output: true
Explanation: There is a 132 pattern in the sequence: [1, 4, 2].
Example 3:

Input: nums = [-1,3,2,0]
Output: true
Explanation: There are three 132 patterns in the sequence: [-1, 3, 2], [-1, 3, 0] and [-1, 2, 0].
**********LEETCODE POTD(30/09/2023)**********
*/
#include<stdbool.h>
bool find132pattern(const int * const nums, const int numsLen){
	assert(numsLen >= 1);

	int leftFirstLargers[numsLen];
	{
		int monoStack[numsLen];
		int monoStackLen = 0;
		for (int i = 0; i < numsLen; i += 1){
			while (
				monoStackLen > 0 &&
				nums[ monoStack[monoStackLen - 1] ] <= nums[i]
			){
				monoStackLen -= 1;
			}

			leftFirstLargers[i] = (0 == monoStackLen)? -1 : monoStack[monoStackLen - 1];

			monoStack[monoStackLen] = i;
			monoStackLen += 1;
		}
	}

	int minUntils[numsLen];
	minUntils[0] = nums[0];
	for (int i = 1; i < numsLen; i += 1){
		minUntils[i] = (nums[i] < minUntils[i - 1])? nums[i] : minUntils[i - 1];
	}

	for (int i = 2; i < numsLen; i += 1){
		if (!( leftFirstLargers[i] >= 1 )){
			continue;
		}

		if (minUntils[leftFirstLargers[i] - 1] < nums[i]){
			return true;
		}
	}
	return false;
}