/*Given the root of a binary tree, return an array of the largest value in each row of the tree (0-indexed).

Example 1:

image: https://assets.leetcode.com/uploads/2020/08/21/largest_e1.jpg

Input: root = [1,3,2,5,3,null,9]
Output: [1,3,9]
Example 2:

Input: root = [1,2,3]
Output: [1,3]
**********LEETCODE POTD(24/10/2023)**********
*/



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
int *largestValues(struct TreeNode *root, int *returnSize)
{
    int *result = (int *)malloc(sizeof(int) * 10000);
    *returnSize = 0;
    if (!root)
        return result;
    struct TreeNode **queue = (struct TreeNode **)malloc(sizeof(struct TreeNode *) * 10000);
    queue[0] = root;
    int front = 0, rear = 1, end = 0, next_end = 0, max = root->val;
    while (front != rear)
    {
        if (queue[front]->left)
        {
            queue[rear] = queue[front]->left;
            next_end++;
            rear++;
        }
        if (queue[front]->right)
        {
            queue[rear] = queue[front]->right;
            next_end++;
            rear++;
        }

        if (queue[front]->val > max)
            max = queue[front]->val;

        if (front == end)
        {
            end = next_end;
            result[*returnSize] = max;
            (*returnSize)++;
            if (front + 1 != rear)
                max = queue[front + 1]->val;
        }
        front++;
    }
    return result;
}