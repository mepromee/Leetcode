class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n+1, vector<int>(2,-1));
        
        return solve(0, 0, prices, dp);
    }
private:
    // 0: buy
    // 1: sell
    
    int solve(int i, int status, vector<int>&prices, vector<vector<int>>&dp) {
        if(i >= prices.size()) return 0;
        if(dp[i][status] != -1) return dp[i][status];
        
        int nxt_i = status == 1 ? i+2 : i+1;
        int trans = status == 1 ? prices[i] : -prices[i];
        
        int res = solve(nxt_i, 1-status, prices, dp) + trans;
        
        res = max(res, solve(i+1, status, prices, dp));
        
        return dp[i][status] = res;
    }
};
/*
8:15
*/