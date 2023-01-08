class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        vector<int> gas_left(n+1), end_st(n+1);
        int cur, cur_gas;
        bool start, ans;
        
        for(int i = 0; i <n ;i++) end_st[i] = i;
        
        for(int i = n-1; i >= 0; i--) {
            cur = i;
            start = true;
            ans = false;
            cur_gas = 0;
            
            while(true) {
                if(cur == i && !start) {
                    ans = true;
                    break;
                }
                start = false;
                if(end_st[cur] != cur) {
                    cur = end_st[cur];
                    cur_gas += gas_left[cur];
                    continue;
                }
                if(cur_gas + gas[cur] - cost[cur] >= 0) {
                    cur_gas += gas[cur] - cost[cur];
                    cur = (cur + 1) % n;
                }
                else break;
            }
            if(ans) return i;
            gas_left[cur] = cur_gas;
            end_st[i] = cur;
        }
        
        return -1;
    }
};
/*
5:37

pre j   k

    i . . . . k
*/