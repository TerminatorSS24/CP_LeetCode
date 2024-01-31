/*Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.



Example 1:

Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]
Example 2:

Input: temperatures = [30,40,50,60]
Output: [1,1,1,0]
Example 3:

Input: temperatures = [30,60,90]
Output: [1,1,0]
**********LEETCODE POTD(31/01/2024)**********
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef struct stack
{
    int size;
    int top;
    int *arr;
} Stack;

Stack *createStack(int size)
{
    Stack *st = (Stack *)malloc(sizeof(Stack));
    st->size = size;
    st->top = -1;
    st->arr = (int *)malloc(size * sizeof(int));

    return st;
}

void push(Stack *st, int data)
{
    if (st->top == st->size - 1)
        printf("Stack overflow");
    else
    {
        st->top++;
        st->arr[st->top] = data;
    }
}

int pop(Stack *st)
{
    if (st->top < 0)
    {
        printf("Stack underflow");
        return -1;
    }
    int data = st->arr[st->top];
    st->top--;

    return data;
}

int *dailyTemperatures(int *temperatures, int temperaturesSize, int *returnSize)
{
    int i;
    int *ans = (int *)malloc(temperaturesSize * sizeof(int));
    Stack *st = createStack(temperaturesSize);

    for (i = temperaturesSize - 1; i >= 0; i--)
    {
        while (st->top >= 0)
        {
            if (temperatures[st->arr[st->top]] > temperatures[i])
            {
                ans[i] = st->arr[st->top] - i;
                break;
            }
            else
                pop(st);
        }

        if (st->top < 0)
            ans[i] = 0;

        push(st, i);
    }

    free(st->arr);
    free(st);
    *returnSize = temperaturesSize;
    return ans;
}