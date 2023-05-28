class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        vector<int>new_cuts = cuts;
        new_cuts.push_back(0);
        new_cuts.push_back(n);
        
        sort(new_cuts.begin(), new_cuts.end());
        
        int m = new_cuts.size();
        vector<vector<int>> dp(m,vector<int>(m,-1));
        
        return calcCost(0,m-1,new_cuts,dp);
    }
    
private:
    int calcCost(int l, int r, vector<int>&cuts, vector<vector<int>>&dp) {
        if(r-l == 1) return 0;
        if(dp[l][r] != -1) return dp[l][r];
        
        int mnCost = INT_MAX, cost;
        
        for(int i = l+1; i < r; i++) {
            cost = calcCost(l,i, cuts, dp) + calcCost(i, r, cuts, dp) + cuts[r] - cuts[l];
            
            mnCost = min(mnCost, cost);
        }
        
        return dp[l][r] = mnCost;
    }
};
/*
*/