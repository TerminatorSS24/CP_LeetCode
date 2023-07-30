// There is a strange printer with the following two special properties:

// The printer can only print a sequence of the same character each time.
// At each turn, the printer can print new characters starting from and ending at any place and will cover the original existing characters.
// Given a string s, return the minimum number of turns the printer needed to print it.

 

// Example 1:

// Input: s = "aaabbb"
// Output: 2
// Explanation: Print "aaa" first and then print "bbb".
// Example 2:

// Input: s = "aba"
// Output: 2
// Explanation: Print "aaa" first and then print "b" from the second place of the string, which will cover the existing character 'a'.
//   **********LEETCODE POTD(30/07/2023)**********
int min(int a, int b) {
    return a < b ? a : b;
}

int strangePrinter(char* s) {
    if (!s || !*s) return 0;

    int n = strlen(s);
    int dp[n][n];

    for (int i = 0; i < n; i++) {
        dp[i][i] = 1; 
    }

    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            dp[i][j] = len; 
            
            if (s[i] == s[j]) {
                dp[i][j] = dp[i][j - 1];
            }

            for (int k = i; k < j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
            }
        }
    }

    return dp[0][n - 1];
}
