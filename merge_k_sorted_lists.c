// You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

// Merge all the linked-lists into one sorted linked-list and return it.

 

// Example 1:

// Input: lists = [[1,4,5],[1,3,4],[2,6]]
// Output: [1,1,2,3,4,4,5,6]
// Explanation: The linked-lists are:
// [
//   1->4->5,
//   1->3->4,
//   2->6
// ]
// merging them into one sorted list:
// 1->1->2->3->4->4->5->6
// Example 2:

// Input: lists = []
// Output: []
// Example 3:

// Input: lists = [[]]
// Output: []
#include <stdio.h>
#include <stdlib.h>

struct listNode {
    int val;
    struct listNode* next;
};

struct listNode* mergeKLists(struct listNode** lists, int listsSize) {
    struct listNode* mergedList = NULL;
    struct listNode* tail = NULL;

    while (1) {
        struct listNode* smallestNode = NULL;
        int smallestIndex = -1;

        for (int i = 0; i < listsSize; i++) {
            if (lists[i] != NULL && (smallestNode == NULL || lists[i]->val < smallestNode->val)) {
                smallestNode = lists[i];
                smallestIndex = i;
            }
        }

        if (smallestNode == NULL) {
            break;
        }

        if (mergedList == NULL) {
            mergedList = smallestNode;
            tail = smallestNode;
        } else {
            tail->next = smallestNode;
            tail = smallestNode;
        }

        lists[smallestIndex] = smallestNode->next;
    }

    return mergedList;
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

