/*Design and implement a data structure for a Least Frequently Used (LFU) cache.

Implement the LFUCache class:

LFUCache(int capacity) Initializes the object with the capacity of the data structure.
int get(int key) Gets the value of the key if the key exists in the cache. Otherwise, returns -1.
void put(int key, int value) Update the value of the key if present, or inserts the key if not already present. When the cache reaches its capacity, it should invalidate and remove the least frequently used key before inserting a new item. For this problem, when there is a tie (i.e., two or more keys with the same frequency), the least recently used key would be invalidated.
To determine the least frequently used key, a use counter is maintained for each key in the cache. The key with the smallest use counter is the least frequently used key.

When a key is first inserted into the cache, its use counter is set to 1 (due to the put operation). The use counter for a key in the cache is incremented either a get or put operation is called on it.

The functions get and put must each run in O(1) average time complexity.

 

Example 1:

Input
["LFUCache", "put", "put", "get", "put", "get", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [3], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, 3, null, -1, 3, 4]

Explanation
// cnt(x) = the use counter for key x
// cache=[] will show the last used order for tiebreakers (leftmost element is  most recent)
LFUCache lfu = new LFUCache(2);
lfu.put(1, 1);   // cache=[1,_], cnt(1)=1
lfu.put(2, 2);   // cache=[2,1], cnt(2)=1, cnt(1)=1
lfu.get(1);      // return 1
                 // cache=[1,2], cnt(2)=1, cnt(1)=2
lfu.put(3, 3);   // 2 is the LFU key because cnt(2)=1 is the smallest, invalidate 2.
                 // cache=[3,1], cnt(3)=1, cnt(1)=2
lfu.get(2);      // return -1 (not found)
lfu.get(3);      // return 3
                 // cache=[3,1], cnt(3)=2, cnt(1)=2
lfu.put(4, 4);   // Both 1 and 3 have the same cnt, but 1 is LRU, invalidate 1.
                 // cache=[4,3], cnt(4)=1, cnt(3)=2
lfu.get(1);      // return -1 (not found)
lfu.get(3);      // return 3
                 // cache=[3,4], cnt(4)=1, cnt(3)=3
lfu.get(4);      // return 4
                 // cache=[4,3], cnt(4)=2, cnt(3)=3*/
#include <iostream>
#include <vector>
#include <map>

class LFUCache {
public:
    int cap;
    int size;
    
    struct node {
        int key;
        int freq;
        int val;
        node* next;
        node* pre;
        
        node(int x, int y) {
            val = x;
            key = y;
            freq = 0;
            next = NULL;
            pre = NULL;
        }
    };
    
    std::vector<node*> fq;
    std::map<int, node*> mp;
    node *head, *tail;
    
    LFUCache(int capacity) {
        cap = capacity;
        size = 0;
        fq.push_back(NULL);
        fq.push_back(NULL);
        head = NULL;
        tail = NULL;
    }
    
    int get(int key) {
        if (mp.find(key) == mp.end())
            return -1;
        else {
            node* temp = mp[key];
            int f = temp->freq;
            
            if (fq.size() <= f + 1)
                fq.push_back(NULL);
            
            if (tail == temp && temp != head && temp->pre->freq <= f + 1)
                tail = temp->pre;
            
            if (fq[f] == temp) {
                if (temp->next && f == temp->next->freq)
                    fq[temp->freq] = temp->next;
                else
                    fq[f] = NULL;
            }
            
            temp->freq++;
            f++;
            
            if (fq[f] == NULL) {
                if (fq[f - 1] != NULL && fq[f - 1] != temp->next) {
                    if (temp->next) temp->next->pre = temp->pre;
                    if (temp->pre) temp->pre->next = temp->next;
                    
                    node* t = fq[f - 1];
                    temp->next = t;
                    temp->pre = t->pre;
                    
                    if (t == head)
                        head = temp;
                    else
                        t->pre->next = temp;
                    
                    t->pre = temp;
                }
            } else {
                if (temp->next) temp->next->pre = temp->pre;
                if (temp->pre) temp->pre->next = temp->next;
                
                node* t = fq[f];
                temp->pre = t->pre;
                temp->next = t;
                
                if (t == head)
                    head = temp;
                else
                    t->pre->next = temp;
                
                t->pre = temp;
            }
            
            fq[f] = temp;
            return temp->val;
        }
    }
    
    void put(int key, int value) {
        if (get(key) != -1) {
            mp[key]->val = value;
        } else {
            node* t1 = new node(value, key);
            mp[key] = t1;
            size++;
            
            if (size > cap) {
                node* temp = tail;
                if (fq[tail->freq] == temp) fq[tail->freq] = NULL;
                
                if (tail == head) {
                    head = NULL;
                } else
                    tail->pre->next = NULL;
                
                tail = tail->pre;
                mp.erase(temp->key);
                delete (temp);
                
                size--;
            }
            
            if (head == NULL || size == 0) {
                head = t1;
                tail = t1;
                fq[1] = t1;
                t1->freq = 1;
                return;
            }
            
            fq[0] = t1;
            tail->next = t1;
            t1->pre = tail;
            tail = t1;
            
            get(key);
            node* t = head;
        }
    }
};
