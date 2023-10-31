/*You are given an integer array pref of size n. Find and return the array arr of size n that satisfies:

pref[i] = arr[0] ^ arr[1] ^ ... ^ arr[i].
Note that ^ denotes the bitwise-xor operation.

It can be proven that the answer is unique.

 

Example 1:

Input: pref = [5,2,0,3,1]
Output: [5,7,2,3,2]
Explanation: From the array [5,7,2,3,2] we have the following:
- pref[0] = 5.
- pref[1] = 5 ^ 7 = 2.
- pref[2] = 5 ^ 7 ^ 2 = 0.
- pref[3] = 5 ^ 7 ^ 2 ^ 3 = 3.
- pref[4] = 5 ^ 7 ^ 2 ^ 3 ^ 2 = 1.
Example 2:

Input: pref = [13]
Output: [13]
Explanation: We have pref[0] = arr[0] = 13.
**********LEETCODE POTD(31/10/2023)**********
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findArray(vector<int>& pref) {

        vector<int> ans;

        int n = pref.size();

        ans.push_back(pref[0]);
        int xr = pref[0];

        for (int i = 1; i < n; i++) {
            ans.push_back(pref[i] ^ xr);
            xr ^= ans[i];
        }
        return ans;
    }
};