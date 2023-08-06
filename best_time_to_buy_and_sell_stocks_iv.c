// You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.

// Find the maximum profit you can achieve. You may complete at most k transactions: i.e. you may buy at most k times and sell at most k times.

// Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

// Example 1:

// Input: k = 2, prices = [2,4,1]
// Output: 2
// Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
// Example 2:

// Input: k = 2, prices = [3,2,6,5,0,3]
// Output: 7
// Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
int maxProfit(int k, int* prices, int pricesSize) {
    if (k == 0 || pricesSize == 0) {
        return 0;
    }
    
    if (k >= pricesSize / 2) {
        int maxProfit = 0;
        for (int i = 1; i < pricesSize; i++) {
            if (prices[i] > prices[i - 1]) {
                maxProfit += prices[i] - prices[i - 1];
            }
        }
        return maxProfit;
    }
    
    int dp[k + 1][pricesSize];
    for (int i = 0; i <= k; i++) {
        dp[i][0] = 0;
    }
    for (int j = 0; j < pricesSize; j++) {
        dp[0][j] = 0;
    }
    
    for (int i = 1; i <= k; i++) {
        int maxDiff = -prices[0];
        for (int j = 1; j < pricesSize; j++) {
            dp[i][j] = fmax(dp[i][j - 1], prices[j] + maxDiff);
            maxDiff = fmax(maxDiff, dp[i - 1][j] - prices[j]);
        }
    }
    
    return dp[k][pricesSize - 1];
}
