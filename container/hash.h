/******************************************************************************* 
 * @Author       : tuhuilin
 * @Date         : 2022-10-20 16:20:17
 * @Description  : 哈希的一些实现方法
 * @Copyright (c) 2022 zyyt, All Rights Reserved. 
 *******************************************************************************/
//
#define MAX_LEN 100000          // the amount of buckets
class MyHashSet {
private:
    vector<int> set[MAX_LEN];   // hash set implemented by array
    
    /** Returns the corresponding bucket index. */
    int getIndex(int key) {
        return key % MAX_LEN;
    }
    
    /** Search the key in a specific bucket. Returns -1 if the key does not existed. */
    int getPos(int key, int index) {
        // Each bucket contains a list. Iterate all the elements in the bucket to find the target key.
        for (int i = 0; i < set[index].size(); ++i) {
            if (set[index][i] == key) {
                return i;
            }
        }
        return -1;
    }
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        
    }
    
    void add(int key) {
        int index = getIndex(key);
        int pos = getPos(key, index);
        if (pos < 0) {
            // Add new key if key does not exist.
            set[index].push_back(key);
        }
    }
    
    void remove(int key) {
        int index = getIndex(key);
        int pos = getPos(key, index);
        if (pos >= 0) {
            // Remove the key if key exists.
            set[index].erase(set[index].begin() + pos);
        }
    }
    
    /** Returns true if this set did not already contain the specified element */
    bool contains(int key) {
        int index = getIndex(key);
        int pos = getPos(key, index);
        return pos >= 0;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet obj = new MyHashSet();
 * obj.add(key);
 * obj.remove(key);
 * bool param_3 = obj.contains(key);
 */