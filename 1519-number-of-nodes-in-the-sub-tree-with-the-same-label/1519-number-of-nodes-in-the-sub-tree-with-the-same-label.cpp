class Solution {
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> adj(n+1);
        vector<int> ans(n); 

        for(auto edge: edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        dfs(0, 0, adj, labels, ans);
        
        return ans;
    }
private:
    vector<int> dfs(int cur, int par, vector<vector<int>>&adj, string &labels, vector<int>&ans) {
        vector<int> cnt(26), tmp(26);
        for(auto nxt: adj[cur]) {
            if(nxt != par) {
                tmp = dfs(nxt, cur, adj, labels, ans);
                merge(cnt, tmp);
            }
        }
        cnt[labels[cur]-'a']++;
        ans[cur] = cnt[labels[cur]-'a'];
        return cnt;
    }

    void merge(vector<int>& vec1, vector<int>& vec2) {
        for(int i = 0; i < vec1.size(); i++) {
            vec1[i] += vec2[i];
        }
    }
};
/*
3:43
*/