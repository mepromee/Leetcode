class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        priority_queue<pair<int,pair<int,int>>> pq;
        pq.push({0,{0,src}});
        int ans = -1;
        
        vector<vector<pair<int,int>>> adj(n);
        vector<vector<int>> cost(n, vector<int>(n,INT_MAX));
        cost[src][0] = 0;
        
        for(auto &flight: flights) {
            adj[flight[0]].push_back({flight[1], flight[2]});
        } 
        
        while(!pq.empty()) {
            auto t = pq.top();
            pq.pop();
            
            int curCost = -t.first;
            int curStops = -t.second.first;
            int curNode = t.second.second;
            
            if(curNode == dst) {
                ans = curCost;
                break;
            }
            
            for(auto &nxt: adj[curNode]) {
                int nxtNode = nxt.first;
                int nxtCost = curCost + nxt.second;
                
                if(nxtNode == src) continue;
                
                int stops = curNode == src ? curStops : curStops+1;
                if(cost[nxtNode][stops] > nxtCost && stops <= k) {
                    cost[nxtNode][stops] = nxtCost;
                    pq.push({-nxtCost, {-stops, nxtNode}});
                }
            }
        }
        
        return ans;
    }
};
/*
5:16


   0
   |  \
1  |59  \83
   |     2
        /  
       /  
      /
     /  
    3



*/