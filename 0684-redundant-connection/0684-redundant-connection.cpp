class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<pair<int,int>>>adj(n+1);
        
        // states = 1 -> in active path, 
        // states = 2 -> in finished path
        vector<int>states(n+1);
        int i = 0;
        for(auto edge: edges) {
            //construct adjacency list
            adj[edge[0]].push_back({edge[1],i});
            adj[edge[1]].push_back({edge[0],i});
            i++;
        }
        
        dfs(edges[0][0], edges[0][0], adj, states);
        
        return edges[redundantEdgeId];
    }
private:
    int redundantEdgeId = -1;
    int cycleStart = -1;
    bool isCycle = false;
    bool finished = false;
    
    void dfs(int cur, int par, vector<vector<pair<int,int>>>adj, vector<int>&states) {
        // mark to be in active path
        states[cur] = 1;
        for(auto nxt: adj[cur]) {
            if(nxt.first == par) continue;
            // nxt one is in active path then it's in a cycle
            if(states[nxt.first] == 1) {
                redundantEdgeId = max(redundantEdgeId, nxt.second);
                cycleStart = nxt.first;
                isCycle = true;
                return;
            }
            dfs(nxt.first, cur, adj, states);
            if(finished) return;
            if(isCycle) {
                redundantEdgeId = max(redundantEdgeId, nxt.second);
                if(cur == cycleStart) finished = true;
                return;
            }
        }
        states[cur] = 2;
    }
};
/*
amazon
fb

3:07
*/