// Given a string num that contains only digits and an integer target, return all possibilities to insert the binary operators '+', '-', and/or '*' between the digits of num so that the resultant expression evaluates to the target value.

// Note that operands in the returned expressions should not contain leading zeros.

 

// Example 1:

// Input: num = "123", target = 6
// Output: ["1*2*3","1+2+3"]
// Explanation: Both "1*2*3" and "1+2+3" evaluate to 6.
// Example 2:

// Input: num = "232", target = 8
// Output: ["2*3+2","2+3*2"]
// Explanation: Both "2*3+2" and "2+3*2" evaluate to 8.
// Example 3:

// Input: num = "3456237490", target = 9191
// Output: []
// Explanation: There are no expressions that can be created from "3456237490" to evaluate to 9191.
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

class Solution {
public:
    unordered_map<string, bool> memo;
    vector<string> result;
    
    void backtrack(string num, int target, int index, long currentSum, long prevNum, string currentExpr) {
        if (index == num.length()) {
            if (currentSum == target) {
                result.push_back(currentExpr);
            }
            return;
        }
        
        for (int i = index; i < num.length(); i++) {
            string currentStr = num.substr(index, i - index + 1);
            
            if (currentStr.length() > 1 && currentStr[0] == '0') {
                // Avoid leading zeros
                break;
            }
            
            long currentNum = stol(currentStr);
            
            if (index == 0) {
                backtrack(num, target, i + 1, currentNum, currentNum, currentExpr + currentStr);
            } else {
                // '+'
                backtrack(num, target, i + 1, currentSum + currentNum, currentNum, currentExpr + "+" + currentStr);
                
                // '-'
                backtrack(num, target, i + 1, currentSum - currentNum, -currentNum, currentExpr + "-" + currentStr);
                
                // '*'
                backtrack(num, target, i + 1, currentSum - prevNum + prevNum * currentNum, prevNum * currentNum, currentExpr + "*" + currentStr);
            }
        }
    }
    
    vector<string> addOperators(string num, int target) {
        backtrack(num, target, 0, 0, 0, "");
        return result;
    }
};