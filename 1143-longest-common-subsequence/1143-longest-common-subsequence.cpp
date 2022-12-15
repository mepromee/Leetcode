class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        
        vector<int>nxtRow(m+1), cur(m+1);
        
        int mx = 0;
        for(int i = n-1; i >= 0; i--) {
            for(int j = m-1; j>=0; j--) {
                mx = 0;
                if(text1[i] == text2[j]) mx = 1+nxtRow[j+1];
                mx = max(mx, max(nxtRow[j], cur[j+1]));
                cur[j] = mx;
            }
            nxtRow = cur;
        }
        return cur[0];
    }
};
/*
7:46

i,j   i,j+1
i+1,j

n,m


0000000
0000000
0000000
*/