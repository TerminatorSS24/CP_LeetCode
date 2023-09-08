/*Design a data structure that follows the constraints of a Least Recently Used (LRU) cache(https://en.wikipedia.org/wiki/Cache_replacement_policies#LRU).

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.

 

Example 1:

Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, null, -1, 3, 4]

Explanation
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4*/
#include <iostream>
#include <unordered_map>

class Node {
public:
    int key, val;
    Node *prev, *next;
    Node(int key, int val) {
        this -> key = key;
        this -> val = val;
        this -> prev = nullptr;
        this -> next = nullptr;
    }
};

class LRUCache {
public:
    std::unordered_map<int, Node*> ump;
    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);
    int capacity;

    void addNode(Node *newNode) {
        Node *temp = head -> next;
        newNode -> next = temp;
        newNode -> prev = head;
        head -> next = newNode;
        temp -> prev = newNode;
    }

    void deleteNode(Node *delNode) {
        delNode -> prev -> next = delNode -> next;
        delNode -> next -> prev = delNode -> prev;
    }

    LRUCache(int capacity) {
        this -> capacity = capacity;
        head -> next = tail;
        tail -> next = head;
    }
    
    int get(int key) {
        if(ump.find(key) != ump.end()) {
            Node *temp = ump[key];
            int result = temp -> val;   
            ump.erase(key);
            deleteNode(temp);
            addNode(temp);
            ump[key] = head -> next;
            return result;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(ump.find(key) != ump.end()) {     
            Node *temp = ump[key];
            temp -> val = value;
            ump.erase(key);
            deleteNode(temp);
        }
        if(ump.size() == capacity) {
            ump.erase(tail -> prev -> key);
            deleteNode(tail -> prev);
        }
        Node *newNode = new Node(key, value);
        addNode(newNode);
        ump[key] = head -> next;
    }
};
