class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        
        vector<vector<int>> adj(n+1);
        for(auto edge: edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        dfs(0, 0, adj, hasApple);
        return time;
    }
private:
    int time = 0;
    int dfs(int cur, int par, vector<vector<int>>&adj, vector<bool>&hasApple) {
        int res = 0;
        if(hasApple[cur]) {
            res++;
        }
        for(auto nxt: adj[cur]) {
            if(nxt != par) {
                res += dfs(nxt, cur, adj, hasApple);
            }
        }
        if(res > 0 && cur > 0) time += 2;
        
        return res;
    }
};
/*
10:30
*/