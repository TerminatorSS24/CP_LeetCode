/*You are given an m x n grid grid where:

'.' is an empty cell.
'#' is a wall.
'@' is the starting point.
Lowercase letters represent keys.
Uppercase letters represent locks.
You start at the starting point and one move consists of walking one space in one of the four cardinal directions. You cannot walk outside the grid, or walk into a wall.

If you walk over a key, you can pick it up and you cannot walk over a lock unless you have its corresponding key.

For some 1 <= k <= 6, there is exactly one lowercase and one uppercase letter of the first k letters of the English alphabet in the grid. This means that there is exactly one key for each lock, and one lock for each key; and also that the letters used to represent the keys and locks were chosen in the same order as the English alphabet.

Return the lowest number of moves to acquire all keys. If it is impossible, return -1.

 

Example 1:

image: https://assets.leetcode.com/uploads/2021/07/23/lc-keys2.jpg

Input: grid = ["@.a..","###.#","b.A.B"]
Output: 8
Explanation: Note that the goal is to obtain all the keys not to open all the locks.
Example 2:

image: https://assets.leetcode.com/uploads/2021/07/23/lc-keys2.jpg

Input: grid = ["@..aA","..B#.","....b"]
Output: 6
Example 3:

iamge: https://assets.leetcode.com/uploads/2021/07/23/lc-keys3.jpg

Input: grid = ["@Aa"]
Output: -1*/
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <unordered_set>
#include <utility>

class Solution {
public:
    int shortestPathAllKeys(std::vector<std::string>& grid) {
        const int m = grid.size();
        const int n = grid[0].size();
        int targetKeychain = 0;
        std::queue<std::tuple<int, int, int>> queue;
        std::vector<std::vector<std::unordered_set<int>>> visited(m, std::vector<std::unordered_set<int>>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '@') {
                    queue.push({i, j, 0});
                    visited[i][j].insert(0);
                } else if (isKey(grid[i][j])) {
                    targetKeychain = addKey(targetKeychain, grid[i][j]);
                }
            }
        }
        static const std::vector<std::pair<int, int>> kDirections{{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
        int moves = 0;
        while (!queue.empty()) {
            const int size = queue.size();
            for (int k = 0; k < size; ++k) {
                const auto [x, y, keychain] = queue.front();
                queue.pop();
                for (const auto& [dx, dy] : kDirections) {
                    const int i = x + dx; 
                    const int j = y + dy;
                    if (i < 0 || i >= m || j < 0 || j >= n)
                        continue;
                    if (grid[i][j] == '#')
                        continue;
                    if (isLock(grid[i][j]) && !canOpen(keychain, grid[i][j]))
                        continue;
                    int newKeychain = keychain;
                    if (isKey(grid[i][j])) {
                        newKeychain = addKey(keychain, grid[i][j]);
                    }
                    if (visited[i][j].count(newKeychain))
                        continue;
                    if (newKeychain == targetKeychain)
                        return moves + 1;

                    queue.push({i, j, newKeychain});
                    visited[i][j].insert(newKeychain);
                }
            }
            moves++;
        }
        return -1;
    }

private:
    int addKey(int currentKeychain, char key) {
        return currentKeychain | (1 << (key - 'a'));
    }

    bool canOpen(int currentKeychain, char lock) {
        return (currentKeychain >> (lock - 'A')) & 1;
    }

    bool isLock(char c) {
        return c >= 'A' && c <= 'Z';
    }

    bool isKey(char c) {
        return c >= 'a' && c <= 'z';
    }
};