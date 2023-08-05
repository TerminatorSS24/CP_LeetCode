// A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.

// The path sum of a path is the sum of the node's values in the path.

// Given the root of a binary tree, return the maximum path sum of any non-empty path.

 

// Example 1:

// image: https://assets.leetcode.com/uploads/2020/10/13/exx1.jpg

// Input: root = [1,2,3]
// Output: 6
// Explanation: The optimal path is 2 -> 1 -> 3 with a path sum of 2 + 1 + 3 = 6.
// Example 2:

// image: https://assets.leetcode.com/uploads/2020/10/13/exx2.jpg

// Input: root = [-10,9,20,null,null,15,7]
// Output: 42
// Explanation: The optimal path is 15 -> 20 -> 7 with a path sum of 15 + 20 + 7 = 42.
#include <stdio.h>
#include <stdlib.h>
#include<limits.h>

struct treeNode {
    int val;
    struct treeNode *left;
    struct treeNode *right;
};

int maxPathSumHelper(struct treeNode* root, int* maxSum) {
    if (root == NULL) {
        return 0;
    }

    int leftSum = maxPathSumHelper(root->left, maxSum);
    int rightSum = maxPathSumHelper(root->right, maxSum);

    int currentPathSum = root->val + (leftSum > 0 ? leftSum : 0) + (rightSum > 0 ? rightSum : 0);
    *maxSum = (*maxSum > currentPathSum) ? *maxSum : currentPathSum;

    return root->val + (leftSum > rightSum ? (leftSum > 0 ? leftSum : 0) : (rightSum > 0 ? rightSum : 0));
}

int maxPathSum(struct treeNode* root) {
    int maxSum = INT_MIN;
    maxPathSumHelper(root, &maxSum);
    return maxSum;
}

struct treeNode* createNode(int val) {
    struct treeNode* newNode = (struct treeNode*)malloc(sizeof(struct treeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
