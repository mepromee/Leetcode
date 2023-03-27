class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> dp(n,vector<int>(m,-1));
        
        return getMinPathSum(0,0,grid,dp,n,m);
    }
private:
    int getMinPathSum(int i, int j, vector<vector<int>>&grid, vector<vector<int>>&dp, int n, int m) {
        if(i == n-1 && j == m-1) return grid[i][j];
        if(dp[i][j] != -1) return dp[i][j];
        
        int r1 = j+1 < m ? getMinPathSum(i, j+1, grid, dp, n, m) : INT_MAX;
        int r2 = i+1 < n ? getMinPathSum(i+1, j, grid, dp, n, m) : INT_MAX;
        
        return dp[i][j] = grid[i][j] + min(r1, r2);
    }
};
/*
2:19
*/