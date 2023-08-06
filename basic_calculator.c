// Given a string s representing a valid expression, implement a basic calculator to evaluate it, and return the result of the evaluation.

// Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().

 

// Example 1:

// Input: s = "1 + 1"
// Output: 2
// Example 2:

// Input: s = " 2-1 + 2 "
// Output: 3
// Example 3:

// Input: s = "(1+(4+5+2)-3)+(6+8)"
// Output: 23
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int calculate(char *s) {
    int len = strlen(s);
    int result = 0;
    int num = 0;
    int sign = 1;
    int stack[10000];
    int stackTop = 0;

    for (int i = 0; i < len; i++) {
        if (isdigit(s[i])) {
            num = num * 10 + (s[i] - '0');
        } else if (s[i] == '+') {
            result += sign * num;
            sign = 1;
            num = 0;
        } else if (s[i] == '-') {
            result += sign * num;
            sign = -1;
            num = 0;
        } else if (s[i] == '(') {
            stack[stackTop++] = result;
            stack[stackTop++] = sign;
            result = 0;
            sign = 1;
        } else if (s[i] == ')') {
            result += sign * num;
            num = 0;
            result *= stack[--stackTop]; 
            result += stack[--stackTop]; 
        }
    }

    result += sign * num;

    return result;
}

