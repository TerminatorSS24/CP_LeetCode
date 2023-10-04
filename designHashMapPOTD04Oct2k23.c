/*Design a HashMap without using any built-in hash table libraries.

Implement the MyHashMap class:

MyHashMap() initializes the object with an empty map.
void put(int key, int value) inserts a (key, value) pair into the HashMap. If the key already exists in the map, update the corresponding value.
int get(int key) returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key.
void remove(key) removes the key and its corresponding value if the map contains the mapping for the key.
 

Example 1:

Input
["MyHashMap", "put", "put", "get", "get", "put", "get", "remove", "get"]
[[], [1, 1], [2, 2], [1], [3], [2, 1], [2], [2], [2]]
Output
[null, null, null, 1, -1, null, 1, null, -1]

Explanation
MyHashMap myHashMap = new MyHashMap();
myHashMap.put(1, 1); // The map is now [[1,1]]
myHashMap.put(2, 2); // The map is now [[1,1], [2,2]]
myHashMap.get(1);    // return 1, The map is now [[1,1], [2,2]]
myHashMap.get(3);    // return -1 (i.e., not found), The map is now [[1,1], [2,2]]
myHashMap.put(2, 1); // The map is now [[1,1], [2,1]] (i.e., update the existing value)
myHashMap.get(2);    // return 1, The map is now [[1,1], [2,1]]
myHashMap.remove(2); // remove the mapping for 2, The map is now [[1,1]]
myHashMap.get(2);    // return -1 (i.e., not found), The map is now [[1,1]]
**********LEETCODE POTD(04/10/2023)**********
*/
#include <stdio.h>
#include <stdlib.h>
typedef struct KeyValuePair
{
    int key;
    int value;
    struct KeyValuePair *next;
} KeyValuePair;

typedef struct
{
    KeyValuePair **table;
    int size;
} MyHashMap;

MyHashMap *myHashMapCreate()
{
    int initial_size = 1000; // Initial size of the HashMap
    MyHashMap *hashMap = (MyHashMap *)malloc(sizeof(MyHashMap));
    hashMap->table = (KeyValuePair **)malloc(sizeof(KeyValuePair *) * initial_size);
    hashMap->size = initial_size;
    for (int i = 0; i < initial_size; i++)
    {
        hashMap->table[i] = NULL;
    }
    return hashMap;
}

int hash(int key, int size)
{
    return key % size;
}

void myHashMapPut(MyHashMap *obj, int key, int value)
{
    int index = hash(key, obj->size);
    KeyValuePair *newNode = (KeyValuePair *)malloc(sizeof(KeyValuePair));
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;

    if (obj->table[index] == NULL)
    {
        obj->table[index] = newNode;
    }
    else
    {
        // Handle collisions by chaining
        KeyValuePair *current = obj->table[index];
        while (current->next != NULL)
        {
            if (current->key == key)
            {
                current->value = value; // Update the value if the key already exists
                free(newNode);
                return;
            }
            current = current->next;
        }
        if (current->key == key)
        {
            current->value = value; // Update the value if the key already exists
            free(newNode);
        }
        else
        {
            current->next = newNode;
        }
    }
}

int myHashMapGet(MyHashMap *obj, int key)
{
    int index = hash(key, obj->size);
    KeyValuePair *current = obj->table[index];
    while (current != NULL)
    {
        if (current->key == key)
        {
            return current->value; // Return the value if the key is found
        }
        current = current->next;
    }
    return -1; // Key not found
}

void myHashMapRemove(MyHashMap *obj, int key)
{
    int index = hash(key, obj->size);
    KeyValuePair *current = obj->table[index];
    KeyValuePair *prev = NULL;

    while (current != NULL)
    {
        if (current->key == key)
        {
            if (prev != NULL)
            {
                prev->next = current->next;
            }
            else
            {
                obj->table[index] = current->next;
            }
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

void myHashMapFree(MyHashMap *obj)
{
    for (int i = 0; i < obj->size; i++)
    {
        KeyValuePair *current = obj->table[i];
        while (current != NULL)
        {
            KeyValuePair *temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(obj->table);
    free(obj);
}