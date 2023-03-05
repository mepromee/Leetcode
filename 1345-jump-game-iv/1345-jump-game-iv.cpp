class Solution {
public:
    int minJumps(vector<int>& arr) {
        if(arr.size() == 1) return 0;
        
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
            jumps++;
            for(int i = q.size(); i > 0; i--) {
                int cur = q.front();
                q.pop();
                vector<int> &nxtnodes = hashmap[arr[cur]];
                nxtnodes.push_back(cur-1);
                nxtnodes.push_back(cur+1);
                
                for(auto &nxt: nxtnodes) {
                    if(nxt >= 0 && nxt < arr.size() && !visited[nxt]) {
                        visited[nxt] = true;
                        q.push(nxt);
                        if(nxt == arr.size()-1) return jumps;
                    }
                }
                
                nxtnodes.clear();
            }
        }
        return jumps;
    }
};
/*

*/