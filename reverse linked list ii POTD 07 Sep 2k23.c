/*Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.

 

Example 1:

image: https://assets.leetcode.com/uploads/2021/02/19/rev2ex2.jpg

Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]
Example 2:

Input: head = [5], left = 1, right = 1
Output: [5]
**********LEETCODE POTD(07/09/2023)**********
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct ListNode ListNode;

ListNode *reverseBetween(ListNode *const pHead, const int left, const int right) {
    assert(left >= 1 && left <= right);

    struct ListNode dummyHead;
    dummyHead.next = pHead;

    ListNode *pPrevLeft = &dummyHead;

    for (int cntDown = left - 1; cntDown > 0; cntDown -= 1) {
        pPrevLeft = pPrevLeft->next;
    }

    ListNode *pPrev = pPrevLeft->next, *pCur = pPrev->next;

    for (int cntDown = right - left; cntDown > 0; cntDown -= 1) {
        assert(pCur != NULL);
        ListNode *const pNext = pCur->next;

        pCur->next = pPrev;

        pPrev = pCur;
        pCur = pNext;
    }

    (pPrevLeft->next)->next = pCur;
    pPrevLeft->next = pPrev;

    return dummyHead.next;
}

struct ListNode *createNode(int val) {
    struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

void printList(struct ListNode *head) {
    struct ListNode *current = head;
    while (current != NULL) {
        printf("%d -> ", current->val);
        current = current->next;
    }
    printf("NULL\n");
}
