/*Given the root of a binary tree, return the inorder traversal of its nodes' values.

 

Example 1:

image: https://assets.leetcode.com/uploads/2020/09/15/inorder_1.jpg

Input: root = [1,null,2,3]
Output: [1,3,2]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [1]
Output: [1]*/
#include<stdio.h>
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int count(struct TreeNode *root)
{
    int lc, rc;
    if (root == NULL)
        return 0;
    return count(root->left) + count(root->right) + 1;
}
static int b = 0;
int a[101] = {0};
void inorder(struct TreeNode *p)
{
    if (p != NULL)
    {
        inorder(p->left);
        a[b++] = p->val;
        inorder(p->right);
    }
}
int *inorderTraversal(struct TreeNode *root, int *returnSize)
{
    inorder(root);
    int c = 0;
    int *z = (int *)malloc(sizeof(int) * b);
    for (int i = 0; i < b; i++)
    {
        z[i] = a[i];
    }
    *returnSize = b;
    b = 0;
    return z;
}