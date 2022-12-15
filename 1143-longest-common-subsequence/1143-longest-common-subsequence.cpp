class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        
        dp[n][m] = 0;
        for(int i = n-1; i >= 0; i--) {
            for(int j = m-1; j>=0; j--) {
                if(text1[i] == text2[j]) dp[i][j] = max(dp[i][j], 1+dp[i+1][j+1]);
                dp[i][j] = max(dp[i][j], max(dp[i+1][j], dp[i][j+1]));
            }
        }
        return dp[0][0];
    }
};
/*
7:46

i,j   i,j+1
i+1,j

n,m
*/