// Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane, return the maximum number of points that lie on the same straight line.

 

// Example 1:

// image: https://assets.leetcode.com/uploads/2021/02/25/plane1.jpg

// Input: points = [[1,1],[2,2],[3,3]]
// Output: 3
// Example 2:

// image: https://assets.leetcode.com/uploads/2021/02/25/plane2.jpg

// Input: points = [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
// Output: 4
#include <stdio.h>
#include <math.h>

#include <stdbool.h>

struct point {
    double x, y;
};

bool isCollinear(struct point a, struct point b, struct point c) {
    double m1 = (b.y - a.y) / (b.x - a.x);
    double m2 = (c.y - b.y) / (c.x - b.x);
    return m1 == m2;
}

int maxPoints(int** points, int pointsSize, int* pointsColSize) {
    int n = pointsSize;
    if (n <= 2) {
        return n;
    }
    
    struct point coordinates[n];
    for (int i = 0; i < n; i++) {
        struct point k = { (double)points[i][0], (double)points[i][1] };
        coordinates[i] = k;
    }
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int cnt = 0;
            for (int k = 0; k < n; k++) {
                if (i != j && j != k && i != k) {
                    if (isCollinear(coordinates[i], coordinates[j], coordinates[k])) {
                        cnt++;
                    }
                }
            }
            ans = (cnt + 2 > ans) ? cnt + 2 : ans;
        }
    }
    return ans;
}
