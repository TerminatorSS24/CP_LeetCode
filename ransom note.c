/*Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.

Each letter in magazine can only be used once in ransomNote.

 

Example 1:

Input: ransomNote = "a", magazine = "b"
Output: false
Example 2:

Input: ransomNote = "aa", magazine = "ab"
Output: false
Example 3:

Input: ransomNote = "aa", magazine = "aab"
Output: true*/
#include<stdio.h>
#include<string.h>
#include<stdbool.h>
int alphabet_magazine[26];

bool canConstruct(char * ransomNote, char * magazine){
    memset(alphabet_magazine, 0, 26 * sizeof(int));

    int i, mag_len = strlen(magazine), ransom_len = strlen(ransomNote);

    for (i = 0; i < mag_len; i++) {
        alphabet_magazine[magazine[i] - 'a']++;
    }

    for (i = 0; i < ransom_len; i++) {
        if (alphabet_magazine[ransomNote[i] - 'a'] == 0)
            return false;
        alphabet_magazine[ransomNote[i] - 'a']--;
    }

    return true;
}