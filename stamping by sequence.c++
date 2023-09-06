/*You are given two strings stamp and target. Initially, there is a string s of length target.length with all s[i] == '?'.

In one turn, you can place stamp over s and replace every letter in the s with the corresponding letter from stamp.

For example, if stamp = "abc" and target = "abcba", then s is "?????" initially. In one turn you can:
place stamp at index 0 of s to obtain "abc??",
place stamp at index 1 of s to obtain "?abc?", or
place stamp at index 2 of s to obtain "??abc".
Note that stamp must be fully contained in the boundaries of s in order to stamp (i.e., you cannot place stamp at index 3 of s).
We want to convert s to target using at most 10 * target.length turns.

Return an array of the index of the left-most letter being stamped at each turn. If we cannot obtain target from s within 10 * target.length turns, return an empty array.

 

Example 1:

Input: stamp = "abc", target = "ababc"
Output: [0,2]
Explanation: Initially s = "?????".
- Place stamp at index 0 to get "abc??".
- Place stamp at index 2 to get "ababc".
[1,0,2] would also be accepted as an answer, as well as some other answers.
Example 2:

Input: stamp = "abca", target = "aabcaca"
Output: [3,0,1]
Explanation: Initially s = "???????".
- Place stamp at index 3 to get "???abca".
- Place stamp at index 0 to get "abcabca".
- Place stamp at index 1 to get "aabcaca".*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
 public:
  vector<int> movesToStamp(string stamp, string target) {
    vector<int> ans;
    vector<bool> stamped(target.length());
    int stampedCount = 0;

    while (stampedCount < target.length()) {
      bool isStamped = false;
      for (int i = 0; i <= target.length() - stamp.length(); ++i) {
        if (stamped[i])
          continue;
        const int stampified = stampify(stamp, target, i);
        if (stampified == 0)
          continue;
        stampedCount += stampified;
        isStamped = true;
        stamped[i] = true;
        ans.push_back(i);
      }
      if (!isStamped)
        return {};
    }

    reverse(ans.begin(), ans.end());
    return ans;
  }

 private:
  int stampify(const string& stamp, string& target, int s) {
    int stampified = stamp.length();

    for (int i = 0; i < stamp.length(); ++i)
      if (target[s + i] == '*')
        --stampified;
      else if (target[s + i] != stamp[i])
        return 0;

    if (stampified > 0)
      fill(target.begin() + s, target.begin() + s + stamp.length(), '*');

    return stampified;
  }
};
