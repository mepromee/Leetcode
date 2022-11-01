class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int>ans;
        for(int i = 0; i < m; i++) {
            ans.push_back(getDestCol(0,i,1, grid));
        }
        return ans;
    }
private:
    int getDestCol(int x, int y, int z, vector<vector<int>> &grid) {
        bool hasReachedEnd = false;
        int n = grid.size();
        int m = grid[0].size();
        while(true) {
            if(x == n-1 && z == -1) {
                hasReachedEnd = true;
                break;
            }
            if(grid[x][y] == 1 && z == 1) {
                if(y+1 == m || grid[x][y+1] == -1) break;
                y++;
                z = -1;
            }
            else if(grid[x][y] == 1 && z == -1) {
                x++;
                z = 1;
            }
            else if(grid[x][y] == -1 && z == 1) {
                if(y-1 == -1 || grid[x][y-1] == 1) break;
                y--;
                z = -1;
            }
            else if(grid[x][y] == -1 && z == -1) {
                x++;
                z = 1;
            }
        }
        
        return hasReachedEnd ? y : -1;
        
    }
};
/*
5:01

12:06

grid[x][y] z
 1         1
 1         -1
 -1        1
 -1        -1
*/