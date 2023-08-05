// Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

// k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

// You may not alter the values in the list's nodes, only nodes themselves may be changed.

 

// Example 1:

// image: https://assets.leetcode.com/uploads/2020/10/03/reverse_ex1.jpg

// Input: head = [1,2,3,4,5], k = 2
// Output: [2,1,4,3,5]
// Example 2:

// image: https://assets.leetcode.com/uploads/2020/10/03/reverse_ex2.jpg

// Input: head = [1,2,3,4,5], k = 3
// Output: [3,2,1,4,5]
#include <stdio.h>
#include <stdlib.h>

struct listNode {
    int val;
    struct listNode* next;
};

struct listNode* reverseKGroup(struct listNode* head, int k) {
    struct listNode* current = head;
    struct listNode* next = NULL;
    struct listNode* prev = NULL;
    int count = 0;

    struct listNode* temp = head;
    while (count < k && temp != NULL) {
        temp = temp->next;
        count++;
    }

    if (count == k) {
        count = 0;
        while (current != NULL && count < k) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
            count++;
        }

        if (next != NULL) {
            head->next = reverseKGroup(next, k);
        }

        return prev; 
    } else {
        return head;
    }
}

struct listNode* createListNode(int val) {
    struct listNode* newNode = (struct listNode*)malloc(sizeof(struct listNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

void printLinkedList(struct listNode* head) {
    struct listNode* curr = head;

    while (curr) {
        printf("%d ", curr->val);
        curr = curr->next;
    }

    printf("\n");
}

