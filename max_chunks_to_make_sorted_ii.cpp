/*You are given an integer array arr.

We split arr into some number of chunks (i.e., partitions), and individually sort each chunk. After concatenating them, the result should equal the sorted array.

Return the largest number of chunks we can make to sort the array.

 

Example 1:

Input: arr = [5,4,3,2,1]
Output: 1
Explanation:
Splitting into two or more chunks will not return the required result.
For example, splitting into [5, 4], [3, 2, 1] will result in [4, 5, 1, 2, 3], which isn't sorted.
Example 2:

Input: arr = [2,1,3,4,4]
Output: 4
Explanation:
We can split into two chunks, such as [2, 1], [3, 4, 4].
However, splitting into [2, 1], [3], [4], [4] is the highest number of chunks possible.*/
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        map<int, int> mpp, temp;
        int ans = 0;
        for(int i=0; i<arr.size(); i++){
            mpp[arr[i]]++;
        } 
        int maxi = arr[0];
        for(int i=0; i<arr.size(); i++){
            maxi = max(arr[i], maxi);
            temp[arr[i]]++;
            bool flag = true;
            for(auto it: mpp){
                if(it.first < maxi){
                    if(temp[it.first] < it.second){
                        flag = false;
                        break;
                    }
                }
                else break;
            }
            if(flag){
                cout<<i<<", "<<maxi<<endl;
                ans++;
                maxi = INT_MIN;
            } 
        }
        return ans;
    }
};
