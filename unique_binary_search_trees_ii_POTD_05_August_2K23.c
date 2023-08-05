// Given an integer n, return all the structurally unique BST's (binary search trees), which has exactly n nodes of unique values from 1 to n. Return the answer in any order.
// Example 1:

// image: https://assets.leetcode.com/uploads/2021/01/18/uniquebstn3.jpg

// Input: n = 3
// Output: [[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]
// Example 2:

// Input: n = 1
// Output: [[1]]
#include <stdio.h>
#include <stdlib.h>

struct treeNode {
    int val;
    struct treeNode *left;
    struct treeNode *right;
};

struct treeNode* cloneTree(struct treeNode* root, int offset) {
    if (root == NULL)
        return NULL;

    struct treeNode* newNode = (struct treeNode*)malloc(sizeof(struct treeNode));
    newNode->val = root->val + offset;
    newNode->left = cloneTree(root->left, offset);
    newNode->right = cloneTree(root->right, offset);
    return newNode;
}

struct treeNode** generateTreesInRange(int start, int end, int* returnSize) {
    if (start > end) {
        *returnSize = 1;
        struct treeNode** result = (struct treeNode**)malloc(sizeof(struct treeNode*));
        result[0] = NULL;
        return result;
    }

    struct treeNode** result = NULL;
    int resultSize = 0;

    for (int i = start; i <= end; i++) {
        int leftSize, rightSize;
        struct treeNode** leftSubtrees = generateTreesInRange(start, i - 1, &leftSize);
        struct treeNode** rightSubtrees = generateTreesInRange(i + 1, end, &rightSize);

        for (int j = 0; j < leftSize; j++) {
            for (int k = 0; k < rightSize; k++) {
                struct treeNode* root = (struct treeNode*)malloc(sizeof(struct treeNode));
                root->val = i;
                root->left = cloneTree(leftSubtrees[j], 0);
                root->right = cloneTree(rightSubtrees[k], 0);

                result = (struct treeNode**)realloc(result, (resultSize + 1) * sizeof(struct treeNode*));
                result[resultSize++] = root;
            }
        }

        for (int j = 0; j < leftSize; j++) {
            free(leftSubtrees[j]);
        }
        free(leftSubtrees);

        for (int j = 0; j < rightSize; j++) {
            free(rightSubtrees[j]);
        }
        free(rightSubtrees);
    }

    *returnSize = resultSize;
    return result;
}

struct treeNode** generateTrees(int n, int* returnSize) {
    if (n == 0) {
        *returnSize = 0;
        return NULL;
    }
    return generateTreesInRange(1, n, returnSize);
}

void inorderTraversal(struct treeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->val);
        inorderTraversal(root->right);
    }
}

