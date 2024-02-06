/*
Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.



Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
Example 2:

Input: strs = [""]
Output: [[""]]
Example 3:

Input: strs = ["a"]
Output: [["a"]]
**********LEETCODE POTD(06/02/2024)**********
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b)
{
    return (*(const char *)a - *(const char *)b);
}

char ***groupAnagrams(char **strs, int strsSize, int *returnSize, int **returnColumnSizes)
{

    typedef struct
    {
        char *key;
        char **values;
        int count;
    } HashEntry;

    HashEntry *hashTable = (HashEntry *)malloc(strsSize * sizeof(HashEntry));
    int hashTableSize = 0;

    for (int i = 0; i < strsSize; i++)
    {
        char *word = strs[i];
        char *sortedWord = strdup(word);
        qsort(sortedWord, strlen(sortedWord), sizeof(char), cmp);

        int found = 0;
        for (int j = 0; j < hashTableSize; j++)
        {
            if (strcmp(hashTable[j].key, sortedWord) == 0)
            {
                hashTable[j].count++;
                hashTable[j].values = (char **)realloc(hashTable[j].values, hashTable[j].count * sizeof(char *));
                hashTable[j].values[hashTable[j].count - 1] = word;
                found = 1;
                break;
            }
        }
        if (!found)
        {
            hashTable[hashTableSize].key = sortedWord;
            hashTable[hashTableSize].count = 1;
            hashTable[hashTableSize].values = (char **)malloc(sizeof(char *));
            hashTable[hashTableSize].values[0] = word;
            hashTableSize++;
        }
    }

    char ***result = (char ***)malloc(hashTableSize * sizeof(char **));
    int *columnSizes = (int *)malloc(hashTableSize * sizeof(int));

    for (int i = 0; i < hashTableSize; i++)
    {
        result[i] = hashTable[i].values;
        columnSizes[i] = hashTable[i].count;
    }

    free(hashTable);

    *returnSize = hashTableSize;
    *returnColumnSizes = columnSizes;

    return result;
}

void printGroupedAnagrams(char ***anagrams, int *columnSizes, int size)
{
    printf("[\n");
    for (int i = 0; i < size; i++)
    {
        printf("  [");
        for (int j = 0; j < columnSizes[i]; j++)
        {
            printf("\"%s\"", anagrams[i][j]);
            if (j < columnSizes[i] - 1)
                printf(", ");
        }
        printf("]\n");
    }
    printf("]\n");
}
