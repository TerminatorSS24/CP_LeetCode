/*Design a stack-like data structure to push elements to the stack and pop the most frequent element from the stack.

Implement the FreqStack class:

FreqStack() constructs an empty frequency stack.
void push(int val) pushes an integer val onto the top of the stack.
int pop() removes and returns the most frequent element in the stack.
If there is a tie for the most frequent element, the element closest to the stack's top is removed and returned.
 

Example 1:

Input
["FreqStack", "push", "push", "push", "push", "push", "push", "pop", "pop", "pop", "pop"]
[[], [5], [7], [5], [7], [4], [5], [], [], [], []]
Output
[null, null, null, null, null, null, null, 5, 7, 5, 4]

Explanation
FreqStack freqStack = new FreqStack();
freqStack.push(5); // The stack is [5]
freqStack.push(7); // The stack is [5,7]
freqStack.push(5); // The stack is [5,7,5]
freqStack.push(7); // The stack is [5,7,5,7]
freqStack.push(4); // The stack is [5,7,5,7,4]
freqStack.push(5); // The stack is [5,7,5,7,4,5]
freqStack.pop();   // return 5, as 5 is the most frequent. The stack becomes [5,7,5,7,4].
freqStack.pop();   // return 7, as 5 and 7 is the most frequent, but 7 is closest to the top. The stack becomes [5,7,5,4].
freqStack.pop();   // return 5, as 5 is the most frequent. The stack becomes [5,7,4].
freqStack.pop();   // return 4, as 4, 5 and 7 is the most frequent, but 4 is closest to the top. The stack becomes [5,7].*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

class FreqStack {
public:
    unordered_map<int, int> freq;
    priority_queue<vector<int>> pq;
    int counter = 0;
    FreqStack() {

    }
    
    void push(int val) {

        freq[val]++;
        pq.push({freq[val], counter, val});
        counter++;
    }
    
    int pop() {  
        auto it = pq.top();
        pq.pop();

        int ans = it[2];
        int curr = it[0]; 

        freq[ans]--;
        if (freq[ans] == 0) freq.erase(ans);

        return ans;
    }
};

class Solution {
    #define ll long long
    int mod = 1e9 + 7;
    int power(ll x, ll y) {
        int res = 1;  
        x = x % mod; 
        if (x == 0) return 0;
    
        while (y > 0) {
            if (y & 1)
                res = (res * x) % mod;
    
            y = y >> 1; 
            x = (x * x) % mod;
        }
        return res;
    }
public:
    int sumSubseqWidths(vector<int>& nums) {
        ll ans = 0, n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; ++i) {
            ans = (ans + nums[i] * 1ll * power(2, i)) % mod;
            ans = (ans - nums[i] * 1ll * power(2, n - i - 1)) % mod;
        }
        return ans;
    }
};
