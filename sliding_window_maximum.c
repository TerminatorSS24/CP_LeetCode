// You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

// Return the max sliding window.

 

// Example 1:

// Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
// Output: [3,3,5,5,6,7]
// Explanation: 
// Window position                Max
// ---------------               -----
// [1  3  -1] -3  5  3  6  7       3
//  1 [3  -1  -3] 5  3  6  7       3
//  1  3 [-1  -3  5] 3  6  7       5
//  1  3  -1 [-3  5  3] 6  7       5
//  1  3  -1  -3 [5  3  6] 7       6
//  1  3  -1  -3  5 [3  6  7]      7
// Example 2:

// Input: nums = [1], k = 1
// Output: [1]
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize){
  int* ret_array = (int*) malloc((numsSize-(--k))*sizeof(int));
  int lut_array[100001];
  int idx_head = 0;
  int idx_tail = 0;
  
  *returnSize = 0;
  
  for (int loop_idx=0; loop_idx<numsSize; loop_idx++) {
    while (idx_head < idx_tail && lut_array[idx_head] < (loop_idx-k)) {
      idx_head++;
    }
    
    while (idx_head < idx_tail && nums[lut_array[idx_tail-1]] < nums[loop_idx]) {
      idx_tail--;
    }
    
    lut_array[idx_tail++] = loop_idx;
    
    if (loop_idx >= k) {
      ret_array[(*returnSize)++] = nums[lut_array[idx_head]];
    }
  }
  
  return ret_array;
}