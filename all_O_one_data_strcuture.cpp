/*Design a data structure to store the strings' count with the ability to return the strings with minimum and maximum counts.

Implement the AllOne class:

AllOne() Initializes the object of the data structure.
inc(String key) Increments the count of the string key by 1. If key does not exist in the data structure, insert it with count 1.
dec(String key) Decrements the count of the string key by 1. If the count of key is 0 after the decrement, remove it from the data structure. It is guaranteed that key exists in the data structure before the decrement.
getMaxKey() Returns one of the keys with the maximal count. If no element exists, return an empty string "".
getMinKey() Returns one of the keys with the minimum count. If no element exists, return an empty string "".
Note that each function must run in O(1) average time complexity.

 

Example 1:

Input
["AllOne", "inc", "inc", "getMaxKey", "getMinKey", "inc", "getMaxKey", "getMinKey"]
[[], ["hello"], ["hello"], [], [], ["leet"], [], []]
Output
[null, null, null, "hello", "hello", null, "hello", "leet"]

Explanation
AllOne allOne = new AllOne();
allOne.inc("hello");
allOne.inc("hello");
allOne.getMaxKey(); // return "hello"
allOne.getMinKey(); // return "hello"
allOne.inc("leet");
allOne.getMaxKey(); // return "hello"
allOne.getMinKey(); // return "leet"*/
class AllOne {
public:
    
    map<string, int> mp;
    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> mini;
    priority_queue<pair<int, string>> maxi;
    
    
    AllOne(){
        // WASTE
    }
    
    void inc(string key) {
        mp[key]++;
        mini.push({mp[key], key});
        maxi.push({mp[key], key});
    }
    
    void dec(string key) {
        mp[key]--;
        mini.push({mp[key], key});
        maxi.push({mp[key], key});
    }
    
    string getMaxKey() {
        while(maxi.size()){
            if(maxi.top().first == mp[maxi.top().second] && mp[maxi.top().second]){
                return maxi.top().second;
                break;
            }else{
                maxi.pop();
            }
        }return "";
    }
    
    string getMinKey() {
        while(mini.size()){
            if(mini.top().first == mp[mini.top().second] && mp[mini.top().second]){
                return mini.top().second;
                break;
            }else{
                mini.pop();
            }
        }return "";
    }
};