class MyHashSet {
public:
    MyHashSet() {
        hashSet.assign(1000001, 0);
    }
    
    void add(int key) {
        hashSet[key] = 1;
    }
    
    void remove(int key) {
        hashSet[key] = 0;
    }
    
    bool contains(int key) {
        return hashSet[key] == 1;
    }
private:
    vector<int> hashSet;
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */

/*
6:52
*/