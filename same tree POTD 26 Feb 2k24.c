/*Given the roots of two binary trees p and q, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.



Example 1:

image: https://assets.leetcode.com/uploads/2020/12/20/ex1.jpg

Input: p = [1,2,3], q = [1,2,3]
Output: true
Example 2:

image: https://assets.leetcode.com/uploads/2020/12/20/ex2.jpg

Input: p = [1,2], q = [1,null,2]
Output: false
Example 3:

image: https://assets.leetcode.com/uploads/2020/12/20/ex3.jpg

Input: p = [1,2,1], q = [1,1,2]
Output: false
**********LEETCODE POTD(26/02/2024)**********
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
bool ishere(struct TreeNode *p, struct TreeNode *q);
bool isSameTree(struct TreeNode *p, struct TreeNode *q)
{
    if (!p && !q)
        return true;
    if (p && q && p->val == q->val)
        return ishere(p, q);

    return false;
}

bool ishere(struct TreeNode *p, struct TreeNode *q)
{
    if ((isSameTree(p->left, q->left)) && (isSameTree(p->right, q->right)))
        return true;
    else
        return false;
}