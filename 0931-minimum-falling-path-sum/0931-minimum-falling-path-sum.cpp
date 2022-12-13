class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans = INT_MAX;
        int n = matrix.size();
        vector<int> minSum = matrix[n-1];
        calc(matrix,minSum);
        for(int i = 0; i < n; i++) {
            ans = min(ans, minSum[i]);
        }
        return ans;
    }
private:
    void calc(vector<vector<int>>&matrix, vector<int>&minSum) {
        int n = matrix.size();
        vector<int>tmp;
        for(int i = n-2; i >= 0; i--) {
            tmp = matrix[i];
            for(int j = 0;j<n; j++) {
                int x = isValid(i+1,j-1,n) ? minSum[j-1] : INT_MAX;
                int y = isValid(i+1,j,n) ? minSum[j] : INT_MAX;
                int z = isValid(i+1,j+1,n)? minSum[j+1] : INT_MAX;
                
                tmp[j]+= min(x,min(y,z));
            }
            minSum = tmp;
        }
    }
    bool isValid(int i, int j, int n) {
        return i >= 0 && i < n && j >=0 && j < n;
    }
};
/*
6:54
*/