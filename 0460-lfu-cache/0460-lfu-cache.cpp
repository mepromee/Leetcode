class LFUCache {
public:
    LFUCache(int capacity) {
        cap = capacity;
        minfreq = 0;
        cursize = 0;
    }
    
    int get(int key) {
        if(cache.count(key) == 0) {
            // not in cache;
            return -1;
        }
        
        int freq = cache[key].first;
        auto itr = cache[key].second;
        
        auto node = *itr;
        int val = node.second;
        
        update_usage(key, val);
        
        return val;
    }
    
    void put(int key, int value) {
        if(cap == 0) return;
        if(cache.count(key) == 0) {
            // add new
            if(cursize == cap) {
                // invalidate
                auto firstnode = *frequencies[minfreq].begin();
                cache.erase(firstnode.first);
                frequencies[minfreq].pop_front();
                cursize--;
            }
                
            frequencies[1].push_back({key,value});
            cache[key] = {1, --frequencies[1].end()};
            minfreq = 1;
            cursize++;
        }
        else {
            // already exist
            update_usage(key, value);
        }
    }
    
    
private:
    // key: key, value: {freq, iterator to node}
    unordered_map<int,pair<int,list<pair<int,int>>::iterator>> cache;
    // key: freq, value: linked list
    unordered_map<int, list<pair<int,int>>> frequencies;
    int cap, cursize;
    int minfreq;
    
    void update_usage(int key, int value) {
        int freq = cache[key].first;
        auto itr = cache[key].second;
        frequencies[freq].erase(itr);
        if(frequencies[freq].empty() && minfreq == freq) minfreq++;
        
        frequencies[freq+1].push_back({key,value});
        cache[key] = {freq+1,--frequencies[freq+1].end()};
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */