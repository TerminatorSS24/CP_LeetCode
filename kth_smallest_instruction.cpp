/*Bob is standing at cell (0, 0), and he wants to reach destination: (row, column). He can only travel right and down. You are going to help Bob by providing instructions for him to reach destination.

The instructions are represented as a string, where each character is either:

'H', meaning move horizontally (go right), or
'V', meaning move vertically (go down).
Multiple instructions will lead Bob to destination. For example, if destination is (2, 3), both "HHHVV" and "HVHVH" are valid instructions.

However, Bob is very picky. Bob has a lucky number k, and he wants the kth lexicographically smallest instructions that will lead him to destination. k is 1-indexed.

Given an integer array destination and an integer k, return the kth lexicographically smallest instructions that will take Bob to destination.

 

Example 1:

image: https://assets.leetcode.com/uploads/2020/10/12/ex1.png

Input: destination = [2,3], k = 1
Output: "HHHVV"
Explanation: All the instructions that reach (2, 3) in lexicographic order are as follows:
["HHHVV", "HHVHV", "HHVVH", "HVHHV", "HVHVH", "HVVHH", "VHHHV", "VHHVH", "VHVHH", "VVHHH"].
Example 2:

image: https://assets.leetcode.com/uploads/2020/10/12/ex2.png

Input: destination = [2,3], k = 2
Output: "HHVHV"
Example 3:

image: https://assets.leetcode.com/uploads/2020/10/12/ex3.png

Input: destination = [2,3], k = 3
Output: "HHVVH"*/
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    size_t NChooseK(int n, int k) {
        return round(tgamma(n+1)/tgamma(k+1)/tgamma(n-k+1));
    }
    
    string kthSmallestPath(vector<int>& destination, int k) {
        int numHLeft = destination[1], numCharsToBuild = destination[0] + destination[1];
        uint64_t totalMax = NChooseK(numCharsToBuild, numHLeft);
        string ans = "";
        while (numHLeft && numHLeft < numCharsToBuild) {
            uint64_t maxH = totalMax*numHLeft/numCharsToBuild;
            if (k <= maxH) {
                ans += "H";
                numHLeft--;
                totalMax = maxH;
            } else {
                ans += "V";
                totalMax -= maxH;
                k -= maxH;
            }
            numCharsToBuild--;
        }
        ans += string(numCharsToBuild, numHLeft ? 'H' : 'V');
        return ans;
    }
};
