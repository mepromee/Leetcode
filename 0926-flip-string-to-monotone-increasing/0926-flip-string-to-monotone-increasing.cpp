class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.length(), ans = n;
        vector<int> oneInLeft(n), zeroInRight(n);
        
        for(int i = 0; i < n; i++) {
            if(s[i] == '1') oneInLeft[i]++;
            if(i > 0) oneInLeft[i] += oneInLeft[i-1];
        }
        
        for(int i = n-1; i >=0 ; i--) {
            if(s[i] == '0') zeroInRight[i]++;
            if(i < n-1) zeroInRight[i] += zeroInRight[i+1];
        }
        
        for(int i = 0; i < n-1; i++) {
            ans = min(ans, oneInLeft[i] + zeroInRight[i+1]);
        }
        
        ans = min(ans, oneInLeft[n-1]);
        ans = min(ans, zeroInRight[0]);
        
        return ans;
    }
};
/*
8:10

00001110010
*/