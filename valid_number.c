// A valid number can be split up into these components (in order):

// A decimal number or an integer.
// (Optional) An 'e' or 'E', followed by an integer.
// A decimal number can be split up into these components (in order):

// (Optional) A sign character (either '+' or '-').
// One of the following formats:
// One or more digits, followed by a dot '.'.
// One or more digits, followed by a dot '.', followed by one or more digits.
// A dot '.', followed by one or more digits.
// An integer can be split up into these components (in order):

// (Optional) A sign character (either '+' or '-').
// One or more digits.
// For example, all the following are valid numbers: ["2", "0089", "-0.1", "+3.14", "4.", "-.9", "2e10", "-90E3", "3e+7", "+6e-1", "53.5e93", "-123.456e789"], while the following are not valid numbers: ["abc", "1a", "1e", "e3", "99e2.5", "--6", "-+3", "95a54e53"].

// Given a string s, return true if s is a valid number.

 

// Example 1:

// Input: s = "0"
// Output: true
// Example 2:

// Input: s = "e"
// Output: false
// Example 3:

// Input: s = "."
// Output: false
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

bool isNumber(char *s) {
    s = strtok(s, " \t\n");
    if (s == NULL || strlen(s) == 0) {
        return false;
    }
    
    bool dot_seen = false;
    bool e_seen = false;
    bool num_seen = false;
    bool num_after_e = false;
    int length = strlen(s);

    for (int i = 0; i < length; i++) {
        char current_char = s[i];

        if (current_char == '+' || current_char == '-') {
            if (i > 0 && s[i - 1] != 'e' && s[i - 1] != 'E') {
                return false;
            }
            if (i == length - 1) {
                return false;
            }
        } else if (isdigit(current_char)) {
            num_seen = true;
            num_after_e = true;
        } else if (current_char == '.') {
            if (dot_seen || e_seen) {
                return false;
            }
            dot_seen = true;
            if (i == length - 1) {
                return num_seen;
            }
        } else if (current_char == 'e' || current_char == 'E') {
            if (e_seen || !num_seen) {
                return false;
            }
            e_seen = true;
            num_after_e = false;
            if (i == length - 1) {
                return false;
            }
        } else {
            return false;
        }
    }
    
    return num_seen && num_after_e;
}

