// Given an m x n board of characters and a list of strings words, return all words on the board.

// Each word must be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

 

// Example 1:

// image: https://assets.leetcode.com/uploads/2020/11/07/search1.jpg

// Input: board = [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]], words = ["oath","pea","eat","rain"]
// Output: ["eat","oath"]
// Example 2:

// image: https://assets.leetcode.com/uploads/2020/11/07/search2.jpg

// Input: board = [["a","b"],["c","d"]], words = ["abcb"]
// Output: []
#include <vector>
#include <string>
#include <functional>
class TrieNode {
public:
  vector<TrieNode*> nodes;  
  const string* word;
  TrieNode(): nodes(26), word(nullptr) {}
  ~TrieNode() {
    for (auto node : nodes) delete node;
  }  
};
class Solution {
public:
  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    TrieNode root;
    
    // Add all the words into Trie.
    for (const string& word : words) {
      TrieNode* cur = &root;
      for (char c : word) {
        auto& next = cur->nodes[c - 'a'];
        if (!next) next = new TrieNode();
        cur = next;
      }
      cur->word = &word;
    }
    
    const int n = board.size();
    const int m = board[0].size();    
    vector<string> ans;
    
    function<void(int, int, TrieNode*)> walk = [&](int x, int y, TrieNode* node) {      
      if (x < 0 || x == m || y < 0 || y == n || board[y][x] == '#')
        return;      
      
      const char cur = board[y][x];
      TrieNode* next_node = node->nodes[cur - 'a'];
      
      // Pruning, only expend paths that are in the trie.
      if (!next_node) return;
      
      if (next_node->word) {
        ans.push_back(*next_node->word);
        next_node->word = nullptr;
      }
 
      board[y][x] = '#';
      walk(x + 1, y, next_node);
      walk(x - 1, y, next_node);
      walk(x, y + 1, next_node);
      walk(x, y - 1, next_node);
      board[y][x] = cur;
    };
    
    // Try all possible pathes.
    for (int i = 0 ; i < n; i++)
      for (int j = 0 ; j < m; j++)
        walk(j, i, &root);        
        
    return ans;
  }
};