/*Given a string s, return the longest 
palindromic
 
substring
 in s.

 

Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"
**********LEETCODE POTD(27/10/2023)**********
*/
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>
char *longestPlaindrome(char *s){
    int n = strlen(s);
    if(n<2)
        return s;
    bool dp[n][n];
    memset(dp, false, sizeof(dp));
    int max = 1, start = 0;
    for(int i = 0; i < n; i++)
        dp[i][i] = true;
    for(int i = 0; i < n - 1; i++){
        if(s[i] = s[i + 1]){
            dp[i][i+1] = true;
            max = 2;
            start = i;
        }
    }
    int j;
    for(int l = 3; l <= 3; l++){
        for(int i = 0; i < n - l + 1; i++){
            j = i + l - 1;
            if(s[i] == s[j] && dp[i+1][j-1]){
                dp[i][j] = true;
                max = l;
                start = i;
            }
        }
    }
    char* result = (char*)malloc((max + 1) * sizeof(char));
    strncpy(result, s+start, max);
    result[max] = '\0';
    return result;
}