/*You have n binary tree nodes numbered from 0 to n - 1 where node i has two children leftChild[i] and rightChild[i], return true if and only if all the given nodes form exactly one valid binary tree.

If node i has no left child then leftChild[i] will equal -1, similarly for the right child.

Note that the nodes have no values and that we only use the node numbers in this problem.

 

Example 1:

image: https://assets.leetcode.com/uploads/2019/08/23/1503_ex1.png

Input: n = 4, leftChild = [1,-1,3,-1], rightChild = [2,-1,-1,-1]
Output: true
Example 2:

image: https://assets.leetcode.com/uploads/2019/08/23/1503_ex2.png

Input: n = 4, leftChild = [1,-1,3,-1], rightChild = [2,3,-1,-1]
Output: false
Example 3:

image: https://assets.leetcode.com/uploads/2019/08/23/1503_ex3.png

Input: n = 2, leftChild = [1,0], rightChild = [-1,-1]
Output: false
**********LEETCODE POTD**********
*/
#include <vector>
#include <set>
using namespace std;
class Solution
{
public:
    vector<bool> visited;
    bool validate(int u, vector<int> &leftChild, vector<int> &rightChild)
    {
        if (u == -1)
            return true;
        if (visited[u])
            return false;
        visited[u] = true;
        bool left = validate(leftChild[u], leftChild, rightChild);
        bool right = validate(rightChild[u], leftChild, rightChild);
        return left && right;
    }
    bool validateBinaryTreeNodes(int n, vector<int> &leftChild, vector<int> &rightChild)
    {
        set<int> st;
        int root = -1;
        for (auto &k : leftChild)
            if (k != -1)
                st.insert(k);
        for (auto &k : rightChild)
            if (k != -1)
                st.insert(k);
        for (int i = 0; i < n; i++)
        {
            if (st.count(i) == 0)
            {
                root = i;
                break;
            }
        }
        if (root == -1)
            return false;
        visited = vector<bool>(n, 0);
        bool flag = validate(root, leftChild, rightChild);
        if (!flag)
            return false;
        for (int i = 0; i < n; i++)
            if (!visited[i])
                return false;
        return true;
    }
};
