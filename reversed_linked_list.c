#include <stdio.h>
#include <stdlib.h>

struct listNode {
    int val;
    struct ListNode *next;
};

struct listNode* reverseList(struct listNode* head) {
    struct listNode *prev = NULL;
    struct listNode *current = head;
    struct listNode *next = NULL;

    while (current != NULL) {
        next = current->next;

        current->next = prev;

        prev = current;
        current = next;
    }

   
    return prev;
}

struct listNode* createNode(int val) {
    struct listNode* newNode = (struct listNode*)malloc(sizeof(struct listNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}


void insertEnd(struct listNode** head, int val) {
    struct listNode* newNode = createNode(val);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct listNode* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}


void printList(struct listNode* head) {
    struct listNode* current = head;
    while (current != NULL) {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("\n");
}

