class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size(), len, maxLen = 0, startPos = 0;
        
        for(int i = 0; i < n; i++) {
            expandFromCenter(i,i, s, maxLen, startPos);
        }
        
        for(int i = 0; i < n-1; i++) {
            expandFromCenter(i,i+1, s, maxLen, startPos);
        }
        
        return s.substr(startPos, maxLen);
    }
    
private:
    void expandFromCenter(int i, int j, string &s, int &maxLen, int &startPos) {
        int len;
        
        for(int l = i, r = j; l >= 0 && r < s.size(); l--, r++) {
            if(s[l] == s[r]) {
                len  = r - l + 1;
                if(len >= maxLen) {
                    maxLen = len;
                    startPos = l;
                }
            }
            else break;
        }
    }
};
/*
1:12
1:50
2:49
M
*/