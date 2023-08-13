/*A Range Module is a module that tracks ranges of numbers. Design a data structure to track the ranges represented as half-open intervals and query about them.

A half-open interval [left, right) denotes all the real numbers x where left <= x < right.

Implement the RangeModule class:

RangeModule() Initializes the object of the data structure.
void addRange(int left, int right) Adds the half-open interval [left, right), tracking every real number in that interval. Adding an interval that partially overlaps with currently tracked numbers should add any numbers in the interval [left, right) that are not already tracked.
boolean queryRange(int left, int right) Returns true if every real number in the interval [left, right) is currently being tracked, and false otherwise.
void removeRange(int left, int right) Stops tracking every real number currently being tracked in the half-open interval [left, right).
 

Example 1:

Input
["RangeModule", "addRange", "removeRange", "queryRange", "queryRange", "queryRange"]
[[], [10, 20], [14, 16], [10, 14], [13, 15], [16, 17]]
Output
[null, null, null, true, false, true]

Explanation
RangeModule rangeModule = new RangeModule();
rangeModule.addRange(10, 20);
rangeModule.removeRange(14, 16);
rangeModule.queryRange(10, 14); // return True,(Every number in [10, 14) is being tracked)
rangeModule.queryRange(13, 15); // return False,(Numbers like 14, 14.03, 14.17 in [13, 15) are not being tracked)
rangeModule.queryRange(16, 17); // return True, (The number 16 in [16, 17) is still being tracked, despite the remove operation)*/
#include <iostream>
#include <vector>
#include <set>
#include <utility>

class RangeModule {
    std::set<std::pair<int, int>> st;  
public:
    bool overlap(std::pair<int, int> a, std::pair<int, int> b){
        if(a.first > b.second || a.second < b.first) return false;
        return true;
    }
    
    RangeModule() {
        
    }
    
    void addRange(int l, int r) {
        r--;
        std::vector<std::pair<int, int>> temp;
        
        for(auto i : st) temp.push_back(i);
        
        for(auto i : temp){
            if(overlap({l, r}, i)){
                st.erase(i);
                l = std::min(l, i.first);
                r = std::max(r, i.second);
            }
        } 
        
        st.insert({l, r});  
    }
    
    bool queryRange(int l, int r) {
        r--;
        
        for(auto i : st){
            if(overlap(i, {l, r})){
                if(i.first <= l && i.second >= r) return true;
                if(i.first > l) r = i.first - 1;
                if(r > i.second) l = i.second + 1;
            }
        }
        
        return l <= 0 || r <= 0;
    }
    
    void removeRange(int l, int r) {
        r--;
        std::vector<std::pair<int, int>> temp;
        
        for(auto i : st) temp.push_back(i);
        
        for(auto i : temp){
            if(overlap({l, r}, i)){
                st.erase(i);
                if(l > i.first) st.insert({i.first, l - 1});
                if(r < i.second) st.insert({r + 1, i.second});
            }
        }
    }
};