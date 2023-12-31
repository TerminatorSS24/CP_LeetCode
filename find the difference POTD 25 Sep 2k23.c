/*You are given two strings s and t.

String t is generated by random shuffling string s and then add one more letter at a random position.

Return the letter that was added to t.

 

Example 1:

Input: s = "abcd", t = "abcde"
Output: "e"
Explanation: 'e' is the letter that was added.
Example 2:

Input: s = "", t = "y"
Output: "y"
**********LEETCODE POTD(25/09/2023)**********
*/
char findTheDifference(char * s, char * t){
    char LTR[26]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    char x;
    int STRIND=0;
    while (s[STRIND]!='\0') {
        LTR[s[STRIND]-97]+=1;
        STRIND+=1;
    }
    STRIND=0;
    while (t[STRIND]!='\0') {
        if (LTR[t[STRIND]-97]!='\0')
            LTR[t[STRIND]-97]+=-1;
        else
            return t[STRIND];
        STRIND+=1;
    }
    return '\0';
}