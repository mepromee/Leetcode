class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n, vector<int>(m,0));
        bool connectsToBorder;
        int closedIslands = 0;
        
        for(int i = 0 ; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 0 && vis[i][j] == 0) {
                    connectsToBorder = false;
                    dfs(i,j, n, m, grid, vis, connectsToBorder);
                    if(!connectsToBorder) closedIslands++;
                }
            }
        }
        
        return closedIslands;
    }
private: 
    void dfs(int i , int j, int n, int m, vector<vector<int>>&grid, vector<vector<int>>&vis, bool &connectsToBorder) {
        vis[i][j] = 1;
        if(i == 0 || i == n-1 || j == 0 || j == m-1) connectsToBorder = true;
        if(isValidMove(i+1,j,n,m, grid, vis)) dfs(i+1, j, n, m, grid, vis, connectsToBorder);
        if(isValidMove(i-1,j,n,m, grid, vis)) dfs(i-1, j, n, m, grid, vis, connectsToBorder);
        if(isValidMove(i,j+1,n,m, grid, vis)) dfs(i, j+1, n, m, grid, vis, connectsToBorder);
        if(isValidMove(i,j-1,n,m, grid, vis)) dfs(i, j-1, n, m, grid, vis, connectsToBorder);
    }
    
    bool isValidMove(int i, int j, int n, int m,  vector<vector<int>>&grid, vector<vector<int>>&vis) {
        return i >= 0 && i < n && j >= 0 && j < m && grid[i][j] == 0 && vis[i][j] == 0;
    }
};
/*
6:03


01110
10101
10101
10001
01110

*/


