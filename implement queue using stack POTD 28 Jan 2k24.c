/*
Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).

Implement the MyQueue class:

void push(int x) Pushes element x to the back of the queue.
int pop() Removes the element from the front of the queue and returns it.
int peek() Returns the element at the front of the queue.
boolean empty() Returns true if the queue is empty, false otherwise.
Notes:

You must use only standard operations of a stack, which means only push to top, peek/pop from top, size, and is empty operations are valid.
Depending on your language, the stack may not be supported natively. You may simulate a stack using a list or deque (double-ended queue) as long as you use only a stack's standard operations.


Example 1:

Input
["MyQueue", "push", "push", "peek", "pop", "empty"]
[[], [1], [2], [], [], []]
Output
[null, null, null, 1, 1, false]

Explanation
MyQueue myQueue = new MyQueue();
myQueue.push(1); // queue is: [1]
myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
myQueue.peek(); // return 1
myQueue.pop(); // return 1, queue is [2]
myQueue.empty(); // return false
**********LEETCODE POTD(29/01/2024)**********
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
    int *arr;
    int front;

} MyQueue;

MyQueue *myQueueCreate()
{
    MyQueue *obj = (MyQueue *)malloc(sizeof(MyQueue));
    obj->arr = malloc(sizeof(int) * 100);
    obj->front = -1;
    return obj;
}

void myQueuePush(MyQueue *obj, int x)
{
    if (obj == NULL)
        return;
    obj->arr[++obj->front] = x;
}

int myQueuePop(MyQueue *obj)
{
    if (obj == NULL)
        return NULL;
    int ele = obj->arr[0];
    for (int i = 0; i < obj->front; i++)
        obj->arr[i] = obj->arr[i + 1];
    obj->front -= 1;
    return ele;
}

int myQueuePeek(MyQueue *obj)
{
    if (obj == NULL)
        return NULL;
    return obj->arr[0];
}

bool myQueueEmpty(MyQueue *obj)
{
    if (obj == NULL)
        return false;
    return obj->front == -1;
}

void myQueueFree(MyQueue *obj)
{
    free(obj->arr);
    free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);

 * int param_2 = myQueuePop(obj);

 * int param_3 = myQueuePeek(obj);

 * bool param_4 = myQueueEmpty(obj);

 * myQueueFree(obj);
*/