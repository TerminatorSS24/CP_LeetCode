/*Under the grammar given below, strings can represent a set of lowercase words. Let R(expr) denote the set of words the expression represents.

The grammar can best be understood through simple examples:

Single letters represent a singleton set containing that word.
R("a") = {"a"}
R("w") = {"w"}
When we take a comma-delimited list of two or more expressions, we take the union of possibilities.
R("{a,b,c}") = {"a","b","c"}
R("{{a,b},{b,c}}") = {"a","b","c"} (notice the final set only contains each word at most once)
When we concatenate two expressions, we take the set of possible concatenations between two words where the first word comes from the first expression and the second word comes from the second expression.
R("{a,b}{c,d}") = {"ac","ad","bc","bd"}
R("a{b,c}{d,e}f{g,h}") = {"abdfg", "abdfh", "abefg", "abefh", "acdfg", "acdfh", "acefg", "acefh"}
Formally, the three rules for our grammar:

For every lowercase letter x, we have R(x) = {x}.
For expressions e1, e2, ... , ek with k >= 2, we have R({e1, e2, ...}) = R(e1) ∪ R(e2) ∪ ...
For expressions e1 and e2, we have R(e1 + e2) = {a + b for (a, b) in R(e1) × R(e2)}, where + denotes concatenation, and × denotes the cartesian product.
Given an expression representing a set of words under the given grammar, return the sorted list of words that the expression represents.



Example 1:

Input: expression = "{a,b}{c,{d,e}}"
Output: ["ac","ad","ae","bc","bd","be"]
Example 2:

Input: expression = "{{a,z},a{b,c},{ab,z}}"
Output: ["a","ab","ac","z"]
Explanation: Each distinct word is written only once in the final answer.*/
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>
using namespace std;
class Solution
{
public:
    unordered_set<char> operators;
    vector<string> multiplyVectors(vector<string> vec1, vector<string> vec2)
    {
        vector<string> res;
        for (int i = 0; i < vec1.size(); i++)
        {
            for (int j = 0; j < vec2.size(); j++)
                res.push_back(vec1[i] + vec2[j]);            
        }
        return res;
    }
    void updateRes(vector<string> &res, int startIdx, vector<string> res2)
    {
        vector<string> vec2 = {};
        for (int j = startIdx; j < res.size(); j++)        
            vec2.push_back(res[j]);
        vector<string> newRes = multiplyVectors(vec2, res2);
        int pos = 0;
        for (int j = startIdx; pos < newRes.size(); j++)
        {
            if (j < res.size()) 
                res[j] = newRes[pos];
            else
                res.push_back(newRes[pos]);
            res[j] = newRes[pos];
            pos += 1;
        }
    }
    vector<string> helper(int &idx, string &expression)
    {
        vector<string> res = {""};
        int startIdx = 0;
        for (int &i = idx; i < expression.length(); i++)
        {
            char curr = expression[i];
            if (curr == '{')
            {
                i += 1;
                vector<string> res2 = helper(i, expression);
                updateRes(res, startIdx, res2);
            }
            else if (curr == '}')
                return res;
            else if (curr == ',')
            {
                res.push_back("");
                startIdx = res.size() - 1;
            }
            else
            {
                string word(1, curr);
                int currPos = i + 1;
                while (currPos < expression.size() && operators.find(expression[currPos]) == operators.end())
                {
                    word += expression[currPos];
                    currPos += 1;
                }
                i = currPos - 1;
                updateRes(res, startIdx, {word});
            }
        }
        return res;
    }
    vector<string> braceExpansionII(string expression)
    {
        operators.insert('{');
        operators.insert('}');
        operators.insert(',');
        int idx = 0;
        vector<string> res = helper(idx, expression);
        unordered_set<string> set;
        vector<string> ans;
        for (int i = 0; i < res.size(); i++)
        {
            if (set.find(res[i]) == set.end())
            {
                ans.push_back(res[i]);
                set.insert(res[i]);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};