/*Given an array rectangles where rectangles[i] = [xi, yi, ai, bi] represents an axis-aligned rectangle. The bottom-left point of the rectangle is (xi, yi) and the top-right point of it is (ai, bi).

Return true if all the rectangles together form an exact cover of a rectangular region.

 

Example 1:

image : https://assets.leetcode.com/uploads/2021/03/27/perectrec1-plane.jpg

Input: rectangles = [[1,1,3,3],[3,1,4,2],[3,2,4,4],[1,3,2,4],[2,3,3,4]]
Output: true
Explanation: All 5 rectangles together form an exact cover of a rectangular region.
Example 2:

image: https://assets.leetcode.com/uploads/2021/03/27/perfectrec2-plane.jpg

Input: rectangles = [[1,1,2,3],[1,3,2,4],[3,1,4,2],[3,2,4,4]]
Output: false
Explanation: Because there is a gap between the two rectangular regions.
Example 3:

image: https://assets.leetcode.com/uploads/2021/03/27/perfecrrec4-plane.jpg

Input: rectangles = [[1,1,3,3],[3,1,4,2],[1,3,2,4],[2,2,4,4]]
Output: false
Explanation: Because two of the rectangles overlap with each other.*/
#include <iostream>
// #include <vector>
#include <unordered_map>
#include <cmath>
#include <vector>

class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        unordered_map<long long, int> mark;
        const long long N=1000000;
        for(vector<int>& x:rectangles){
            int x1=x[0];
            int y1=x[1];
            int x2=x[2];
            int y2=x[3];
            mark[x1*N+y1]++;
            mark[x1*N+y2]--;
            mark[x2*N+y1]--;
            mark[x2*N+y2]++;
        }
        int n_mark=0;
        for(auto ptr=mark.begin();ptr!=mark.end();ptr++)
            if(ptr->second!=0){
                if(abs(ptr->second)!=1) return false;
                n_mark++;
            }
        return n_mark==4;
    }
};