/*You are given an integer array cards of length 4. You have four cards, each containing a number in the range [1, 9]. You should arrange the numbers on these cards in a mathematical expression using the operators ['+', '-', '*', '/'] and the parentheses '(' and ')' to get the value 24.

You are restricted with the following rules:

The division operator '/' represents real division, not integer division.
For example, 4 / (1 - 2 / 3) = 4 / (1 / 3) = 12.
Every operation done is between two numbers. In particular, we cannot use '-' as a unary operator.
For example, if cards = [1, 1, 1, 1], the expression "-1 - 1 - 1 - 1" is not allowed.
You cannot concatenate numbers together
For example, if cards = [1, 2, 1, 2], the expression "12 + 12" is not valid.
Return true if you can get such expression that evaluates to 24, and false otherwise.

 

Example 1:

Input: cards = [4,1,8,7]
Output: true
Explanation: (8-4) * (7-1) = 24
Example 2:

Input: cards = [1,2,1,2]
Output: false*/
#include <stdbool.h>

bool judgePoint24Helper(double* nums, int size) {
    if (size == 1) {
        return fabs(nums[0] - 24) < 1e-6;
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i != j) {
                double newNums[size - 1];
                int idx = 0;
                for (int k = 0; k < size; k++) {
                    if (k != i && k != j) {
                        newNums[idx++] = nums[k];
                    }
                }

                newNums[idx] = nums[i] + nums[j];
                if (judgePoint24Helper(newNums, size - 1)) {
                    return true;
                }

                newNums[idx] = nums[i] - nums[j];
                if (judgePoint24Helper(newNums, size - 1)) {
                    return true;
                }

                newNums[idx] = nums[i] * nums[j];
                if (judgePoint24Helper(newNums, size - 1)) {
                    return true;
                }

                if (nums[j] != 0) {
                    newNums[idx] = nums[i] / nums[j];
                    if (judgePoint24Helper(newNums, size - 1)) {
                        return true;
                    }
                }
            }
        }
    }

    return false;
}

bool judgePoint24(int* cards, int cardsSize) {
    double nums[4];
    for (int i = 0; i < cardsSize; i++) {
        nums[i] = (double)cards[i];
    }

    return judgePoint24Helper(nums, cardsSize);
}
