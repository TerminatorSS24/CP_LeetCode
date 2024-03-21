/*Given the head of a singly linked list, reverse the list, and return the reversed list.

 

Example 1:

image: https://assets.leetcode.com/uploads/2021/02/19/rev1ex1.jpg

Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]
Example 2:

image: https://assets.leetcode.com/uploads/2021/02/19/rev1ex2.jpg

Input: head = [1,2]
Output: [2,1]
Example 3:

Input: head = []
Output: []
**********LEETCODE POTD(21/03/2024)**********
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct listNode
{
    int val;
    struct ListNode *next;
} node;

node *reverseList(node *head)
{
    node *prev = NULL;
    node *current = head;
    node *next = NULL;

    while (current != NULL)
    {
        next = current->next;

        current->next = prev;

        prev = current;
        current = next;
    }

    return prev;
}

node *createNode(int val)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(node **head, int val)
{
    node *newNode = createNode(val);
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void printList(node *head)
{
    node *current = head;
    while (current != NULL)
    {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("\n");
}