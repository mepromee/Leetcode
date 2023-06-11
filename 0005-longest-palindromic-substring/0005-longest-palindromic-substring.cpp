class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size(), mxLen = 0, palindromeStartIndex = 0, arrIndex;
        palindromeStatus.resize(2, vector<int>(n,0));
        
        for(int len = 1; len <= n; len++) {
            for(int i = 0, j = i+len-1; i < n && j < n; i++, j++) {
                if(len % 2 == 0) arrIndex = 1;
                else arrIndex = 0;
                
                if(s[i] == s[j]) {
                    if(len <= 2 || palindromeStatus[arrIndex][i+1] == 1) {
                        palindromeStatus[arrIndex][i] = 1;
                        mxLen = len;
                        palindromeStartIndex = i;
                        continue;
                    }
                }
                palindromeStatus[arrIndex][i] = 0;
            }
        }
        
        string ans = s.substr(palindromeStartIndex, mxLen);
        
        return ans;
    }
    
private:
    vector<vector<int>> palindromeStatus;
    
};
/*
1:12
1:50
M
*/