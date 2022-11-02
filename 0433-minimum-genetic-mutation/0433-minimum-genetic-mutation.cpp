class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        int n = bank.size();
        vector<vector<int>> adj(n, vector<int>(n,-1));
        vector<int> dist(n,-1);
        int ans = INT_MAX, mismatch = 0, endId = -1;
        
        if(start == end) return 0;
        for(int i = 0; i < bank.size(); i++) {
            if(bank[i] == end) {
                endId = i;
            }
            for(int j = i+1; j < bank.size(); j++) {
                mismatch = 0;
                for(int k = 0; k < bank[i].size(); k++) {
                    if(bank[i][k] != bank[j][k]) mismatch++;
                }
                if(mismatch == 1) {
                    adj[i][j] = mismatch;
                    adj[j][i] = mismatch;
                }
            }
        }
        
        if(endId == -1) return -1;
        
        bfs(endId, adj, dist);
        
        for(int i = 0; i < bank.size(); i++) {
            mismatch = 0;
            for(int k = 0; k < bank[i].size(); k++) {
                if(bank[i][k] != start[k]) mismatch++;
            }
            if(mismatch == 1 && dist[i] != -1)
                ans = min(ans, mismatch + dist[i]);
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
    
private:
    void bfs(int s, vector<vector<int>> &adj, vector<int> &dist) {
        queue<int> q;
        q.push(s);
        dist[s] = 0;
        int cur;
        while(!q.empty()) {
            cur = q.front();
            q.pop();
            
            for(int i = 0; i < adj[0].size(); i++) {
                if(cur != i && adj[cur][i] == 1 && dist[i] == -1) {
                    dist[i] = dist[cur] + 1;
                    q.push(i);
                } 
            }
        }
    }
};
/*
9:40
*/