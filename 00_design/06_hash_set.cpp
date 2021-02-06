/*

https://leetcode.com/problems/design-hashset/

Design a HashSet without using any built-in hash table libraries.

Implement MyHashSet class:

void add(key) Inserts the value key into the HashSet.
bool contains(key) Returns whether the value key exists in the HashSet or not.
void remove(key) Removes the value key in the HashSet. If key does not exist in the HashSet, do nothing.
 

Example 1:

Input
["MyHashSet", "add", "add", "contains", "contains", "add", "contains", "remove", "contains"]
[[], [1], [2], [1], [3], [2], [2], [2], [2]]
Output
[null, null, null, true, false, null, true, null, false]

Explanation
MyHashSet myHashSet = new MyHashSet();
myHashSet.add(1);      // set = [1]
myHashSet.add(2);      // set = [1, 2]
myHashSet.contains(1); // return True
myHashSet.contains(3); // return False, (not found)
myHashSet.add(2);      // set = [1, 2]
myHashSet.contains(2); // return True
myHashSet.remove(2);   // set = [1]
myHashSet.contains(2); // return False, (already removed)
 

Constraints:

0 <= key <= 106
At most 104 calls will be made to add, remove, and contains.

*/


class MyHashSet {
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        buckets_.assign(maxBuckets_, vector<int>{});
    }
    
    void add(int key) {
        int hash = get_hash(key);
        auto iter = find(buckets_[hash].begin(), buckets_[hash].end(), key);
        if (iter == buckets_[hash].end()) {
            buckets_[hash].push_back(key);
        }
    }
    
    void remove(int key) {
        int hash = get_hash(key);
        auto iter = find(buckets_[hash].begin(), buckets_[hash].end(), key);
        if (iter != buckets_[hash].end()) {
            buckets_[hash].erase(iter);
        }
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int hash = get_hash(key);
        auto iter = find(buckets_[hash].begin(), buckets_[hash].end(), key);
        return iter != buckets_[hash].end();
    }
private:
    int get_hash(int key){
        return key % maxBuckets_;
    }
private:
    const int maxBuckets_ = 1000;
    vector<vector<int>> buckets_;
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
