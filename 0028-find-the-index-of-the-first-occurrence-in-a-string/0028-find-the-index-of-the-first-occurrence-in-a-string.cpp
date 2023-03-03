class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length();
        int m = needle.length(), ans = -1;
                
        for(int i = 0; i <= n-m; i++) {
            bool matched = true;
            for(int j = 0; j < m; j++) {
                if(haystack[i+j] != needle[j]) {
                    matched = false;
                    break;
                }
            }
            if(matched) {
                ans = i;
                break;
            }
        }
        
        return ans;
    }
};
/*
5:06
*/