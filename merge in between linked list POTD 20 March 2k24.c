/*You are given two linked lists: list1 and list2 of sizes n and m respectively.

Remove list1's nodes from the ath node to the bth node, and put list2 in their place.

The blue edges and nodes in the following figure indicate the result:

image:https://assets.leetcode.com/uploads/2020/11/05/fig1.png

Build the result list and return its head.



Example 1:

image: https://assets.leetcode.com/uploads/2024/03/01/ll.png

Input: list1 = [10,1,13,6,9,5], a = 3, b = 4, list2 = [1000000,1000001,1000002]
Output: [10,1,13,1000000,1000001,1000002,5]
Explanation: We remove the nodes 3 and 4 and put the entire list2 in their place. The blue edges and nodes in the above figure indicate the result.
Example 2:

image: https://assets.leetcode.com/uploads/2020/11/05/merge_linked_list_ex2.png

Input: list1 = [0,1,2,3,4,5,6], a = 2, b = 5, list2 = [1000000,1000001,1000002,1000003,1000004]
Output: [0,1,1000000,1000001,1000002,1000003,1000004,6]
Explanation: The blue edges and nodes in the above figure indicate the result.
**********LEETCODE POTD(20/03/2024)**********
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *mergeInBetween(struct ListNode *list1, int a, int b, struct ListNode *list2)
{

    struct ListNode *temp = NULL;
    struct ListNode *travel = list1;
    int cnt = 1;

    while (cnt < a)
    {
        travel = travel->next;
        cnt++;
    }

    temp = travel->next;
    travel->next = list2;

    while (list2->next != NULL)
    {
        list2 = list2->next;
    }

    while (cnt <= b)
    {
        temp = temp->next;
        cnt++;
    }

    list2->next = temp;

    return list1;
}