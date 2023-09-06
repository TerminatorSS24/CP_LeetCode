/*Given the root of a binary tree, calculate the vertical order traversal of the binary tree.

For each node at position (row, col), its left and right children will be at positions (row + 1, col - 1) and (row + 1, col + 1) respectively. The root of the tree is at (0, 0).

The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each column index starting from the leftmost column and ending on the rightmost column. There may be multiple nodes in the same row and same column. In such a case, sort these nodes by their values.

Return the vertical order traversal of the binary tree.



Example 1:

image: https://assets.leetcode.com/uploads/2021/01/29/vtree1.jpg

Input: root = [3,9,20,null,null,15,7]
Output: [[9],[3,15],[20],[7]]
Explanation:
Column -1: Only node 9 is in this column.
Column 0: Nodes 3 and 15 are in this column in that order from top to bottom.
Column 1: Only node 20 is in this column.
Column 2: Only node 7 is in this column.
Example 2:

image: https://assets.leetcode.com/uploads/2021/01/29/vtree2.jpg

Input: root = [1,2,3,4,5,6,7]
Output: [[4],[2],[1,5,6],[3],[7]]
Explanation:
Column -2: Only node 4 is in this column.
Column -1: Only node 2 is in this column.
Column 0: Nodes 1, 5, and 6 are in this column.
          1 is at the top, so it comes first.
          5 and 6 are at the same position (2, 0), so we order them by their value, 5 before 6.
Column 1: Only node 3 is in this column.
Column 2: Only node 7 is in this column.
Example 3:

image: https://assets.leetcode.com/uploads/2021/01/29/vtree3.jpg

Input: root = [1,2,3,4,6,5,7]
Output: [[4],[2],[1,5,6],[3],[7]]
Explanation:
This case is the exact same as example 2, but with nodes 5 and 6 swapped.
Note that the solution remains the same since 5 and 6 are in the same location and should be ordered by their values.*/
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

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
     vector<vector<int>> verticalTraversal(TreeNode *root)
     {
         vector<vector<int>> ret;
         map<int, map<int, vector<int>>> mp;
         queue<pair<TreeNode *, pair<int, int>>> nodes;

         nodes.push(make_pair(root, make_pair(0, 0)));
         while (nodes.size())
         {
             auto [node, rowcol] = nodes.front();
             nodes.pop();
             mp[rowcol.second][rowcol.first].push_back(node->val);
             if (node->left)
                 nodes.push(make_pair(node->left, make_pair(rowcol.first + 1, rowcol.second - 1)));
             if (node->right)
                 nodes.push(make_pair(node->right, make_pair(rowcol.first + 1, rowcol.second + 1)));
         }

         for (const auto &[_, rowmp] : mp)
         {
             vector<int> colvec;
             for (auto [_, v] : rowmp)
             {
                 sort(v.begin(), v.end());
                 colvec.insert(colvec.end(), v.begin(), v.end());
             }
             ret.push_back(colvec);
         }
         return ret;
     }
 };
