/*Given an integer n, return the number of positive integers in the range [1, n] that have at least one repeated digit.



Example 1:

Input: n = 20
Output: 1
Explanation: The only positive number (<= 20) with at least 1 repeated digit is 11.
Example 2:

Input: n = 100
Output: 10
Explanation: The positive numbers (<= 100) with atleast 1 repeated digit are 11, 22, 33, 44, 55, 66, 77, 88, 99, and 100.
Example 3:

Input: n = 1000
Output: 262*/
#include <stdio.h>
#include <stdbool.h>
#ifdef DEBUG
#define PRINT printf
#define ASSERT assert
#else
#define PRINT
#define ASSERT
#endif

static inline int numberOfDigits(int n)
{
    int count = 0;

    while (n > 0)
    {
        n /= 10;
        count++;
    }

    return count;
}

int numDupDigitsAtMostN(int n)
{
    const int origN = n;
    const int origNumDigits = numberOfDigits(n);

    bool highUsed[10] = {false};
    int count = 0;
    int multiple = 1;

    for (int i = 1; i < origNumDigits; i++)
    {
        multiple *= 10;
    }
    const int origMultiple = multiple;

    if ((n / multiple) > 1)
    {
        int add = (n / multiple) - 1;
        for (int numUsed = 1; numUsed < origNumDigits; numUsed++)
        {
            add *= 10 - numUsed;
        }
        count += add;
    }

    PRINT("1: %d\n", count);
    for (int numDigits = origNumDigits; numDigits > 0; numDigits--)
    {
        const int highDigit = n / multiple;
        const int highN = highDigit * multiple;
        n -= highN;
        multiple /= 10;

        if (highUsed[highDigit] == true)
        {
            break;
        }
        else if (numDigits == 1)
        {
            count++;
        }
        else
        {
            const int nextHighDigit = n / multiple;
            int numOptions = 0;
            int numUsed = 0;

            highUsed[highDigit] = true;

            for (int i = 0; i < 10; i++)
            {
                if (highUsed[i] == false)
                {
                    if (i < nextHighDigit)
                    {
                        numOptions++;
                    }
                }
                else
                {
                    numUsed++;
                }
            }
            if (numOptions > 0)
            {
                int add = numOptions;

                numUsed++;
                for (; numUsed < origNumDigits; numUsed++)
                {
                    add *= 10 - numUsed;
                }
                count += add;
            }
        }

        PRINT("2: %d\n", count);
    }

    n = origN;
    multiple = origMultiple;

    for (int numDigits = origNumDigits; numDigits > 0; numDigits--)
    {
        const int highDigit = n / multiple;
        const int highN = highDigit * multiple;

        if (numDigits > 1)
        {
            int add = 9;
            for (int numUsed = 1; numUsed < (numDigits - 1); numUsed++)
            {
                add *= 10 - numUsed;
            }
            count += add;
        }

        PRINT("3: %d\n", count);
        n -= highN;
        multiple /= 10;
    }

    PRINT("%d vs %d\n", origN, count);
    ASSERT(origN >= count);
    return (origN - count);
}