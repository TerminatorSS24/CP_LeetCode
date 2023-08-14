/*Design a special dictionary that searches the words in it by a prefix and a suffix.

Implement the WordFilter class:

WordFilter(string[] words) Initializes the object with the words in the dictionary.
f(string pref, string suff) Returns the index of the word in the dictionary, which has the prefix pref and the suffix suff. If there is more than one valid index, return the largest of them. If there is no such word in the dictionary, return -1.
 

Example 1:

Input
["WordFilter", "f"]
[[["apple"]], ["a", "e"]]
Output
[null, 0]
Explanation
WordFilter wordFilter = new WordFilter(["apple"]);
wordFilter.f("a", "e"); // return 0, because the word at index 0 has prefix = "a" and suffix = "e".*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Trie {
    Trie* child[27];
    bool isEnd;
    int idx;
    Trie() {
        for (int i = 0; i < 27; i++) {
            child[i] = NULL;
        }
        isEnd = false;
        idx = -1;
    }
};

class WordFilter {
public:
    Trie* prefRoot = new Trie();

    void insert(string word, Trie* root, int id) {
        Trie* curr = root;
        for (auto i : word) {
            int p = i - 'a';
            if (curr->child[p] == NULL) {
                curr->child[p] = new Trie();
            }
            curr = curr->child[p];
            curr->idx = max(id, curr->idx);
        }
        curr->isEnd = true;
    }

    WordFilter(vector<string>& words) {
        for (int i = 0; i < words.size(); i++) {
            reverse(words[i].begin(), words[i].end());
            string temp = words[i] + '{';
            reverse(words[i].begin(), words[i].end());
            for (int j = words[i].length() - 1; j >= 0; j--) {
                temp += words[i][j];
                string t = temp;
                reverse(t.begin(), t.end());
                insert(t, prefRoot, i);
            }
            reverse(temp.begin(), temp.end());
            insert(temp, prefRoot, i);
        }
    }

    void helper(string s, int& ans, Trie* prefRoot) {
        Trie* curr = prefRoot;
        for (auto i : s) {
            int p = i - 'a';
            if (curr->child[p] == NULL) {
                return;
            }
            curr = curr->child[p];
        }
        ans = curr->idx;
        return;
    }

    int f(string pref, string suff) {
        int ans = -1;
        helper(suff + '{' + pref, ans, prefRoot);
        return ans;
    }
};

