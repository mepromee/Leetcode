class SummaryRanges {
public:
    SummaryRanges() {
        intervalEdge.clear();
        par.clear();
        isAdded.clear();
        rank.clear();
        
        par.resize(N);
        rank.resize(N);
        intervalEdge.resize(N);
        isAdded.resize(N,0);
        
        for(int i = 0; i < N; i++) {
            par[i] = i;
            rank[i] = 1;
            intervalEdge[i] = {i,i};
        }
    }
    
    void addNum(int value) {
        isAdded[value] = 1;
        
        if(value-1 >= 0 && isAdded[value-1]) connect(value-1,value);
        if(value+1 < N && isAdded[value+1]) connect(value, value+1);
        else connect(value, value);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> vec;
        for(auto &interval: intervals) {
            vec.push_back({interval.first, interval.second});
        }
        
        return vec;
    }
    
private:
    set<pair<int,int>> intervals;
    vector<int> par, isAdded, rank;
    vector<pair<int,int>> intervalEdge;
    int N = 1e4 + 1;

    int find(int i) {
        if(par[i] == i )return i;
        return par[i] = find(par[i]);
    }
    void connect(int i, int j) {
        int p = find(i);
        int q = find(j);
        int p1 = p, p2 = q;
        
        if(p != q) {
            intervals.erase(intervalEdge[p]);
            intervals.erase(intervalEdge[q]);
            if(rank[p] > rank[q]) {
                par[q] = p;
                p1 = p, p2 = q;
            }
            else if(rank[q] > rank[p]) {
                par[p] = q;
                p1 = q, p2 = p;
            }
            else {
                par[p] = q;
                p1 = q, p2 = p;
                rank[q]++;
            }
        }
        
        intervalEdge[p1].first = min(min(intervalEdge[p1].first, intervalEdge[p2].first), min(i,j));
        intervalEdge[p1].second = max(max(intervalEdge[p1].second,intervalEdge[p2].second), max(i,j));
        
        intervals.insert(intervalEdge[p1]);
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
/*
1:49
*/