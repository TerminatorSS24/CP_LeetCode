/*Given a string formula representing a chemical formula, return the count of each atom.

The atomic element always starts with an uppercase character, then zero or more lowercase letters, representing the name.

One or more digits representing that element's count may follow if the count is greater than 1. If the count is 1, no digits will follow.

For example, "H2O" and "H2O2" are possible, but "H1O2" is impossible.
Two formulas are concatenated together to produce another formula.

For example, "H2O2He3Mg4" is also a formula.
A formula placed in parentheses, and a count (optionally added) is also a formula.

For example, "(H2O2)" and "(H2O2)3" are formulas.
Return the count of all elements as a string in the following form: the first name (in sorted order), followed by its count (if that count is more than 1), followed by the second name (in sorted order), followed by its count (if that count is more than 1), and so on.

The test cases are generated so that all the values in the output fit in a 32-bit integer.



Example 1:

Input: formula = "H2O"
Output: "H2O"
Explanation: The count of elements are {'H': 2, 'O': 1}.
Example 2:

Input: formula = "Mg(OH)2"
Output: "H2MgO2"
Explanation: The count of elements are {'H': 2, 'Mg': 1, 'O': 2}.
Example 3:

Input: formula = "K4(ON(SO3)2)2"
Output: "K4N2O14S4"
Explanation: The count of elements are {'K': 4, 'N': 2, 'O': 14, 'S': 4}.*/
#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

class Solution
{
    bool isDig(char c)
    {
        if (c >= '0' && c <= '9')
            return true;
        return false;
    }

    string mul(string num1, string num2)
    {
        if (num1.size() < num2.size())
            swap(num1, num2);

        int n = num1.size(), m = num2.size();
        string ans(n + m, '0');

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                int sum = ans[i + j + 1] - '0' + (num1[i] - '0') * (num2[j] - '0');
                ans[i + j + 1] = (sum % 10) + '0';
                ans[i + j] += (sum / 10);
            }
        }

        for (int i = 0; i < (n + m); i++)
        {
            if (ans[i] != '0')
                return ans.substr(i, n + m - i);
        }

        return "0";
    }

    string add(string num1, string num2)
    {
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        int carry = 0;
        string res = "";
        while (i >= 0 || j >= 0 || carry)
        {
            long sum = 0;
            if (i >= 0)
            {
                sum += (num1[i] - '0');
                i--;
            }
            if (j >= 0)
            {
                sum += (num2[j] - '0');
                j--;
            }
            sum += carry;
            carry = sum / 10;
            sum = sum % 10;
            res = res + to_string(sum);
        }
        reverse(res.begin(), res.end());
        return res;
    }

public:
    string countOfAtoms(string formula)
    {
        stack<pair<string, string>> st;
        string s = formula;

        int n = s.size();

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
                st.push({"(", "1"});
            else if (s[i] == ')')
            {
                vector<pair<string, string>> v;
                while (!st.empty() && st.top().first != "(")
                {
                    v.push_back(st.top());
                    st.pop();
                }
                st.pop();
                string cnt = "1";

                int j = i + 1;
                if (i + 1 < n && isDig(s[i + 1]))
                {
                    cnt = "";
                    while (j < n && isDig(s[j]))
                        cnt += s[j++];
                    i = --j;
                }
                while (!v.empty())
                {
                    auto last = v.back();
                    v.pop_back();
                    st.push({last.first, mul(last.second, cnt)});
                }
            }
            else
            {
                string che = "";
                che += s[i];
                int j = i + 1;

                while (j < n && s[j] >= 'a' && s[j] <= 'z')
                    che += s[j++];

                string cnt = "1";

                if (j < n && isDig(s[j]))
                {
                    cnt = "";
                    while (j < n && isDig(s[j]))
                        cnt += s[j++];
                }
                st.push({che, cnt});
                i = --j;
            }
        }

        map<string, string> mp;
        while (!st.empty())
        {
            auto fst = st.top();
            st.pop();
            if (!mp.count(fst.first))
                mp[fst.first] = "0";
            mp[fst.first] = add(mp[fst.first], fst.second);
        }

        string ans;

        for (auto e : mp)
        {
            cout << e.first << " " << e.second << endl;
            ans += e.first;
            if (e.second != "1")
                ans += e.second;
        }

        return ans;
    }
};
