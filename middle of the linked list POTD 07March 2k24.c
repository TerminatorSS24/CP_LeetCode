
/*Given the head of a singly linked list, return the middle node of the linked list.

If there are two middle nodes, return the second middle node.

 

Example 1:

image:https://assets.leetcode.com/uploads/2021/07/23/lc-midlist1.jpg

Input: head = [1,2,3,4,5]
Output: [3,4,5]
Explanation: The middle node of the list is node 3.
Example 2:

image: https://assets.leetcode.com/uploads/2021/07/23/lc-midlist2.jpg

Input: head = [1,2,3,4,5,6]
Output: [4,5,6]
Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.
**********LEETCODE POTD(07/03/2024)**********
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *middleNode(struct ListNode *head)
{
    struct ListNode *slowPointer = head;
    struct ListNode *fastPointer = head;
    while (fastPointer != NULL && fastPointer->next != NULL)
    {
        slowPointer = slowPointer->next;
        fastPointer = fastPointer->next->next;
    }
    return slowPointer;
}