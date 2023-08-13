/*Nearly everyone has used the Multiplication Table. The multiplication table of size m x n is an integer matrix mat where mat[i][j] == i * j (1-indexed).

Given three integers m, n, and k, return the kth smallest element in the m x n multiplication table.

 

Example 1:

image: https://assets.leetcode.com/uploads/2021/05/02/multtable1-grid.jpg

Input: m = 3, n = 3, k = 5
Output: 3
Explanation: The 5th smallest number is 3.
Example 2:

image: https://assets.leetcode.com/uploads/2021/05/02/multtable2-grid.jpg

Input: m = 2, n = 3, k = 6
Output: 6
Explanation: The 6th smallest number is 6.*/
int findKthNumber(int m, int n, int k) {
    int low = 1, high = m * n;
    while (low < high) {
        int mid = low + (high - low) / 2;
        int count = 0;
        for (int i = 1; i <= m; i++) {
            count += (mid > n * i) ? n : (mid / i);
        }
        if (count < k)
            low = mid + 1;
        else
            high = mid;
    }
    return low;
}
