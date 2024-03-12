/*Given the head of a linked list, we repeatedly delete consecutive sequences of nodes that sum to 0 until there are no such sequences.

After doing so, return the head of the final linked list.  You may return any such answer.



(Note that in the examples below, all sequences are serializations of ListNode objects.)

Example 1:

Input: head = [1,2,-3,3,1]
Output: [3,1]
Note: The answer [1,2,1] would also be accepted.
Example 2:

Input: head = [1,2,3,-3,4]
Output: [1,2,4]
Example 3:

Input: head = [1,2,3,-3,-2]
Output: [1]
**********LEETCODE POTD(12/03/2024)**********
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *removeZeroSumSublists(struct ListNode *head)
{

    int buf[1000], len1 = 0, ans[1000], len2 = 0;
    struct ListNode *node;

    for (; head; head = head->next, len1++)
    {
        buf[len1] = head->val;
    }

    head = NULL;

    for (int i = 0, j, sum; i < len1; i++)
    {

        sum = 0;

        for (j = i; j < len1; j++)
        {
            sum += buf[j];

            if (sum == 0)
            {
                break;
            }
        }

        if (sum != 0)
        {
            ans[len2] = buf[i];
            len2++;
        }
        else
        {
            i = j;
        }
    }

    for (int i = len2 - 1; i >= 0; i--)
    {
        node = (struct ListNode *)malloc(sizeof(struct ListNode));
        node->val = ans[i];
        node->next = head;
        head = node;
    }

    return head;
}