/*
Consider all the leaves of a binary tree, from left to right order, the values of those leaves form a leaf value sequence.

image: https://s3-lc-upload.s3.amazonaws.com/uploads/2018/07/16/tree.png

For example, in the given tree above, the leaf value sequence is (6, 7, 4, 9, 8).

Two binary trees are considered leaf-similar if their leaf value sequence is the same.

Return true if and only if the two given trees with head nodes root1 and root2 are leaf-similar.

 

Example 1:

image: https://assets.leetcode.com/uploads/2020/09/03/leaf-similar-1.jpg

Input: root1 = [3,5,1,6,2,9,8,null,null,7,4], root2 = [3,5,1,6,7,4,2,null,null,null,null,null,null,9,8]
Output: true
Example 2:

image: https://assets.leetcode.com/uploads/2020/09/03/leaf-similar-2.jpg

Input: root1 = [1,2,3], root2 = [1,3,2]
Output: false
**********LEETCODE POTD(09/01/2024)**********
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

int Search_Tree(struct TreeNode *root, int *stack, int *stack_cnt)
{
    if (root == NULL)
        return -1;

    int ret_val = 0;
    ret_val += Search_Tree(root->left, stack, stack_cnt);
    ret_val += Search_Tree(root->right, stack, stack_cnt);

    if (-2 == ret_val)
    {
        stack[*stack_cnt] = root->val;
        *stack_cnt += 1;
    }

    return 1;
}

bool leafSimilar(struct TreeNode *root1, struct TreeNode *root2)
{
    int *stack1 = (int *)malloc(sizeof(int) * 200);
    int stack1_cnt = 0;

    int *stack2 = (int *)malloc(sizeof(int) * 200);
    int stack2_cnt = 0;

    Search_Tree(root1, stack1, &stack1_cnt);
    Search_Tree(root2, stack2, &stack2_cnt);

    if (stack1_cnt != stack2_cnt)
        return false;
    else
    {
        for (int i = 0; i < stack1_cnt; i++)
        {
            if (stack1[i] != stack2[i])
                return false;
        }
    }

    return true;
}