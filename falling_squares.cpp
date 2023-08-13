/*There are several squares being dropped onto the X-axis of a 2D plane.

You are given a 2D integer array positions where positions[i] = [lefti, sideLengthi] represents the ith square with a side length of sideLengthi that is dropped with its left edge aligned with X-coordinate lefti.

Each square is dropped one at a time from a height above any landed squares. It then falls downward (negative Y direction) until it either lands on the top side of another square or on the X-axis. A square brushing the left/right side of another square does not count as landing on it. Once it lands, it freezes in place and cannot be moved.

After each square is dropped, you must record the height of the current tallest stack of squares.

Return an integer array ans where ans[i] represents the height described above after dropping the ith square.

 

Example 1:

image: https://assets.leetcode.com/uploads/2021/04/28/fallingsq1-plane.jpg

Input: positions = [[1,2],[2,3],[6,1]]
Output: [2,5,5]
Explanation:
After the first drop, the tallest stack is square 1 with a height of 2.
After the second drop, the tallest stack is squares 1 and 2 with a height of 5.
After the third drop, the tallest stack is still squares 1 and 2 with a height of 5.
Thus, we return an answer of [2, 5, 5].
Example 2:

Input: positions = [[100,100],[200,100]]
Output: [100,100]
Explanation:
After the first drop, the tallest stack is square 1 with a height of 100.
After the second drop, the tallest stack is either square 1 or square 2, both with heights of 100.
Thus, we return an answer of [100, 100].
Note that square 2 only brushes the right side of square 1, which does not count as landing on it.*/
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

struct SegmentTree {
    SegmentTree(int n) : n(n) {
        size = 1;
        while (size < n) {
            size <<= 1;
        }
        tree.resize(2*size);
        lazy.resize(2*size);
    }

    void add_range(int l, int r, int h) {
        l += size;
        r += size;

        tree[l] = max(tree[l], h);
        tree[r] = max(tree[r], h);
        if (l != r) {
            if (!(l & 1)) {
                lazy[l+1] = max(lazy[l-1], h);
            }
            if (r & 1) {
                lazy[r-1] = max(lazy[r-1], h);
            }
        }
        l >>= 1;
        r >>= 1;
        while (l != r) {
            tree[l] = max(tree[2*l], tree[2*l + 1]);
            tree[r] = max(tree[2*r], tree[2*r + 1]);
            if (l / 2 != r / 2) {
                if (!(l & 1)) {
                    lazy[l+1] = max(lazy[l+1], h);
                }
                if (r & 1) {
                    lazy[r-1] = max(lazy[r-1], h);
                }
            }
            l >>= 1;
            r >>= 1;
        }
        while (l > 0) {
            tree[l] = max(tree[2*l], tree[2*l + 1]);
            l >>= 1;
        }
    }

    int max_range(int l, int r) {
        l += size;
        r += size;

        int max_val = max(tree[l], tree[r]);
        while (l / 2 != r / 2) {
            if (!(l & 1)) {
                max_val = max(tree[l + 1], max_val);
                max_val = max(lazy[l + 1], max_val);
            }
            if (r & 1) {
                max_val = max(tree[r - 1], max_val);
                max_val = max(lazy[r - 1], max_val);
            }
            max_val = max(max_val, lazy[l]);
            max_val = max(max_val, lazy[r]);

            l >>= 1;
            r >>= 1;
        }
        max_val = max(max_val, lazy[r]);

        while (l / 2 > 0) {
            max_val = max(lazy[l], max_val);
            l >>= 1;
        }
        return max_val;
    }

    int global_max() {
        return max_range(0, n-1);
    }

    int size;
    int n;
    vector<int> tree;
    vector<int> lazy;
};

class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        vector<int> points;
        for (const auto& rect : positions) {
            points.push_back(rect[0]);
            points.push_back(rect[0] + rect[1] - 1);
        }
        sort(begin(points), end(points));
        auto new_end = unique(begin(points), end(points));
        points.resize(distance(begin(points), new_end));

        SegmentTree st(points.size());

        vector<int> results;

        int max_height = 0;
        for (const auto& rect : positions) {
            int x_1 = rect[0];
            int x_2 = rect[0] + rect[1] - 1;

            int l = distance(begin(points), lower_bound(begin(points), end(points), x_1));
            int r = distance(begin(points), lower_bound(begin(points), end(points), x_2));

            int cur_height = st.max_range(l, r);
            int new_height = rect[1] + cur_height;
            max_height = max(new_height, max_height);
            st.add_range(l, r, new_height);
            results.push_back(max_height);
        }
        return results;
    }
};
