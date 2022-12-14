class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>>vis(grid.size(), vector<int>(grid[0].size(),0));
        int islands = 0;
        
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == '1' && !vis[i][j]) {
                    dfs(i,j,grid,vis);
                    islands++;
                }
            }
        }
        return islands;
    }
private:
    void dfs(int i, int j, vector<vector<char>>&grid, vector<vector<int>>&vis) {
        if(grid[i][j] =='0' || vis[i][j]) return;

        vis[i][j] = 1;
        if(i-1 >=0) dfs(i-1,j,grid,vis);
        if(i+1 < grid.size()) dfs(i+1,j,grid,vis);
        if(j-1 >= 0) dfs(i,j-1,grid,vis);
        if(j+1 < grid[0].size()) dfs(i,j+1,grid,vis);
    }
};
/*
9:30
*/