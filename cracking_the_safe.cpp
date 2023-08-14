/*There is a safe protected by a password. The password is a sequence of n digits where each digit can be in the range [0, k - 1].

The safe has a peculiar way of checking the password. When you enter in a sequence, it checks the most recent n digits that were entered each time you type a digit.

For example, the correct password is "345" and you enter in "012345":
After typing 0, the most recent 3 digits is "0", which is incorrect.
After typing 1, the most recent 3 digits is "01", which is incorrect.
After typing 2, the most recent 3 digits is "012", which is incorrect.
After typing 3, the most recent 3 digits is "123", which is incorrect.
After typing 4, the most recent 3 digits is "234", which is incorrect.
After typing 5, the most recent 3 digits is "345", which is correct and the safe unlocks.
Return any string of minimum length that will unlock the safe at some point of entering it.
Example 1:

Input: n = 1, k = 2
Output: "10"
Explanation: The password is a single digit, so enter each digit. "01" would also unlock the safe.
Example 2:

Input: n = 2, k = 2
Output: "01100"
Explanation: For each possible password:
- "00" is typed in starting from the 4th digit.
- "01" is typed in starting from the 1st digit.
- "10" is typed in starting from the 3rd digit.
- "11" is typed in starting from the 2nd digit.
Thus "01100" will unlock the safe. "10011", and "11001" would also unlock the safe.*/
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> g[100000];
    map<string, int> m1;
    vector<string> m2;

    void help(int n, int k, string s) {
        if (n == 0) {
            m2.push_back(s);
            m1[s] = m2.size() - 1;
            return;
        }
        for (int i = 0; i < k; i++) {
            help(n - 1, k, s + to_string(i));
        }
    }

    string crackSafe(int n, int k) {
        if (n == 1) {
            string s = "";
            for (int i = 0; i < k; i++) {
                s = s + to_string(i);
            }
            return s;
        }
        help(n - 1, k, "");
        int sz = m2.size();
        for (int i = 0; i < sz; i++) {
            string t = m2[i];
            int in = m1[t];
            string t1 = t.substr(1);
            for (int i = 0; i < k; i++) {
                string t2 = t1 + to_string(i);
                int in1 = m1[t2];
                g[in].push_back(in1);
            }
        }
        stack<int> st;
        st.push(0);
        vector<int> path;
        while (!st.empty()) {
            int node = st.top();
            if ((int)g[node].size() == 0) {
                path.push_back(node);
                st.pop();
            } else {
                int x = g[node].back();
                g[node].pop_back();
                st.push(x);
            }
        }
        string ans = "";
        for (int i = 0; i < (int)path.size() - 1; i++)
            ans += m2[path[i]][n - 2];
        ans += m2[0];
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
