/*You are given an integer n and an array of unique integers blacklist. Design an algorithm to pick a random integer in the range [0, n - 1] that is not in blacklist. Any integer that is in the mentioned range and not in blacklist should be equally likely to be returned.

Optimize your algorithm such that it minimizes the number of calls to the built-in random function of your language.

Implement the Solution class:

Solution(int n, int[] blacklist) Initializes the object with the integer n and the blacklisted integers blacklist.
int pick() Returns a random integer in the range [0, n - 1] and not in blacklist.
 

Example 1:

Input
["Solution", "pick", "pick", "pick", "pick", "pick", "pick", "pick"]
[[7, [2, 3, 5]], [], [], [], [], [], [], []]
Output
[null, 0, 4, 1, 6, 1, 0, 4]

Explanation
Solution solution = new Solution(7, [2, 3, 5]);
solution.pick(); // return 0, any integer from [0,1,4,6] should be ok. Note that for every call of pick,
                 // 0, 1, 4, and 6 must be equally likely to be returned (i.e., with probability 1/4).
solution.pick(); // return 4
solution.pick(); // return 1
solution.pick(); // return 6
solution.pick(); // return 1
solution.pick(); // return 0
solution.pick(); // return 4*/
#include <iostream>
#include <vector>
#include <unordered_set>
#include <cstdlib> // for rand()

using namespace std;

class Solution {
public:
    int approach;
    int n, m;
    unordered_set<int> hash_set;
    vector<int> whitelist;

    Solution(int nn, vector<int>& blacklist) {
        n = nn;
        m = blacklist.size();
        for(auto it : blacklist) {
            hash_set.insert(it);
        }
        if(m * 2 < n) {
            approach = 1;
        }
        else {
            approach = 2;
            for(int i = 0; i < n; i++) {
                if(hash_set.find(i) == hash_set.end()) {
                    whitelist.push_back(i);
                }
            }
        }
    }
    
    int pick() {
        if(approach == 1) {
            while(true) {
                int val = rand() % n;
                if(hash_set.find(val) == hash_set.end()) {
                    return val;
                }
            }
        }
        else {
            int idx = rand() % whitelist.size();
            return whitelist[idx];
        }
    }
};
