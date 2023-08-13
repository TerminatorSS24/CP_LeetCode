/*You have k lists of sorted integers in non-decreasing order. Find the smallest range that includes at least one number from each of the k lists.

We define the range [a, b] is smaller than range [c, d] if b - a < d - c or a < c if b - a == d - c.

 

Example 1:

Input: nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
Output: [20,24]
Explanation: 
List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
List 2: [0, 9, 12, 20], 20 is in range [20,24].
List 3: [5, 18, 22, 30], 22 is in range [20,24].
Example 2:

Input: nums = [[1,2,3],[1,2,3],[1,2,3]]
Output: [1,1]*/
#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Node {
public:
    int data, row, col;
    Node(int val, int r, int c) {
        data = val;
        row = r;
        col = c;
    }
};

class compare {
public:
    bool operator()(Node* a, Node* b) {
        return a->data > b->data;
    }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<int> ans;
        int k = nums.size();

        priority_queue<Node*, vector<Node*>, compare> minheap;
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for (int i = 0; i < k; i++) {
            int ele = nums[i][0];
            maxi = max(maxi, ele);
            mini = min(mini, ele);
            minheap.push(new Node(ele, i, 0));
        }
        int ansStart = mini;
        int ansEnd = maxi;

        while (!minheap.empty()) {
            Node* temp = minheap.top();
            int ele = temp->data;
            int row = temp->row;
            int col = temp->col;
            minheap.pop();

            mini = ele;
            int curr = maxi - mini;
            int ansrange = ansEnd - ansStart;
            if (curr < ansrange) {
                ansStart = mini;
                ansEnd = maxi;
            }
            if (col + 1 < nums[row].size()) {
                maxi = max(maxi, nums[row][col + 1]);
                Node* newNode = new Node(nums[row][col + 1], row, col + 1);
                minheap.push(newNode);
            } else
                break;
        }
        ans.push_back(ansStart);
        ans.push_back(ansEnd);
        return ans;
    }
};