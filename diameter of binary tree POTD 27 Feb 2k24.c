/*Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.



Example 1:

image: https://assets.leetcode.com/uploads/2021/03/06/diamtree.jpg

Input: root = [1,2,3,4,5]
Output: 3
Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].
Example 2:

Input: root = [1,2]
Output: 1
**********LEETCODE POTD(27/02/2024)**********
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
int max(int a, int b) { return a > b ? a : b; }

int height(struct TreeNode *root)
{

    if (root == NULL)
        return 0;

    int leftHeight = height(root->left);

    int rightHeight = height(root->right);

    return 1 + max(leftHeight, rightHeight);
}

int diameterOfBinaryTree(struct TreeNode *root)
{

    if (root == NULL)
        return 0;
    int left = height(root->left);

    int right = height(root->right);

    int currentDiameter = left + right;

    int leftDiameter = diameterOfBinaryTree(root->left);

    int rightDiameter = diameterOfBinaryTree(root->right);
    return max(currentDiameter, max(leftDiameter, rightDiameter));
}