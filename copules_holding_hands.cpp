/*There are n couples sitting in 2n seats arranged in a row and want to hold hands.

The people and seats are represented by an integer array row where row[i] is the ID of the person sitting in the ith seat. The couples are numbered in order, the first couple being (0, 1), the second couple being (2, 3), and so on with the last couple being (2n - 2, 2n - 1).

Return the minimum number of swaps so that every couple is sitting side by side. A swap consists of choosing any two people, then they stand up and switch seats.

 

Example 1:

Input: row = [0,2,1,3]
Output: 1
Explanation: We only need to swap the second (row[1]) and third (row[2]) person.
Example 2:

Input: row = [3,2,0,1]
Output: 0
Explanation: All couples are already seated side by side.*/
#include <iostream>
#include <vector>

using namespace std;

class UnionFind {
    vector<int> parent;

public:
    UnionFind(int n) {
        for (int i = 0; i < n; i++) {
            parent.push_back(i);
        }
    }

    int find(int x) {
        int root = x;
        while (root != parent[root])
            root = parent[root];

        while (x != root) {
            int t = parent[x];
            parent[x] = root;
            x = t;
        }
        return root;
    }

    void union_(int &x, int &y) {
        int xSet = find(x);
        int ySet = find(y);

        if (xSet == ySet)
            return;

        if (xSet < ySet)
            parent[ySet] = xSet;
        else
            parent[xSet] = ySet;
    }
};

class Solution {
public:
    int minSwapsCouples(vector<int> &row) {
        int n = row.size();
        UnionFind obj(n);
        int count = 0;
        for (int i = 0; i < n; i += 2) {
            obj.union_(row[i], row[i + 1]);
        }

        for (int i = 0; i < n; i += 2) {
            int set1 = obj.find(i);
            int set2 = obj.find(i + 1);

            if (set1 == set2)
                continue;
            count++;
            obj.union_(set1, set2);
        }
        return count;
    }
};
