class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int,vector<int>> hashmap;
        unordered_map<int,bool>visited;
        queue<int>q;
        int jumps = 0;

        for(int i = 0 ; i < arr.size(); i++) {
            hashmap[arr[i]].push_back(i);
        }
        
        q.push(0);
        visited[0] = true;
        while(!q.empty()) {
            for(int i = q.size(); i > 0; i--) {
                int cur = q.front();
                q.pop();
                if(cur == arr.size()-1) return jumps;
                vector<int> &nxtnodes = hashmap[arr[cur]];
                nxtnodes.push_back(cur-1);
                nxtnodes.push_back(cur+1);
                
                for(auto &nxt: nxtnodes) {
                    if(nxt >= 0 && nxt < arr.size() && !visited[nxt]) {
                        visited[nxt] = true;
                        q.push(nxt);
                    }
                }
                
                nxtnodes.clear();
            }
            jumps++;
        }
        return jumps;
    }
};
/*

*/