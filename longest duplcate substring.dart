/*Given a string s, consider all duplicated substrings: (contiguous) substrings of s that occur 2 or more times. The occurrences may overlap.

Return any duplicated substring that has the longest possible length. If s does not have a duplicated substring, the answer is "".

 

Example 1:

Input: s = "banana"
Output: "ana"
Example 2:

Input: s = "abcd"
Output: ""*/
import 'dart:collection';
class Solution {
  String longestDupSubstring(String s) {
    final N = s.length;
    final prefix = List.filled(N + 1, 0);
    final pows = List.filled(N + 1, 1);
    for (int i = 0; i < N; i++) {
      prefix[i + 1] = prefix[i] * 31 + s.codeUnitAt(i);
      pows[i + 1] = pows[i] * 31;
    }
    int? can(int m) {
      final seen = HashSet<int>();
      for (int i = m - 1; i < s.length; i++) {
        final sum = prefix[i + 1] - pows[m] * prefix[i + 1 - m];
        if (!seen.add(sum))
          return i + 1 - m;
      }
      return null;
    }
    var l = 1, h = s.length;
    while (l <= h) {
      final m = (l + h) ~/ 2;
      if (can(m) == null)
        h = m - 1;
      else
        l = m + 1;
    }
    return h == 0 ? "" : s.substring(can(h)!, can(h)! + h);
  }
}