class Solution {
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        vector<pair<int,int>> vals2;
        vector<vector<int>> adj(n);
        int pre = -1, ans=0, cur;
        set<int> st;
        unordered_map<int,int>cnt;

        par.resize(n);
        vis.resize(n);
        
        for(int i = 0; i < n; i++) {
            par[i] = i;
            vals2.push_back({vals[i],i});
        }
        sort(vals2.begin(), vals2.end());
        
        for(auto &edge: edges) {
            if(vals[edge[0]] >= vals[edge[1]])
                adj[edge[0]].push_back(edge[1]);
            if(vals[edge[1]] >= vals[edge[0]])
                adj[edge[1]].push_back(edge[0]);
        }
        for(auto val: vals2) {
            cur = val.second;
            if(val.first != pre && pre != -1) {
                calcGoodPaths(ans, cnt, st);
            }
            if(!vis[cur]) {
                //cout<<"dfs "<<cur<<endl;
                dfs(cur, adj);
            }
            par[cur] = find_par(cur);
            //cout<<"par of "<< cur<<" "<<par[cur]<<endl;
            cnt[par[cur]]++;
            st.insert(par[cur]);
            pre = val.first;
        }
        calcGoodPaths(ans, cnt, st);
        return ans;
    }

private:
    vector<int> par, vis;
    
    int find_par(int u) {
        if(par[u] == u) return u;
        return par[u] = find_par(par[u]);
    }
    
    void connect(int u, int v) {
        int x = find_par(u);
        int y = find_par(v);
        
        if(x > y) swap(x,y);
        par[y] = x;
    }
    
    void dfs(int cur, vector<vector<int>>&adj) {
        vis[cur] = 1;
        for(auto &nxt: adj[cur]){
            connect(cur, nxt);
            if(!vis[nxt]) dfs(nxt, adj);
        }
    }
    
    void calcGoodPaths(int &ans, unordered_map<int,int>&cnt, set<int>&st) {
        int n;
        //cout<<"good ";
        for(auto &it: st) {
            //cout<<it<<" "<<cnt[it]<<endl;
            n = cnt[it];
            ans += (n * (n+1)) / 2;
        }
        
        cnt.clear();
        st.clear();
    }
};
/*
8:46
10:20
1 2 3 4
*/