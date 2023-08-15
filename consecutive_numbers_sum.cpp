/*Given an integer n, return the number of ways you can write n as the sum of consecutive positive integers.

 

Example 1:

Input: n = 5
Output: 2
Explanation: 5 = 2 + 3
Example 2:

Input: n = 9
Output: 3
Explanation: 9 = 4 + 5 = 2 + 3 + 4
Example 3:

Input: n = 15
Output: 4
Explanation: 15 = 8 + 7 = 4 + 5 + 6 = 1 + 2 + 3 + 4 + 5*/
#include <iostream>

class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int ans=0;
        long long num=2ll*n;
        for(int i=1;1ll*i*i<=2ll*n;i++){
           if((num%i)==0){
               int a=i;
               int b=num/i;
               if((a%2)!=(b%2)){
                   ans++;
               }
           }
        }
        return ans;
    }
};