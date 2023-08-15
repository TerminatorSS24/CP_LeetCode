/*You are given a 2D array of axis-aligned rectangles. Each rectangle[i] = [xi1, yi1, xi2, yi2] denotes the ith rectangle where (xi1, yi1) are the coordinates of the bottom-left corner, and (xi2, yi2) are the coordinates of the top-right corner.

Calculate the total area covered by all rectangles in the plane. Any area covered by two or more rectangles should only be counted once.

Return the total area. Since the answer may be too large, return it modulo 109 + 7.

 

Example 1:

image: https://s3-lc-upload.s3.amazonaws.com/uploads/2018/06/06/rectangle_area_ii_pic.png

Input: rectangles = [[0,0,2,2],[1,0,2,3],[1,0,3,1]]
Output: 6
Explanation: A total area of 6 is covered by all three rectangles, as illustrated in the picture.
From (1,1) to (2,2), the green and red rectangles overlap.
From (1,0) to (2,3), all three rectangles overlap.
Example 2:

Input: rectangles = [[0,0,1000000000,1000000000]]
Output: 49
Explanation: The answer is 1018 modulo (109 + 7), which is 49.*/
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

class Solution {
public:
    #define ll long long
    ll MOD=1e9+7;
    static bool cmp(std::vector<int>&v1, std::vector<int>&v2){
        if(v1[0]==v2[0]){
            return v1[2]<v2[2];
        }
        return v1[0]<v2[0];
    }
    
    int rectangleArea(std::vector<std::vector<int>>& rectangles) {
        ll n = rectangles.size(), answer = 0;
        std::set<ll> ss;
        
        for(auto &x : rectangles){
            ss.insert(x[1]);
            ss.insert(x[3]);
        }
        
        std::sort(rectangles.begin(), rectangles.end(), cmp);
        ll lower = *ss.begin();
        
        for(auto &x : ss){
            ll upper = x;
            ll height = upper - lower;
            ll left = rectangles[0][0], right = left;
            
            for(auto &y : rectangles){
                if(y[1] <= lower && y[3] >= upper){
                    if(y[0] > right){
                        answer = (answer + height * (right - left)) % MOD;
                        left = y[0];
                    }
                    if(y[2] > right){
                        right = y[2];
                    }
                }
            }
            answer = (answer + height * (right - left)) % MOD;
            lower = upper;
        }
        return answer % MOD;
    }
};