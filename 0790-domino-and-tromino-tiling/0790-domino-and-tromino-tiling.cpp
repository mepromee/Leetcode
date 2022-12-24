class Solution {
public:
    int numTilings(int n) {
        vector<vector<int>> dp(n+1, vector<int>(2,-1));
        return solve(n,0,dp);
    }
private:
    int M = 1e9 + 7;
    int solve(int i, int filledCnt, vector<vector<int>>&dp) {
        if(i == 0) return 1;
        if(dp[i][filledCnt] != -1) return dp[i][filledCnt];
        
        long long int res = 0;
        
        if(filledCnt == 0) {
            // both blank
            
            if(i-2 >= 0) {
                // 2 horizontal domino
                res += solve(i-2, 0,dp);
                if(res > M)
                    res %= M;
                // 1 tromino
                res += solve(i-1, 1,dp) * 1ll * 2;
                if(res > M)
                    res %= M;
            }
            // 1 vertical domino
            res += solve(i-1,0,dp);
            if(res > M)
                res %= M;
            
        }
        else {
            // one is filled
            
            if(i-2 >= 0) {
                // 1 tromino
                res += solve(i-2,0,dp);
                if(res > M)
                    res %= M;           
                // 1 horizontal domino
                res += solve(i-1,1,dp);
                if(res > M)
                    res %= M;            
            
            }
        }
        return dp[i][filledCnt] = res;
    }
};
/*
6:07
*/