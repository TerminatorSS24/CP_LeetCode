#include <iostream>
using namespace std;
class Solution
{
public:
    int integerBreak(int n)
    {
        if (n <= 3)
            return n - 1;
        int m = 3, sum = 1;
        n -= 3;
        if (n == 1)
            m++;
        sum *= m;
        while (n - 3 > 1)
        {
            n -= 3;
            sum *= 3;
        }
        if (n > 1)
            sum *= n;
        return sum;
    }
};