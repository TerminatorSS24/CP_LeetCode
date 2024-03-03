/*Given the head of a linked list, remove the nth node from the end of the list and return its head.

 

Example 1:

image:https://assets.leetcode.com/uploads/2020/10/03/remove_ex1.jpg

Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
Example 2:

Input: head = [1], n = 1
Output: []
Example 3:

Input: head = [1,2], n = 1
Output: [1]*/
#include <bits/stdc++.h>
using namespace std;
void fastIO() { ios_base::sync_with_stdio(false); }
#define lint long long int
#define tc    \
    int t;    \
    cin >> t; \
    while (t--)
#define vecint vector<int>
#define MOD 1000000007

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        ListNode *first = dummy;
        ListNode *second = dummy;
        for (int i = 0; i <= n; i++)
            second = second->next;
        while (second != nullptr)
        {
            first = first->next;
            second = second->next;
        }
        ListNode *nodeToRemove = first->next;
        first->next = first->next->next;
        delete nodeToRemove;

        ListNode *newHead = dummy->next;
        delete dummy;

        return newHead;
    }
};

int main()
{

    return 0;
}