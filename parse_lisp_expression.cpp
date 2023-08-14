/*You are given a string expression representing a Lisp-like expression to return the integer value of.

The syntax for these expressions is given as follows.

An expression is either an integer, let expression, add expression, mult expression, or an assigned variable. Expressions always evaluate to a single integer.
(An integer could be positive or negative.)
A let expression takes the form "(let v1 e1 v2 e2 ... vn en expr)", where let is always the string "let", then there are one or more pairs of alternating variables and expressions, meaning that the first variable v1 is assigned the value of the expression e1, the second variable v2 is assigned the value of the expression e2, and so on sequentially; and then the value of this let expression is the value of the expression expr.
An add expression takes the form "(add e1 e2)" where add is always the string "add", there are always two expressions e1, e2 and the result is the addition of the evaluation of e1 and the evaluation of e2.
A mult expression takes the form "(mult e1 e2)" where mult is always the string "mult", there are always two expressions e1, e2 and the result is the multiplication of the evaluation of e1 and the evaluation of e2.
For this question, we will use a smaller subset of variable names. A variable starts with a lowercase letter, then zero or more lowercase letters or digits. Additionally, for your convenience, the names "add", "let", and "mult" are protected and will never be used as variable names.
Finally, there is the concept of scope. When an expression of a variable name is evaluated, within the context of that evaluation, the innermost scope (in terms of parentheses) is checked first for the value of that variable, and then outer scopes are checked sequentially. It is guaranteed that every expression is legal. Please see the examples for more details on the scope.
 

Example 1:

Input: expression = "(let x 2 (mult x (let x 3 y 4 (add x y))))"
Output: 14
Explanation: In the expression (add x y), when checking for the value of the variable x,
we check from the innermost scope to the outermost in the context of the variable we are trying to evaluate.
Since x = 3 is found first, the value of x is 3.
Example 2:

Input: expression = "(let x 3 x 2 x)"
Output: 2
Explanation: Assignment in let statements is processed sequentially.
Example 3:

Input: expression = "(let x 1 y 2 x (add x y) (add x y))"
Output: 5
Explanation: The first (add x y) evaluates as 3, and is assigned to x.
The second (add x y) evaluates as 3+2 = 5.*/
#include <iostream>
#include <string>
#include <string_view>
#include <unordered_map>
#include <optional>
#include <cassert>

using namespace std;

class Solution {
public:
    struct Context {
        Context* Parent = nullptr;
        unordered_map<string, int> Vars;
    };

    void inc(string_view& buffer, int n = 1) {
        assert(buffer.size() >= n);
        buffer = {buffer.data() + n, buffer.size() - n};
    }

    void skipSpace(string_view& buffer) {
        if (isspace(buffer[0]))
            inc(buffer);
    }

    int isNum(char c) {
        return isdigit(c) || c == '-';
    }

    int parseInt(string_view& buffer) {
        int result = atoi(buffer.data());

        while (isNum(buffer[0]))
            inc(buffer);

        return result;
    }

    bool parseWord(string_view& buffer, const string& word) {
        if ((buffer.size() >= word.size()) && strncmp(buffer.data(), word.c_str(), word.size()) == 0) {
            inc(buffer, word.size());
            return true;
        }
        return false;
    }

    optional<string_view> parseVar(string_view& buffer) {
        optional<string_view> result;
        skipSpace(buffer);

        if (isalpha(buffer[0])) {
            string_view start = buffer;
            while (isalnum(buffer[0]))
                inc(buffer);
            result = string_view{start.data(), (size_t)(buffer.data() - start.data())};
        }
        return result;
    }

    int parseExpression(string_view& buffer, Context* context) {
        static const string kLet{"let"};
        static const string kAdd{"add"};
        static const string kMult{"mult"};

        skipSpace(buffer);
        if (buffer[0] == '(') {
            inc(buffer);
            int result = parseExpression(buffer, context);
            assert(buffer[0] == ')');
            inc(buffer);
            return result;
        } else if (isNum(buffer[0])) {
            return parseInt(buffer);
        } else if (parseWord(buffer, kLet)) {
            Context currContext;
            currContext.Parent = context;

            while (true) {
                string_view backtrack = buffer;
                auto varName = parseVar(buffer);

                if (!varName || buffer[0] == ')') {
                    buffer = backtrack;
                    break;
                }

                int value = parseExpression(buffer, &currContext);
                currContext.Vars[string(varName.value())] = value;
            }
            return parseExpression(buffer, &currContext);
        } else if (parseWord(buffer, kAdd)) {
            int a = parseExpression(buffer, context);
            int b = parseExpression(buffer, context);
            return a + b;
        } else if (parseWord(buffer, kMult)) {
            int a = parseExpression(buffer, context);
            int b = parseExpression(buffer, context);
            return a * b;
        } else if (auto varName = parseVar(buffer)) {
            string varNameStr = string(varName.value());
            Context* currContext = context;
            while (currContext) {
                auto it = currContext->Vars.find(varNameStr);
                if (it != currContext->Vars.end())
                    return it->second;
                currContext = currContext->Parent;
            }
            assert(!"Failed to find variable");
        }

        assert(!"Failed to parse expression");
        return 0;
    }

    int evaluate(string expression) {
        string_view buffer = expression;
        return parseExpression(buffer, nullptr);
    }
};

