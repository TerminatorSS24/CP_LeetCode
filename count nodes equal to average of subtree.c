/*Given the root of a binary tree, return the number of nodes where the value of the node is equal to the average of the values in its subtree.

Note:

The average of n elements is the sum of the n elements divided by n and rounded down to the nearest integer.
A subtree of root is a tree consisting of root and all of its descendants.
 

Example 1:

image: https://assets.leetcode.com/uploads/2022/03/15/image-20220315203925-1.png

Input: root = [4,8,5,0,1,null,6]
Output: 5
Explanation: 
For the node with value 4: The average of its subtree is (4 + 8 + 5 + 0 + 1 + 6) / 6 = 24 / 6 = 4.
For the node with value 5: The average of its subtree is (5 + 6) / 2 = 11 / 2 = 5.
For the node with value 0: The average of its subtree is 0 / 1 = 0.
For the node with value 1: The average of its subtree is 1 / 1 = 1.
For the node with value 6: The average of its subtree is 6 / 1 = 6.
Example 2:

image: https://assets.leetcode.com/uploads/2022/03/26/image-20220326133920-1.png

Input: root = [1]
Output: 1
Explanation: For the node with value 1: The average of its subtree is 1 / 1 = 1.
**********LEETCODE POTD(02/11/2023)**********
*/
#include<stdio.h>
#include<stdlib.h>
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct ansNode
{
    int sum;
    int count;
};

int ans;

struct ansNode solve(struct TreeNode *root)
{
    struct ansNode node;
    if (root == NULL)
    {
        node.sum = 0;
        node.count = 0;
        return node;
    }

    struct ansNode l = solve(root->left);
    struct ansNode r = solve(root->right);

    int curSum = root->val + l.sum + r.sum;
    int num = 1 + l.count + r.count;

    if ((curSum / num) == root->val)
        ans++;

    node.sum = curSum;
    node.count = num;
    return node;
}

int averageOfSubtree(struct TreeNode *root)
{
    ans = 0;
    solve(root);
    return ans;
}