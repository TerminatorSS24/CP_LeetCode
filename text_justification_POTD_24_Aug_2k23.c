// Given an array of strings words and a width maxWidth, format the text such that each line has exactly maxWidth characters and is fully (left and right) justified.

// You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly maxWidth characters.

// Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line does not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

// For the last line of text, it should be left-justified, and no extra space is inserted between words.

// Note:

// A word is defined as a character sequence consisting of non-space characters only.
// Each word's length is guaranteed to be greater than 0 and not exceed maxWidth.
// The input array words contains at least one word.
 

// Example 1:

// Input: words = ["This", "is", "an", "example", "of", "text", "justification."], maxWidth = 16
// Output:
// [
//    "This    is    an",
//    "example  of text",
//    "justification.  "
// ]
// Example 2:

// Input: words = ["What","must","be","acknowledgment","shall","be"], maxWidth = 16
// Output:
// [
//   "What   must   be",
//   "acknowledgment  ",
//   "shall be        "
// ]
// Explanation: Note that the last line is "shall be    " instead of "shall     be", because the last line must be left-justified instead of fully-justified.
// Note that the second line is also left-justified because it contains only one word.
// Example 3:

// Input: words = ["Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"], maxWidth = 20
// Output:
// [
//   "Science  is  what we",
//   "understand      well",
//   "enough to explain to",
//   "a  computer.  Art is",
//   "everything  else  we",
//   "do                  "
// ]
// **********LEETCODE POTD(24/08/2023)**********
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **fullJustify(char **words, int wordsSize, int maxWidth, int *returnSize) {
    char **result = NULL;
    *returnSize = 0;

    int start = 0; 
    int end = 0;  
    while (start < wordsSize) {
        int lineLength = strlen(words[start]);
        end = start + 1;

        while (end < wordsSize && lineLength + 1 + strlen(words[end]) <= maxWidth) {
            lineLength += 1 + strlen(words[end]);
            end++;
        }

        int numWords = end - start;
        int numSpaces = maxWidth - lineLength + numWords - 1;

        char *line = (char *)malloc(maxWidth + 1);
        int pos = 0;

        if (end == wordsSize || numWords == 1) {
            for (int i = start; i < end; i++) {
                if (i > start) {
                    line[pos++] = ' ';
                    numSpaces--;
                }
                strcpy(line + pos, words[i]);
                pos += strlen(words[i]);
            }

            while (numSpaces > 0) {
                line[pos++] = ' ';
                numSpaces--;
            }
        } else {
            int spacesBetweenWords = numSpaces / (numWords - 1);
            int extraSpaces = numSpaces % (numWords - 1);

            for (int i = start; i < end; i++) {
                if (i > start) {
                    int spaces = spacesBetweenWords + (extraSpaces-- > 0 ? 1 : 0);
                    for (int j = 0; j < spaces; j++) {
                        line[pos++] = ' ';
                    }
                }
                strcpy(line + pos, words[i]);
                pos += strlen(words[i]);
            }
        }

        line[pos] = '\0';
        result = (char **)realloc(result, (*returnSize + 1) * sizeof(char *));
        result[*returnSize] = line;
        (*returnSize)++;

        start = end;
    }

    return result;
}

