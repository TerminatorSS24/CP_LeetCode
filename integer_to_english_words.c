// Convert a non-negative integer num to its English words representation.

 

// Example 1:

// Input: num = 123
// Output: "One Hundred Twenty Three"
// Example 2:

// Input: num = 12345
// Output: "Twelve Thousand Three Hundred Forty Five"
// Example 3:

// Input: num = 1234567
// Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char* belowTwenty[] = {"","One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
const char* tens[] = {"","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
const char* thousands[] = {"","Thousand","Million","Billion"};

char* helper(int num) {
    char* result = (char*)calloc(100, sizeof(char));
    if (num == 0)
        return "";
    else if (num < 20) {
        strcat(result, belowTwenty[num]);
    }
    else if (num < 100) {
        strcat(result, tens[num / 10]);
        if(num % 10) strcat(result, " ");
        strcat(result, helper(num % 10));
    }
    else {
        strcat(result, belowTwenty[num / 100]);
        strcat(result, " Hundred");
        if(num % 100) strcat(result, " ");
        strcat(result, helper(num % 100));
    }
    return result;
}

char* numberToWords(int num) {
    if (num == 0)
        return "Zero";

    char* result = (char*)calloc(1000, sizeof(char));
    int i = 0;
    while (num > 0) {
        if (num % 1000 != 0) {
            char* segment = helper(num % 1000);
            if(i > 0) strcat(segment, " ");
            strcat(segment, thousands[i]);
            if(strlen(result) > 0) strcat(segment, " ");
            strcat(segment, result);
            strcpy(result, segment);
            free(segment);
        }
        num /= 1000;
        i++;
    }

    return result;
}