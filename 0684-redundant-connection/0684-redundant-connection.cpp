class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        par = vector<int>(n+1);
        for(int i = 0; i < n; i++) par[i] = i;
        for(auto edge: edges) {
            if(findPar(edge[0]) == findPar(edge[1])) {
                return edge;
            }
            uni(edge[0], edge[1]);
        }
        
        return {};
    }
private:
    vector<int>par;
    int findPar(int u) {
        if(u == par[u]) return u;
        return par[u] = findPar(par[u]);
    }
    void uni(int u, int v) {
        int par_u = findPar(u);
        int par_v = findPar(v);
        
        if(par_u < par_v) par[par_u] = par_v;   
        else if(par_v < par_u) par[par_v] = par_u;
    }
};
/*
amazon
fb

6:46
*/