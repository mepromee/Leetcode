class SnapshotArray {
public:
    SnapshotArray(int length) {
        array.clear();
        array.resize(length);
        curSnapId = 0;
    }
    
    void set(int index, int val) {
        auto &snapIdValuePair = array[index];
        snapIdValuePair.push_back({curSnapId, val});
        
    }
    
    int snap() {
        curSnapId++;
        return curSnapId-1;
    }
    
    int get(int index, int snap_id) {
        auto &snapIdValuePair = array[index];
        auto it = upper_bound(snapIdValuePair.begin(), snapIdValuePair.end(), make_pair(snap_id, INT_MAX));
        if(it == snapIdValuePair.begin()) return 0;
        it--;
        return it->second;
    }
private:
    vector<vector<pair<int,int>>> array;
    int curSnapId;
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 
 8:51
 
 0 0 5 0 6 0
 
 0 -> 
 1 -> 
 2 ->         (4,6)
 3 -> (2,5)
 4 -> (2,7),  (4,1)
 
0  (0,5) (1,6)
1  
2
3

 */
