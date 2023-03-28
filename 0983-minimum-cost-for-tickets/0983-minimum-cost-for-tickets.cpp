class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int>dp(n,-1);
        return getMinCostTickets(0,days,costs,dp,n);
    }
    
private:
    int getMinCostTickets(int i, vector<int>&days, vector<int>&costs, vector<int>&dp, int n) {
        if(i == n) return 0;
        if(dp[i]!= -1) return dp[i];
        
        int minCost = INT_MAX;
        // 1 day pass
        minCost = costs[0] + getMinCostTickets(i+1, days, costs, dp, n);
        
        // 7 days pass
        auto nxtItr = upper_bound(days.begin(), days.end(), days[i]+6) - days.begin();
        minCost = min(minCost, costs[1] + getMinCostTickets(nxtItr, days, costs, dp ,n));
        
        // 30 days pass
        nxtItr = upper_bound(days.begin(), days.end(), days[i]+29) - days.begin();
        minCost = min(minCost, costs[2] + getMinCostTickets(nxtItr, days, costs, dp ,n));
        
        return dp[i] = minCost;
    }
};
/*
1:16
*/