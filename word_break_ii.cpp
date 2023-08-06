// Given a string s and a dictionary of strings wordDict, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences in any order.

// Note that the same word in the dictionary may be reused multiple times in the segmentation.

 

// Example 1:

// Input: s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]
// Output: ["cats and dog","cat sand dog"]
// Example 2:

// Input: s = "pineapplepenapple", wordDict = ["apple","pen","applepen","pine","pineapple"]
// Output: ["pine apple pen apple","pineapple pen apple","pine applepen apple"]
// Explanation: Note that you are allowed to reuse a dictionary word.
// Example 3:

// Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
// Output: []
#include <stdio.h>
#include <string.h>

#define MAX_STRING_LEN 101
#define MAX_WORD_COUNT 200

struct Vector {
    char data[MAX_WORD_COUNT][MAX_STRING_LEN];
    int size;
};

void initVector(struct Vector* v) {
    v->size = 0;
}

void pushBack(struct Vector* v, char* item) {
    if (v->size == MAX_WORD_COUNT) {
        return; // Vector is full
    }

    strcpy(v->data[v->size], item);
    v->size++;
}

void fun(char* s, struct Vector* v, int i, struct Vector* ans, char* temp) {
    if (s[i] == '\0') {
        int n = strlen(temp);
        temp[n - 1] = '\0';
        pushBack(ans, temp);
        return;
    }

    struct Vector start = v[s[i] - 'a'];

    for (int ind = 0; ind < start.size; ind++) {
        int n = strlen(start.data[ind]);
        char part[MAX_STRING_LEN];
        strncpy(part, s + i, n);
        part[n] = '\0';

        if (strcmp(part, start.data[ind]) == 0) {
            char newTemp[MAX_STRING_LEN * 2];
            strcpy(newTemp, temp);
            strcat(newTemp, part);
            strcat(newTemp, " ");
            fun(s, v, i + n, ans, newTemp);
        }
    }
    return;
}

struct Vector wordBreak(char* s, char** wordDict, int wordDictSize, int* returnSize) {
    struct Vector ans;
    initVector(&ans);

    struct Vector array[26];
    for (int i = 0; i < wordDictSize; i++) {
        char firstChar = wordDict[i][0];
        pushBack(&array[firstChar - 'a'], wordDict[i]);
    }

    int ind = 0;
    char temp[MAX_STRING_LEN];
    temp[0] = '\0';
    fun(s, array, ind, &ans, temp);

    *returnSize = ans.size;
    return ans;
}

int main() {
    // Sample usage of the wordBreak function
    char* s = "pineapplepenapple";
    char* wordDict[] = {"apple", "pen", "applepen", "pine", "pineapple"};
    int wordDictSize = 5;
    int ret_size = 0;
    struct Vector ret = wordBreak(s, wordDict, wordDictSize, &ret_size);

    for (int i = 0; i < ret.size; i++) {
        printf("%s\n", ret.data[i]);
    }

    return 0;
}
