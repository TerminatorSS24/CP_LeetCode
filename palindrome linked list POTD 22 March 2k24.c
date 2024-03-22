/*Given the head of a singly linked list, return true if it is a palindrome(A palindrome is a sequence that reads the same forward and backward.) or false otherwise.

 

Example 1:

image: https://assets.leetcode.com/uploads/2021/03/03/pal1linked-list.jpg

Input: head = [1,2,2,1]
Output: true
Example 2:

image: https://assets.leetcode.com/uploads/2021/03/03/pal2linked-list.jpg

Input: head = [1,2]
Output: false
**********LEETCODE POTD(22/03/2024)**********
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

bool isPalindrome(struct ListNode *head)
{
    struct ListNode *temp = head;
    int arr[100000];
    int right = 0, left = 0;
    while (temp->next != NULL)
    {
        arr[right++] = temp->val;
        temp = temp->next;
    }
    arr[right] = temp->val;
    while (left < right)
    {
        if (arr[left++] != arr[right--])
            return false;
    }
    return true;
}