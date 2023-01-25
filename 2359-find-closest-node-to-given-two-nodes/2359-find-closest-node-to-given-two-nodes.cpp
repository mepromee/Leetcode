class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int>dist1(n,-1),dist2(n,-1);
        dist1[node1] = 0;
        dist2[node2] = 0;
        int ans = -1, mx = n+1;
        
        dfs(node1, edges, dist1);
        dfs(node2, edges, dist2);
        
        for(int i = 0; i < n; i++) {
            if(dist1[i] != -1 && dist2[i] != -1) {
                int mxDist = max(dist1[i], dist2[i]);
                if(mxDist < mx) {
                    ans = i;
                    mx = mxDist;
                }
            }
        }
        
        return ans;
    }
private:
    void dfs(int cur, vector<int>&edges, vector<int>&dist) {
        int nxt = edges[cur];
        if(nxt == -1 || dist[nxt] != -1) {
            // can't go further or visited already
            return;
        }
        dist[nxt] = dist[cur] + 1;
        dfs(nxt, edges, dist);
    }
};
/*
4:39



*/