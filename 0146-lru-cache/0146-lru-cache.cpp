class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(cache.find(key) == cache.end()) return -1;
        auto itr = cache[key];
        int val = itr->second;
        
        nodelist.erase(itr);
        insert(key, val);
        
        return val;
    }
    
    void put(int key, int value) {
        if(cache.find(key) == cache.end()) {
            if(cap == cache.size()) {
                cache.erase(nodelist.front().first);
                nodelist.pop_front();
            }
            nodelist.push_back({key,value});
            cache[key] = --nodelist.end();
        }
        else {
            cache[key]->second = value;
            int v = get(key);
        }
    }
    
private:
    int cap;
    unordered_map<int,list<pair<int,int>>::iterator> cache;
    list<pair<int,int>> nodelist;
    
    void insert(int key, int value) {
        nodelist.push_back({key,value});
        cache[key] = --nodelist.end();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
/*
7:06
*/