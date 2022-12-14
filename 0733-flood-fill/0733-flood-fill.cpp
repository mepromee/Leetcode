class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        dfs(sr, sc, image, image[sr][sc], color);
        return image;
    }
private:
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,-1,0,1};

    void dfs(int i, int j, vector<vector<int>>&image, int curColor, int &newColor) {
        if(image[i][j] == newColor) return;
        image[i][j] = newColor;
        for(int k = 0; k < 4; k++) {
            int x = i+dx[k];
            int y = j+dy[k];
            if(isValid(x,y,image,curColor)) {
                dfs(x,y,image,curColor,newColor);
            }
        }
    }
    bool isValid(int i, int j, vector<vector<int>>&image, int color) {
        return i>=0 && i < image.size() && j>=0 && j < image[0].size() && image[i][j] == color;
    }
};
/*
8:50
*/