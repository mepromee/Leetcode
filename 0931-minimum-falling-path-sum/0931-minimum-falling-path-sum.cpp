class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans = INT_MAX;
        int n = matrix.size();
        vector<vector<int>> minSum = matrix;
        calc(matrix,minSum);
        for(int i = 0; i < n; i++) {
            ans = min(ans, minSum[0][i]);
        }
        return ans;
    }
private:
    void calc(vector<vector<int>>&matrix, vector<vector<int>>&minSum) {
        int n = matrix.size();
        for(int i = n-2; i >= 0; i--) {
            for(int j = 0;j<n; j++) {
                int x = isValid(i+1,j-1,n) ? minSum[i+1][j-1] : INT_MAX;
                int y = isValid(i+1,j,n) ? minSum[i+1][j] : INT_MAX;
                int z = isValid(i+1,j+1,n)? minSum[i+1][j+1] : INT_MAX;
                
                minSum[i][j]+= min(x,min(y,z));
            }
        }
    }
    bool isValid(int i, int j, int n) {
        return i >= 0 && i < n && j >=0 && j < n;
    }
};
/*
6:54
*/