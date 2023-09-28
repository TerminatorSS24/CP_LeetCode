/*You are given an encoded string s. To decode the string to a tape, the encoded string is read one character at a time and the following steps are taken:

If the character read is a letter, that letter is written onto the tape.
If the character read is a digit d, the entire current tape is repeatedly written d - 1 more times in total.
Given an integer k, return the kth letter (1-indexed) in the decoded string.

 

Example 1:

Input: s = "leet2code3", k = 10
Output: "o"
Explanation: The decoded string is "leetleetcodeleetleetcodeleetleetcode".
The 10th letter in the string is "o".
Example 2:

Input: s = "ha22", k = 5
Output: "h"
Explanation: The decoded string is "hahahaha".
The 5th letter is "h".
Example 3:

Input: s = "a2345678999999999999999", k = 1
Output: "a"
Explanation: The decoded string is "a" repeated 8301530446056247680 times.
The 1st letter is "a".
**********LEETCODE POTD(27/09/2023)**********
*/
char* decodeAtIndex(char* s, int k) {
    long long length = 0;
    int i = 0;

    while (length < k) {
        if (isdigit(s[i])) {
            length *= s[i] - '0';
        } else {
            length++;
        }
        i++;
    }

    static char result[2];
    for (int j = i - 1; j >= 0; j--) {
        if (isdigit(s[j])) {
            length /= s[j] - '0';
            k %= length;
        } else {
            if (k == 0 || k == length) {
                result[0] = s[j];
                return result;
            }
            length--;
        }
    }

    return "";
}