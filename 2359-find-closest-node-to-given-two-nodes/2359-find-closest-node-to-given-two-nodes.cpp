class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {        
        int ans = bfs(node1, node2, edges);
        
        return ans;
    }
private:
    int bfs(int node1, int node2, vector<int>&edges) {
        int n = edges.size(), mx = n+1;
        pair<int,int> ans = {-1, n+1};
        vector<vector<int>> vis(n, vector<int>(2,-1));
        
        queue<pair<int,int>>q;
        q.push({node1,0});
        q.push({node2,1});
        
        vis[node1][0] = 0;
        vis[node2][1] = 0;
        
        while(!q.empty()) {
            auto cur = q.front();
            q.pop();
            
            int curNode = cur.first;
            int curStatus = cur.second; // 0 or 1
            
            if(vis[curNode][1-curStatus] != -1) {
                int curMx = max(vis[curNode][curStatus],vis[curNode][1-curStatus]);
                if(mx >= curMx) {
                    if(mx == curMx) {
                        ans = {min(ans.first, curNode), curMx};
                    }
                    else {
                        ans = {curNode, curMx};
                    } 
                    mx = curMx;
                }
            }
            
            int nxt = edges[curNode];
            if(nxt == -1 || vis[nxt][curStatus] != -1) continue;
            
            vis[nxt][curStatus] = vis[curNode][curStatus] + 1;
            q.push({nxt,curStatus});
        }
        
        return ans.first;
    }
};
/*
4:39



*/