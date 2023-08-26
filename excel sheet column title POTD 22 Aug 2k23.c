/*Given an integer columnNumber, return its corresponding column title as it appears in an Excel sheet.

For example:

A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28 
...
 

Example 1:

Input: columnNumber = 1
Output: "A"
Example 2:

Input: columnNumber = 28
Output: "AB"
Example 3:

Input: columnNumber = 701
Output: "ZY"
**********LEETCODE POTD(22/08/2023)**********
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* convertToTitle(int columnNumber) {
    int length = 0;
    int num = columnNumber;
    while (num > 0) {
        length++;
        num = (num - 1) / 26;
    }
    
    char *title = (char *)malloc((length + 1) * sizeof(char));
    title[length] = '\0'; 
    
    for (int i = length - 1; i >= 0; i--) {
        title[i] = (columnNumber - 1) % 26 + 'A';
        columnNumber = (columnNumber - 1) / 26;
    }
    
    return title;
}