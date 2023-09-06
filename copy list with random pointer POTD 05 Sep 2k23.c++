/*A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.

Construct a *****deep copy*****(https://en.wikipedia.org/wiki/Object_copying#Deep_copy) of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.

For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.

Return the head of the copied linked list.

The linked list is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:

val: an integer representing Node.val
random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not point to any node.
Your code will only be given the head of the original linked list.



Example 1:

image: https://assets.leetcode.com/uploads/2019/12/18/e1.png

Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]
Example 2:

image: https://assets.leetcode.com/uploads/2019/12/18/e2.png

Input: head = [[1,1],[2,1]]
Output: [[1,1],[2,1]]
Example 3:

image: https://assets.leetcode.com/uploads/2019/12/18/e3.png

Input: head = [[3,null],[3,0],[3,null]]
Output: [[3,null],[3,0],[3,null]]
**********LEETCODE POTD(05/09/2023)**********
*/
#include <iostream>
#include <unordered_map> 
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        unordered_map<Node *, Node *> map;

        Node *itr = head;
        while (itr)
        {
            map[itr] = new Node(itr->val);
            itr = itr->next;
        }

        itr = head;
        while (itr)
        {
            map[itr]->next = map[itr->next];
            map[itr]->random = map[itr->random];
            itr = itr->next;
        }

        return map[head];
    }
};