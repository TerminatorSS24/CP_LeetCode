// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

// A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

//image: https://assets.leetcode.com/uploads/2022/03/15/1200px-telephone-keypad2svg.png
 

// Example 1:

// Input: digits = "23"
// Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
// Example 2:

// Input: digits = ""
// Output: []
// Example 3:

// Input: digits = "2"
// Output: ["a","b","c"]
//**********LEETCODE POTD(03/08/2023)**********
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *phoneMap[] = {
    "",     
    "",     
    "abc",  
    "def",  
    "ghi",  
    "jkl",  
    "mno",  
    "pqrs", 
    "tuv",  
    "wxyz"  
};

void generateCombinations(char *digits, int index, char *current, char **result, int *returnSize) {
    if (digits[index] == '\0') {
        result[*returnSize] = strdup(current);
        (*returnSize)++;
        return;
    }

    int digit = digits[index] - '0';
    const char *letters = phoneMap[digit];
    int len = strlen(letters);

    for (int i = 0; i < len; i++) {
        current[index] = letters[i];
        generateCombinations(digits, index + 1, current, result, returnSize);
    }
}

char **letterCombinations(char *digits, int *returnSize) {
    int len = strlen(digits);
    if (len == 0) {
        *returnSize = 0;
        return NULL;
    }

    int totalCombinations = 1;
    for (int i = 0; i < len; i++) {
        totalCombinations *= strlen(phoneMap[digits[i] - '0']);
    }

    char **result = (char **)malloc(sizeof(char *) * totalCombinations);
    *returnSize = 0;

    char *current = (char *)malloc(sizeof(char) * (len + 1));
    current[len] = '\0';

    generateCombinations(digits, 0, current, result, returnSize);

    free(current);
    return result;
}
