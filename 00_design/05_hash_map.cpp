/*
https://leetcode.com/problems/design-hashmap/

Design a HashMap without using any built-in hash table libraries.

To be specific, your design should include these functions:

put(key, value) : Insert a (key, value) pair into the HashMap. If the value already exists in the HashMap, update the value.
get(key): Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key.
remove(key) : Remove the mapping for the value key if this map contains the mapping for the key.

Example:

MyHashMap hashMap = new MyHashMap();
hashMap.put(1, 1);          
hashMap.put(2, 2);         
hashMap.get(1);            // returns 1
hashMap.get(3);            // returns -1 (not found)
hashMap.put(2, 1);          // update the existing value
hashMap.get(2);            // returns 1 
hashMap.remove(2);          // remove the mapping for 2
hashMap.get(2);            // returns -1 (not found) 

Note:

All keys and values will be in the range of [0, 1000000].
The number of operations will be in the range of [1, 10000].
Please do not use the built-in HashMap library.
*/


// Solution 0 (better in terms of memory)
class MyHashMap {
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        data.resize(size);
    }
    
    int get_hash(int n) {
        return n % size;
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        vector<pair<int, int>>& row = data[get_hash(key)];
        for (auto& i : row) {
            if (i.first == key) {
                i.second = value;
                return;
            }
        }
        row.push_back({key, value});
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        vector<pair<int, int>>& row = data[get_hash(key)];
        for (auto i : row) {
            if (i.first == key) {
                return i.second;
            }
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        vector<pair<int, int>>& row = data[get_hash(key)];
        for (auto iter = row.begin(); iter != row.end(); ++iter) {
            if (iter->first == key) {
                row.erase(iter);
                return;
            }
        }
    }
private:
    static const int size = 1001;
    vector<vector<pair<int, int>>> data;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */


// Solution 1
class MyHashMap {
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        memset(data_, -1, 1000001); // -1 -- means that we haven't value for the index
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        data_[key] = value;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        return data_[key];
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        data_[key] = -1;
    }
private:
    int data_[1000001];
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

// Solution 2
class MyHashMap {
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        data_.fill(-1); // -1 -- means that we haven't value for the index
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        data_[key] = value;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        return data_[key];
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        data_[key] = -1;
    }
private:
    array<int, 1000001> data_;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
