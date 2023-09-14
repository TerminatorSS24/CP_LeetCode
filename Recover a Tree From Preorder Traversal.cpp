/*We run a preorder depth-first search (DFS) on the root of a binary tree.

At each node in this traversal, we output D dashes (where D is the depth of this node), then we output the value of this node.  If the depth of a node is D, the depth of its immediate child is D + 1.  The depth of the root node is 0.

If a node has only one child, that child is guaranteed to be the left child.

Given the output traversal of this traversal, recover the tree and return its root.



Example 1:

image: https://assets.leetcode.com/uploads/2019/04/08/recover-a-tree-from-preorder-traversal.png

Input: traversal = "1-2--3--4-5--6--7"
Output: [1,2,5,3,4,6,7]
Example 2:

image: https://assets.leetcode.com/uploads/2019/04/11/screen-shot-2019-04-10-at-114101-pm.png

Input: traversal = "1-2--3---4-5--6---7"
Output: [1,2,5,3,null,6,null,4,null,7]
Example 3:

image: https://assets.leetcode.com/uploads/2019/04/11/screen-shot-2019-04-10-at-114955-pm.png

Input: traversal = "1-401--349---90--88"
Output: [1,401,null,349,88,90]*/
#include <iostream>
#include <stack>
#include <string>

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

class Solution
{
public:
    TreeNode *recoverFromPreorder(string trav)
    {
        stack<TreeNode *> s;
        int i = 0;
        while (i < trav.size())
        {
            int lev = 0, j = i;
            while (j < trav.size() && trav[j] == '-')
            {
                j++;
                lev++;
            }
            int val = 0;
            while (j < trav.size() && trav[j] != '-')
            {
                val = 10 * val + (trav[j] - '0');
                j++;
            }
            TreeNode *newnode = new TreeNode(val);
            while (s.size() > lev)
                s.pop();
            if (!s.empty())
            {
                if (s.top()->left)
                    s.top()->right = newnode;
                else
                    s.top()->left = newnode;
            }
            s.push(newnode);
            i = j;
        }
        if (s.empty())
            return NULL;
        while (s.size() > 1)
            s.pop();
        return s.top();
    }
};