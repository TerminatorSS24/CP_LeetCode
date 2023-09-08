/*Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

 

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9*/
#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
        
        int n = nums.size();
        if(n <= 1)
            return n;

        std::sort(nums.begin(), nums.end());
        int maxlen = 1, len = 1;
        for(int i = 1; i < n; i++) {
            if(nums[i] == nums[i-1])
                continue;
            else if(nums[i] == nums[i-1] + 1)
                len++;
            else
                len = 1;
            
            maxlen = std::max(maxlen, len);
        }
        return maxlen; 
    }
};
