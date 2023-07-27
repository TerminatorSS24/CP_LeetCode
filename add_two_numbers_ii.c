// You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

// Example 1:
// the picture-  https://assets.leetcode.com/uploads/2021/04/09/sumii-linked-list.jpg
// Input: l1 = [7,2,4,3], l2 = [5,6,4]
// Output: [7,8,0,7]
// Example 2:

// Input: l1 = [2,4,3], l2 = [5,6,4]
// Output: [8,0,7]
// Example 3:

// Input: l1 = [0], l2 = [0]
// Output: [0]
#include <stdio.h>
#include <stdlib.h>

struct listNode
{
    int val;
    struct listNode *next;
};

struct listNode *createNode(int val)
{
    struct listNode *newNode = (struct listNode *)malloc(sizeof(struct listNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

void pushToStack(struct listNode *head, struct listNode **stack, int *stackSize)
{
    struct listNode *current = head;
    while (current)
    {
        stack[*stackSize] = current;
        (*stackSize)++;
        current = current->next;
    }
}

struct listNode *addTwoNumbers(struct listNode *l1, struct listNode *l2)
{
    struct listNode *stack1[1000];
    struct listNode *stack2[1000];
    int stackSize1 = 0;
    int stackSize2 = 0;

    pushToStack(l1, stack1, &stackSize1);
    pushToStack(l2, stack2, &stackSize2);

    int carry = 0;
    struct listNode *result = NULL;

    while (stackSize1 > 0 || stackSize2 > 0 || carry)
    {
        int sum = carry;
        if (stackSize1 > 0)
        {
            stackSize1--;
            sum += stack1[stackSize1]->val;
        }
        if (stackSize2 > 0)
        {
            stackSize2--;
            sum += stack2[stackSize2]->val;
        }

        carry = sum / 10;
        struct listNode *newNode = createNode(sum % 10);
        newNode->next = result;
        result = newNode;
    }

    return result;
}

void printLinkedList(struct listNode *head)
{
    struct listNode *current = head;
    while (current)
    {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("\n");
}
