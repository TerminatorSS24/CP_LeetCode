/*Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

 

Example 1:

image: https://assets.leetcode.com/uploads/2021/01/04/partition.jpg 

Input: head = [1,4,3,2,5,2], x = 3
Output: [1,2,2,4,3,5]
Example 2:

Input: head = [2,1], x = 2
Output: [1,2]
**********LEETCODE POTD(15/08/2023)**********
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int val;
    struct ListNode *next;
} ListNode;

struct ListNode* partition(struct ListNode* head, int x){
    if (head == NULL) return head;
    ListNode* smaller = (ListNode*)malloc(sizeof(ListNode)); 
    smaller->val = 0;
    ListNode* smallerTail = smaller;
        
    ListNode* greater = (ListNode*)malloc(sizeof(ListNode));
    greater->val = 0;
    ListNode* greaterTail = greater; 
        
    ListNode* curr = head;
    while (curr) {
        if (curr->val < x) {
            smallerTail->next = curr;
            smallerTail = smallerTail->next;
        } 
        else {
            greaterTail->next = curr;
            greaterTail = greaterTail->next;
        }
        curr = curr->next;
    }
        
    greaterTail->next = NULL; 
    smallerTail->next = greater->next;
        
    head = smaller->next; 
       
    free(smaller);  // Free the auxiliary nodes
    free(greater);
       
    return head;
}
