// Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.

 

// Example 1:

// Input: n = 13
// Output: 6
// Example 2:

// Input: n = 0
// Output: 0
int countDigitOne(int n) {
    int count = 0;
    long long factor = 1;
    
    while (n / factor > 0) {
        int currentDigit = (n / factor) % 10;
        int before = n / (factor * 10);
        int after = n - n / factor * factor;
        
        if (currentDigit > 1) {
            count += (before + 1) * factor;
        } else if (currentDigit == 1) {
            count += before * factor + after + 1;
        } else {
            count += before * factor;
        }
        
        factor *= 10;
    }
    
    return count;
}

