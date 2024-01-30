/*

You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.

Evaluate the expression. Return an integer that represents the value of the expression.

Note that:

The valid operators are '+', '-', '*', and '/'.
Each operand may be an integer or another expression.
The division between two integers always truncates toward zero.
There will not be any division by zero.
The input represents a valid arithmetic expression in a reverse polish notation.
The answer and all the intermediate calculations can be represented in a 32-bit integer.


Example 1:

Input: tokens = ["2","1","+","3","*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9
Example 2:

Input: tokens = ["4","13","5","/","+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6
Example 3:

Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
Output: 22
Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22
**********LEETCODE POTD(30/01/2024)**********
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_SIZE 10001

bool is_operator(char **token, int tokenSize)
{
    if (tokenSize > 1)
        return false;
    return (*token)[0] == '+' || (*token)[0] == '-' || (*token)[0] == '*' || (*token)[0] == '/';
}

int evalRPN(char **tokens, int tokensSize)
{
    int stack[MAX_SIZE];
    int idx = -1;

    for (int i = 0; i < tokensSize; ++i)
    {
        int len = strlen(tokens[i]);
        if (!is_operator(&tokens[i], len))
        {
            stack[++idx] = (int)strtol(tokens[i], NULL, 0L);
            continue;
        }

        int second = stack[idx--];
        int first = stack[idx--];

        if (tokens[i][0] == '+')
            stack[++idx] = first + second;
        else if (tokens[i][0] == '-')
            stack[++idx] = first - second;
        else if (tokens[i][0] == '*')
            stack[++idx] = first * second;
        else if (tokens[i][0] == '/')
            stack[++idx] = first / second;
    }

    if (idx != 0)
        return -1;

    return stack[idx];
}