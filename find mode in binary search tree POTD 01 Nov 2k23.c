/*Given the root of a binary search tree (BST) with duplicates, return all the mode(s) (i.e., the most frequently occurred element) in it.

If the tree has more than one mode, return them in any order.

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than or equal to the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.
 

Example 1:


Input: root = [1,null,2,2]
Output: [2]
Example 2:

Input: root = [0]
Output: [0]
**********LEETCODE POTD(01/11/2023)**********
*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Definition for a binary tree node
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int cnt;
int maxCnt;
int prev;
int resTop;
int *res;

void inOrder(struct TreeNode *root)
{
    if (!root)
        return;

    inOrder(root->left);

    if (root->val == prev)
    {
        cnt++;
    }
    else
    {
        cnt = 1;
        prev = root->val;
    }

    if (cnt == maxCnt)
    {
        res[resTop++] = root->val;
    }
    else if (cnt > maxCnt)
    {
        resTop = 0;
        res[resTop++] = root->val;
        maxCnt = cnt;
    }
    inOrder(root->right);
}

int *findMode(struct TreeNode *root, int *returnSize)
{
    cnt = 0;
    maxCnt = 0;
    prev = INT_MIN;
    resTop = 0;
    res = (int *)malloc(sizeof(int) * 10000);

    inOrder(root);
    *returnSize = resTop;
    return res;
}
