/*
Given a data stream input of non-negative integers a1, a2, ..., an, summarize the numbers seen so far as a list of disjoint intervals.

Implement the SummaryRanges class:

SummaryRanges() Initializes the object with an empty stream.
void addNum(int value) Adds the integer value to the stream.
int[][] getIntervals() Returns a summary of the integers in the stream currently as a list of disjoint intervals [starti, endi]. The answer should be sorted by starti.
 

Example 1:

Input
["SummaryRanges", "addNum", "getIntervals", "addNum", "getIntervals", "addNum", "getIntervals", "addNum", "getIntervals", "addNum", "getIntervals"]
[[], [1], [], [3], [], [7], [], [2], [], [6], []]
Output
[null, null, [[1, 1]], null, [[1, 1], [3, 3]], null, [[1, 1], [3, 3], [7, 7]], null, [[1, 3], [7, 7]], null, [[1, 3], [6, 7]]]

Explanation
SummaryRanges summaryRanges = new SummaryRanges();
summaryRanges.addNum(1);      // arr = [1]
summaryRanges.getIntervals(); // return [[1, 1]]
summaryRanges.addNum(3);      // arr = [1, 3]
summaryRanges.getIntervals(); // return [[1, 1], [3, 3]]
summaryRanges.addNum(7);      // arr = [1, 3, 7]
summaryRanges.getIntervals(); // return [[1, 1], [3, 3], [7, 7]]
summaryRanges.addNum(2);      // arr = [1, 2, 3, 7]
summaryRanges.getIntervals(); // return [[1, 3], [7, 7]]
summaryRanges.addNum(6);      // arr = [1, 2, 3, 6, 7]
summaryRanges.getIntervals(); // return [[1, 3], [6, 7]]
*/
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

class SummaryRanges {
private:
    map<int, int> m_;

public:
    SummaryRanges() = default;
    
    void addNum(int val) {
        auto [it, inserted]  = m_.insert({val, val});
        if (!inserted) return;
        
        // Merge with previous.
        if (it != begin(m_)) {
            auto p = prev(it);
            if (p->second + 1 >= it->first) {
                p->second = max(it->first, p->second);
                m_.erase(it);
                it = p;                
            }
        }
        
        // Merge with next.
        if (it != end(m_)) {
            auto n = next(it);
            if (it->second + 1 == n->first) {
                it->second = n->second;
                m_.erase(n);
            }
        }
    }
    
    vector<vector<int>> getIntervals() const {
        vector<vector<int>> ans;
        ans.reserve(size(m_));
        for (auto [l, r] : m_) ans.push_back({l, r});
        return ans;
    }
};
