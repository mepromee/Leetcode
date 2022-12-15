class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        
        return solve(n-1,m-1,text1,text2,dp);
    }
private:
    int solve(int i , int j, string &text1, string &text2, vector<vector<int>>&dp) {
        if(i < 0 || j < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        int len = 0;
        if(text1[i] == text2[j]) len = 1 + solve(i-1, j-1, text1, text2, dp);
        len = max(len, solve(i-1,j,text1,text2,dp));
        len = max(len, solve(i,j-1,text1,text2,dp));
        
        return dp[i][j] = len;
    }
};
/*
7:46
*/