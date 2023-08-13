/*You are playing a variation of the game Zuma.

In this variation of Zuma, there is a single row of colored balls on a board, where each ball can be colored red 'R', yellow 'Y', blue 'B', green 'G', or white 'W'. You also have several colored balls in your hand.

Your goal is to clear all of the balls from the board. On each turn:

Pick any ball from your hand and insert it in between two balls in the row or on either end of the row.
If there is a group of three or more consecutive balls of the same color, remove the group of balls from the board.
If this removal causes more groups of three or more of the same color to form, then continue removing each group until there are none left.
If there are no more balls on the board, then you win the game.
Repeat this process until you either win or do not have any more balls in your hand.
Given a string board, representing the row of balls on the board, and a string hand, representing the balls in your hand, return the minimum number of balls you have to insert to clear all the balls from the board. If you cannot clear all the balls from the board using the balls in your hand, return -1.

 

Example 1:

Input: board = "WRRBBW", hand = "RB"
Output: -1
Explanation: It is impossible to clear all the balls. The best you can do is:
- Insert 'R' so the board becomes WRRRBBW. WRRRBBW -> WBBW.
- Insert 'B' so the board becomes WBBBW. WBBBW -> WW.
There are still balls remaining on the board, and you are out of balls to insert.
Example 2:

Input: board = "WWRRBBWW", hand = "WRBRW"
Output: 2
Explanation: To make the board empty:
- Insert 'R' so the board becomes WWRRRBBWW. WWRRRBBWW -> WWBBWW.
- Insert 'B' so the board becomes WWBBBWW. WWBBBWW -> WWWW -> empty.
2 balls from your hand were needed to clear the board.
Example 3:

Input: board = "G", hand = "GGGGG"
Output: 2
Explanation: To make the board empty:
- Insert 'G' so the board becomes GG.
- Insert 'G' so the board becomes GGG. GGG -> empty.
2 balls from your hand were needed to clear the board.*/
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int findMinStep(string board, string hand) {
        vector<int> freq(26, 0);
        for (char c : hand)
            freq[c - 'A']++;
        unordered_map<string, int> cache;
        return dfs(board, freq, cache);
    }

    int dfs(string board, vector<int>& freq, unordered_map<string, int>& cache) {
        string key = board + "#" + serialize(freq);
        if (cache.count(key)) {
            return cache[key];
        }
        int r = INT_MAX;
        if (board.length() == 0) {
            r = 0;
        } else {
            for (int i = 0; i < board.length(); i++) {
                for (int j = 0; j < freq.size(); j++) {
                    bool worthTrying = false;
                    if (board[i] - 'A' == j)
                        worthTrying = true;
                    else if (0 < i && board[i] == board[i - 1] && board[i] - 'A' != j)
                        worthTrying = true;

                    if (freq[j] > 0 && worthTrying) {
                        board.insert(board.begin() + i, j + 'A');
                        freq[j]--;

                        string newStr = updateBoard(board);
                        int steps = dfs(newStr, freq, cache);
                        if (steps != -1) {
                            r = min(r, steps + 1);
                        }

                        freq[j]++;
                        board.erase(board.begin() + i);
                    }
                }
            }
        }
        if (r == INT_MAX) r = -1;
        cache[key] = r;
        return r;
    }

    string updateBoard(string board) {
        int start = 0;
        int end = 0;
        int boardLen = board.length();
        while (start < boardLen) {
            while (end < boardLen && board[start] == board[end]) {
                end++;
            }
            if (end - start >= 3) {
                string newBoard = board.substr(0, start) + board.substr(end);
                return updateBoard(newBoard);
            } else {
                start = end;
            }
        }
        return board;
    }

    string serialize(vector<int>& freq) {
        string key = "";
        for (int i = 0; i < freq.size(); i++) {
            if (freq[i] > 0)
                key += to_string((char)i + 'A') + to_string(freq[i]);
        }
        return key;
    }
};
