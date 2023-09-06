/*Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.

 

Example 1:

Input: n = 2
Output: [0,1,1]
Explanation:
0 --> 0
1 --> 1
2 --> 10
Example 2:

Input: n = 5
Output: [0,1,1,2,1,2]
Explanation:
0 --> 0
1 --> 1
2 --> 10
3 --> 11
4 --> 100
5 --> 101
**********LEETOCDE POTD(01/09/2023)**********
*/
int* countBits(int n, int* returnSize){
    *returnSize = n + 1;
    int* ret = (int*) malloc(*returnSize * sizeof(int));
    ret[0] = 0;
    for (int i = 1; i < *returnSize; i++) {
        ret[i] = (i & 1) + ret[i >> 1];
    }
    return ret;
}