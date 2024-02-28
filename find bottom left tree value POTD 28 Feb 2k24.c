/**
Given the root of a binary tree, return the leftmost value in the last row of the tree.

 

Example 1:

image: https://assets.leetcode.com/uploads/2020/12/14/tree1.jpg

Input: root = [2,1,3]
Output: 1
Example 2:

image:https://assets.leetcode.com/uploads/2020/12/14/tree2.jpg

Input: root = [1,2,3,4,null,5,6,null,null,7]
Output: 7 
**********LEETCODE POTD(28/02/2024)**********
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
typedef struct TreeNode TreeNode_t;
typedef struct
{
    int val;
    int depth;
} LeftMost_t;

void traverse(LeftMost_t *leftMost, TreeNode_t *node, int depth)
{
    if (leftMost->depth < depth)
        *leftMost = (LeftMost_t){.val = node->val, .depth = depth};

    if (node->left)
        traverse(leftMost, node->left, depth + 1);
    if (node->right)
        traverse(leftMost, node->right, depth + 1);
}

int findBottomLeftValue(TreeNode_t *root)
{
    LeftMost_t leftMost = {.val = 0, .depth = 0};
    traverse(&leftMost, root, 1);
    return leftMost.val;
}