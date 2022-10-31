class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int r, c, cur;
        bool invalid = false;
        
        for(int i = 0; i < m; i++) {
            cur = matrix[0][i];
            r = 0, c = i;
            while(r < n && c < m) {
                if(matrix[r][c] != cur) {
                    invalid = true;
                    break;
                }
                r++;
                c++;
            }
            if(invalid) break;
        }
        if(invalid) return false;
        for(int i = 0; i < n; i++) {
            cur = matrix[i][0];
            r = i, c = 0;
            while(r < n && c < m) {
                if(matrix[r][c] != cur) {
                    invalid = true;
                    break;
                }
                r++;
                c++;
            }
            if(invalid) break;
        }
        return !invalid;
        
    }
};
/*
9:32
*/