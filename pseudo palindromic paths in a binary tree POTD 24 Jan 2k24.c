/*
Given a binary tree where node values are digits from 1 to 9. A path in the binary tree is said to be pseudo-palindromic if at least one permutation of the node values in the path is a palindrome.

Return the number of pseudo-palindromic paths going from the root node to leaf nodes.

 

Example 1:

image: https://assets.leetcode.com/uploads/2020/05/06/palindromic_paths_1.png

Input: root = [2,3,1,3,1,null,1]
Output: 2 
Explanation: The figure above represents the given binary tree. There are three paths going from the root node to leaf nodes: the red path [2,3,3], the green path [2,1,1], and the path [2,3,1]. Among these paths only red path and green path are pseudo-palindromic paths since the red path [2,3,3] can be rearranged in [3,2,3] (palindrome) and the green path [2,1,1] can be rearranged in [1,2,1] (palindrome).
Example 2:

image: https://assets.leetcode.com/uploads/2020/05/07/palindromic_paths_2.png

Input: root = [2,1,1,1,3,null,null,null,null,null,1]
Output: 1 
Explanation: The figure above represents the given binary tree. There are three paths going from the root node to leaf nodes: the green path [2,1,1], the path [2,1,3,1], and the path [2,1]. Among these paths only the green path is pseudo-palindromic since [2,1,1] can be rearranged in [1,2,1] (palindrome).
Example 3:

Input: root = [9]
Output: 1
**********LEETCODE POTD(24/01/2024)**********
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
int analysis(int *count)
{
    int odd_count = 0;
    for (int i = 1; i < 10; i++)
    {
        if (count[i] % 2 == 1)
            odd_count++;
        if (odd_count > 1)
            return 0;
    }
    return 1;
}
void generate(struct TreeNode *root, int *res, int *count)
{
    if (!root)
        return;
    count[root->val]++;
    if (!root->left && !root->right)
    {
        (*res) += analysis(count);
        count[root->val]--;
        return;
    }
    generate(root->left, res, count);
    generate(root->right, res, count);
    count[root->val]--;
}
int pseudoPalindromicPaths(struct TreeNode *root)
{
    int count[10] = {0};
    int res = 0;
    generate(root, &res, count);
    return res;
}