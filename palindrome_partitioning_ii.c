// Given a string s, partition s such that every 
// substring
//  of the partition is a 
// palindrome
// .

// Return the minimum cuts needed for a palindrome partitioning of s.

 

// Example 1:

// Input: s = "aab"
// Output: 1
// Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.
// Example 2:

// Input: s = "a"
// Output: 0
// Example 3:

// Input: s = "ab"
// Output: 1
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

int min(int a, int b) {
    return a < b ? a : b;
}

bool isPalindrome(char* s, int start, int end) {
    while (start < end) {
        if (s[start] != s[end])
            return false;
        start++;
        end--;
    }
    return true;
}

int minCut(char * s){
    int n = strlen(s);
    int* dp = (int*)malloc(sizeof(int) * (n + 1));
    for (int i = 0; i <= n; i++) {
        dp[i] = i - 1;
    }
    
    for (int center = 0; center < n; center++) {
        for (int radius = 0; center - radius >= 0 && center + radius < n && s[center - radius] == s[center + radius]; radius++) {
            dp[center + radius + 1] = min(dp[center + radius + 1], 1 + dp[center - radius]);
        }
        
        for (int radius = 0; center - radius >= 0 && center + radius + 1 < n && s[center - radius] == s[center + radius + 1]; radius++) {
            dp[center + radius + 2] = min(dp[center + radius + 2], 1 + dp[center - radius]);
        }
    }
    
    int result = dp[n];
    free(dp);
    return result;
}
