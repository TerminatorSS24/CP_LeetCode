/*You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.



Example 1:

image: https://assets.leetcode.com/uploads/2021/03/04/reorder1linked-list.jpg

Input: head = [1,2,3,4]
Output: [1,4,2,3]
Example 2:

image: https://assets.leetcode.com/uploads/2021/03/09/reorder2-linked-list.jpg

Input: head = [1,2,3,4,5]
Output: [1,5,2,4,3]
**********LEETCODE POTD(23/03/2024)**********
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *getLastAndDelete(struct ListNode *head)
{
    struct ListNode *temp = head, *temp1;
    while (temp->next != NULL)
    {
        temp1 = temp;
        temp = temp->next;
    }
    temp1->next = NULL;
    return temp;
}

void reorderList(struct ListNode *head)
{
    struct ListNode *temp = head, *temp1, *temp2;
    while (temp != NULL)
    {
        if (temp->next == NULL)
        {
            break;
        }
        temp1 = getLastAndDelete(temp);
        temp2 = temp->next;
        temp1->next = temp2;
        temp->next = temp1;
        temp = temp2;
    }
}