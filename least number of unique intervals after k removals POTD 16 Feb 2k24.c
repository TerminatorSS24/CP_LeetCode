/*Given an array of integers arr and an integer k. Find the least number of unique integers after removing exactly k elements.



Example 1:

Input: arr = [5,5,4], k = 1
Output: 1
Explanation: Remove the single 4, only 5 is left.
Example 2:
Input: arr = [4,3,1,1,3,3,2], k = 3
Output: 2
Explanation: Remove 4, 2 and either one of the two 1s or three 3s. 1 and 3 will be left.
**********LEETCODE POTD(16/02/2024)**********
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int compareNumbers(const void *a, const void *b)
{
    return *((int *)a) - *((int *)b);
}

int findLeastNumOfUniqueInts(int *arr, int arrSize, int k)
{
    const int n = arrSize;

    qsort(arr, n, sizeof(arr[0]), compareNumbers);

    int m = 0;
    int counts[n];

    int cur = arr[0];
    int cnt = 1;

    for (int i = 1; i < n; i++)
    {
        if (cur == arr[i])
            cnt += 1;
        else
        {
            counts[m++] = cnt;
            cur = arr[i];
            cnt = 1;
        }
    }

    counts[m++] = cnt;

    qsort(counts, m, sizeof(counts[0]), compareNumbers);

    int r = 0;

    for (int i = 0; i < m; i++)
    {
        if (k < counts[i])
            return m - r;

        r += 1;
        k -= counts[i];
    }

    return m - r;
}