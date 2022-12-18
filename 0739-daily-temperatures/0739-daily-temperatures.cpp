class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> stk;
        vector<int> ans(temperatures.size());
        
        for(int i = temperatures.size()-1; i >=0; i--) {
            while(!stk.empty() && temperatures[stk.top()] <= temperatures[i]) {
                stk.pop();
            }
            if(stk.empty()) ans[i] = 0;
            else ans[i] = stk.top() - i;
            stk.push(i);
        }
        
        return ans;
    }
};
/*
7:44

x y z
*/