class Solution {
public:
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        vector<int> maxPathLen(n);
        vector<vector<int>> adj(n);
        
        for(int i = 1 ; i < n; i++) {
            adj[parent[i]].push_back(i);
        }
        
        solve(0, adj, s, maxPathLen);
        return ans;
    }
private:
    int ans = 1;
    void solve(int cur, vector<vector<int>>&adj, string &s, vector<int>&maxPathLen) {
        maxPathLen[cur] = 1;
        int mx1 = 0, mx2 = 0;
        for(auto nxt: adj[cur]) {
            solve(nxt, adj, s, maxPathLen);
        }
        for(auto nxt: adj[cur]) {
            if(s[nxt] != s[cur]) {
                maxPathLen[cur] = max(maxPathLen[cur], maxPathLen[nxt] + 1);
                if(maxPathLen[nxt] > mx1) {
                    mx2 = mx1;
                    mx1 = maxPathLen[nxt];
                }
                else if(maxPathLen[nxt] > mx2){
                    mx2 = maxPathLen[nxt];
                }
            }
        }
        ans = max(ans, max(maxPathLen[cur], mx1 + mx2 + 1));
    }
};
/*
3:51
*/