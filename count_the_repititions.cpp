/*We define str = [s, n] as the string str which consists of the string s concatenated n times.

For example, str == ["abc", 3] =="abcabcabc".
We define that string s1 can be obtained from string s2 if we can remove some characters from s2 such that it becomes s1.

For example, s1 = "abc" can be obtained from s2 = "abdbec" based on our definition by removing the bolded underlined characters.
You are given two strings s1 and s2 and two integers n1 and n2. You have the two strings str1 = [s1, n1] and str2 = [s2, n2].

Return the maximum integer m such that str = [str2, m] can be obtained from str1.

 

Example 1:

Input: s1 = "acb", n1 = 4, s2 = "ab", n2 = 2
Output: 2
Example 2:

Input: s1 = "acb", n1 = 1, s2 = "acb", n2 = 1
Output: 1*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        int len1 = s1.length(), len2 = s2.length();
        vector<int> repeatCount(len2 + 1, 0);
        vector<int> nextIndex(len2 + 1, 0);

        int count1 = 0, count2 = 0, j = 0;
        for (int k = 1; k <= n1; k++) {
            for (int i = 0; i < len1; i++) {
                if (s1[i] == s2[j]) {
                    j++;
                    if (j == len2) {
                        j = 0;
                        count2++;
                    }
                }
            }
            count1++;

            // Check for repetition pattern
            repeatCount[k] = count2;
            nextIndex[k] = j;

            for (int start = 0; start < k; start++) {
                if (nextIndex[start] == j) {
                    int prefixCount = repeatCount[start];
                    int patternCount = (n1 - start) / (k - start) * (repeatCount[k] - repeatCount[start]);
                    int suffixCount = repeatCount[start + (n1 - start) % (k - start)] - repeatCount[start];
                    return (prefixCount + patternCount + suffixCount) / n2;
                }
            }
        }

        return count2 / n2;
    }
};

