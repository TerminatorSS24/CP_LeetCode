/*
You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it represented by an array nums. You are asked to burst all the balloons.

If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins. If i - 1 or i + 1 goes out of bounds of the array, then treat it as if there is a balloon with a 1 painted on it.

Return the maximum coins you can collect by bursting the balloons wisely.

 

Example 1:

Input: nums = [3,1,5,8]
Output: 167
Explanation:
nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167
Example 2:

Input: nums = [1,5]
Output: 10
*/
#include <vector>
#include <cstring> 

using namespace std;
class Solution {
public:
    int n;
    int t[501][501]; 
    int solve(vector<int> &nums, int i, int j){
		if(i > j)
			return 0;
        if(i == j){    
            int temp = nums[i];
            if(i - 1 >= 0)  
                temp *= nums[i - 1];
            if(i + 1 < n)
                temp *= nums[i + 1];
            return temp;
        }
		if(t[i][j] != -1)  
			return t[i][j];
        int ans = 0;

        for(int k = i; k <= j; k++){
		
            int temp = nums[k];
			
                temp *= nums[j + 1];
				
            if(i - 1 >= 0) 
                temp *= nums[i - 1];
				
            temp += (solve(nums, i, k - 1) + solve(nums, k + 1, j));
			
            ans = max(ans, temp);
        }
        return t[i][j] = ans;
    }
    
    int maxCoins(vector<int>& nums) {
        memset(t, -1, sizeof(t));
		vector<int> arr = {1};
        for(int x: nums) 
			arr.push_back(x);
        arr.push_back(1);
        n = arr.size();
        return solve(arr, 1, arr.size() - 2);
    }
};