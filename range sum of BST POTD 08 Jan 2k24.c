/*
Given the root node of a binary search tree and two integers low and high, return the sum of values of all nodes with a value in the inclusive range [low, high].

 

Example 1:

image: https://assets.leetcode.com/uploads/2020/11/05/bst1.jpg

Input: root = [10,5,15,3,7,null,18], low = 7, high = 15
Output: 32
Explanation: Nodes 7, 10, and 15 are in the range [7, 15]. 7 + 10 + 15 = 32.
Example 2:

image:https://assets.leetcode.com/uploads/2020/11/05/bst2.jpg

Input: root = [10,5,15,3,7,13,18,1,null,6], low = 6, high = 10
Output: 23
Explanation: Nodes 6, 7, and 10 are in the range [6, 10]. 6 + 7 + 10 = 23.
*/
#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int rangeSumBST(struct TreeNode *root, int low, int high)
{
    if (root == NULL)
        return 0;

    int sum = 0;

    if (root->val >= low && root->val <= high)
        sum += root->val;

    sum += rangeSumBST(root->left, low, high);
    sum += rangeSumBST(root->right, low, high);

    return sum;
}