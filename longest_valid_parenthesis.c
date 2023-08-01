// Given a string containing just the characters '(' and ')', return the length of the longest valid (well-formed) parentheses 
// substring
// .

 

// Example 1:

// Input: s = "(()"
// Output: 2
// Explanation: The longest valid parentheses substring is "()".
// Example 2:

// Input: s = ")()())"
// Output: 4
// Explanation: The longest valid parentheses substring is "()()".
// Example 3:

// Input: s = ""
// Output: 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int* data;
    int top;
    int capacity;
} Stack;

Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->data = (int*)malloc(capacity * sizeof(int));
    stack->top = -1;
    stack->capacity = capacity;
    return stack;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

void push(Stack* stack, int value) {
    if (stack->top == stack->capacity - 1) {
        int newCapacity = 2 * stack->capacity;
        stack->data = (int*)realloc(stack->data, newCapacity * sizeof(int));
        stack->capacity = newCapacity;
    }

    stack->top++;
    stack->data[stack->top] = value;
}

int pop(Stack* stack) {
    if (isEmpty(stack)) {
        return -1; 
    }

    int value = stack->data[stack->top];
    stack->top--;
    return value;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int longestValidParentheses(char* s) {
    int max_len = 0;
    int start = 0;
    int s_len = strlen(s);

    Stack* st = createStack(s_len);

    for (int i = 0; i < s_len; i++) {
        if (s[i] == '(') {
            push(st, i);
        } else { 
            if (isEmpty(st)) {
                start = i + 1; 
            } else {
                pop(st);
                if (isEmpty(st)) {
                    max_len = max(max_len, i - start + 1);
                } else {
                    max_len = max(max_len, i - st->data[st->top]);
                }
            }
        }
    }

    free(st->data);
    free(st);

    return max_len;
}


