/*
An integer has sequential digits if and only if each digit in the number is one more than the previous digit.

Return a sorted list of all the integers in the range [low, high] inclusive that have sequential digits.



Example 1:

Input: low = 100, high = 300
Output: [123,234]
Example 2:

Input: low = 1000, high = 13000
Output: [1234,2345,3456,4567,5678,6789,12345]
**********LEETCODE POTD(02/02/2024)**********
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void update_next_num(int *num, int *base_num, int *digit_mask)
{
    *num += *digit_mask;
    if (*num % 10 == 0)
    {
        *digit_mask = *digit_mask * 10 + 1;
        *base_num = *base_num * 10 + *base_num % 10 + 1;
        *num = *base_num;
    }
}

void update_result(int **result, int *returnSize, int num)
{
    *result = (int *)realloc(*result, (*returnSize + 1) * sizeof(int));
    if (*result == NULL)
        return;
    (*result)[*returnSize] = num;
    (*returnSize)++;
}

int *sequentialDigits(int low, int high, int *returnSize)
{
    int *result = (int *)malloc(1 * sizeof(int));
    if (result == NULL)
        exit(-1);

    *returnSize = 0;

    int base_num = 1;
    int digit_mask = 1;

    {
        int len = 1;
        while (low / len > 0)
            len *= 10;

        while (base_num <= len / 10)
        {
            base_num = base_num * 10 + base_num % 10 + 1;
            digit_mask = digit_mask * 10 + 1;
        }
    }

    int num = base_num;
    while (num < low)
        update_next_num(&num, &base_num, &digit_mask);

    while (num <= high)
    {
        update_result(&result, returnSize, num);
        if (result == NULL)
            return NULL;
        update_next_num(&num, &base_num, &digit_mask);
    }

    return result;
}