/*
You are given the root of a binary tree with unique values, and an integer start. At minute 0, an infection starts from the node with value start.

Each minute, a node becomes infected if:

The node is currently uninfected.
The node is adjacent to an infected node.
Return the number of minutes needed for the entire tree to be infected.

 

Example 1:

image: https://assets.leetcode.com/uploads/2022/06/25/image-20220625231744-1.png

Input: root = [1,5,3,null,4,10,6,9,2], start = 3
Output: 4
Explanation: The following nodes are infected during:
- Minute 0: Node 3
- Minute 1: Nodes 1, 10 and 6
- Minute 2: Node 5
- Minute 3: Node 4
- Minute 4: Nodes 9 and 2
It takes 4 minutes for the whole tree to be infected so we return 4.

Example 2:

image: https://assets.leetcode.com/uploads/2022/06/25/image-20220625231812-2.png

Input: root = [1], start = 1
Output: 0
Explanation: At minute 0, the only node in the tree is infected so we return 0.
**********LEETCODE POTD(10/01/2024)**********
*/
#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct Node
{
    int val;
    Node *left;
    Node *right;
    Node *parent;
    Node() : val(0), left(nullptr), right(nullptr), parent(nullptr) {}
    Node(Node *parent) : val(0), left(nullptr), right(nullptr), parent(parent) {}
};

Node *required_node = new Node();

void getNewRoot(TreeNode *root, Node *cur_node, int &start)
{
    cur_node->val = root->val;
    if (cur_node->val == start)
    {
        required_node = cur_node;
    }
    if (root->left)
    {
        cur_node->left = new Node(cur_node);
        getNewRoot(root->left, cur_node->left, start);
    }
    if (root->right)
    {
        cur_node->right = new Node(cur_node);
        getNewRoot(root->right, cur_node->right, start);
    }
}

int getBFSCount(Node *root)
{
    if (!root || root->val == -1)
        return 0;
    int parent = 0;
    int left = 0;
    int right = 0;
    root->val = -1;
    if (root->parent && root->parent->val != -1)
    {
        parent = 1 + getBFSCount(root->parent);
    }
    if (root->left && root->left->val != -1)
    {
        left = 1 + getBFSCount(root->left);
    }
    if (root->right && root->right->val != -1)
    {
        right = 1 + getBFSCount(root->right);
    }
    return max(parent, max(left, right));
}

class Solution
{
public:
    int amountOfTime(TreeNode *root, int start)
    {
        Node *new_root = new Node();
        new_root->val = root->val;
        if (root->val == start)
        {
            required_node = new_root;
        }
        if (root->left)
        {
            new_root->left = new Node(new_root);
            getNewRoot(root->left, new_root->left, start);
        }
        if (root->right)
        {
            new_root->right = new Node(new_root);
            getNewRoot(root->right, new_root->right, start);
        }
        int totalCount = getBFSCount(required_node);
        return totalCount;
    }
};