/*You are given the root of a binary tree. We install cameras on the tree nodes where each camera at a node can monitor its parent, itself, and its immediate children.

Return the minimum number of cameras needed to monitor all nodes of the tree.

 

Example 1:


Input: root = [0,0,null,0,0]
Output: 1
Explanation: One camera is enough to monitor all nodes if placed as shown.
Example 2:


Input: root = [0,0,null,0,null,0,null,null,0]
Output: 2
Explanation: At least two cameras are needed to monitor all nodes of the tree. The above image shows one of the valid configurations of camera placement.*/
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int timer = 1;
    
    void pre(TreeNode* root) {
        root->val = timer++;
        if (root->left) {
            pre(root->left);
        }
        if (root->right) {
            pre(root->right);
        }
    }
    
    int dp[1001][2][2];
    
    int solve(TreeNode* root, int cam, int par) {
        if (dp[root->val][cam][par] != -1) {
            return dp[root->val][cam][par];
        }
        int ans = 0;
        if (cam) {
            ans += 1;
            if (root->left) {
                ans += min(solve(root->left, 0, 1), solve(root->left, 1, 1));
            }
            if (root->right) {
                ans += min(solve(root->right, 0, 1), solve(root->right, 1, 1));
            }
        }
        else if (!cam && par) {
            if (root->left) {
                ans += min(solve(root->left, 0, 0), solve(root->left, 1, 0));
            }
            if (root->right) {
                ans += min(solve(root->right, 0, 0), solve(root->right, 1, 0));
            }
        }
        else {
            if (!root->left && !root->right) {
                return 1e5;
            }
            else if (root->left && !root->right) {
                ans += solve(root->left, 1, 0);
            }
            else if (root->right && !root->left) {
                ans += solve(root->right, 1, 0);
            }
            else {
                int a = solve(root->left, 1, 0) + min(solve(root->right, 1, 0), solve(root->right, 0, 0));
                int b = solve(root->right, 1, 0) + min(solve(root->left, 1, 0), solve(root->left, 0, 0));
                ans += min(a, b);
            }
        }
        return dp[root->val][cam][par] = ans;
    }
    
    int minCameraCover(TreeNode* root) {
        pre(root);
        memset(dp, -1, sizeof(dp));
        return min(solve(root, 0, 0), solve(root, 1, 0));
    }
};
