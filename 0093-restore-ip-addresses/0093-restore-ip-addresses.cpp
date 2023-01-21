class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        int n = s.length();
        vector<string> ans;
        
        for(auto ch: s) {
            if(ch >= '0' && ch <= '9') continue;
            return ans;
        }
        
        for(int j = 1; j < min(4,n); j++) {
                for(int k = j+1; k < min(j+4,n); k++) {
                    for(int l = k+1; l < min(k+4,n); l++) {
                        process(s, 0, j, k, l, ans);
                    }
                }
            }
        return ans;
    }
private:
    void process(string &s, int i, int j, int k, int l, vector<string>&ans) {
        int n = s.length();
        
        if(n-l > 4) return;
        string sa = s.substr(i, j-i);
        string sb = s.substr(j, k-j);
        string sc = s.substr(k, l-k);
        string sd = s.substr(l, n-l);
        int a = stoi(sa);
        int b = stoi(sb);
        int c = stoi(sc);
        int d = stoi(sd);
        if(s[i] == '0' && (a > 0 || sa.length() > 1)) return;
        if(s[j] == '0' && (b > 0 || sb.length() > 1)) return;
        if(s[k] == '0' && (c > 0 || sc.length() > 1)) return;
        if(s[l] == '0' && (d > 0 || sd.length() > 1)) return;
        
        int mx = max(a,max(b,max(c,d)));
        if(mx > 255) return;
        
        string ip = sa + '.' + sb + '.' + sc + '.' + sd;
        ans.push_back(ip);
        return;
    }
};
/*
8:25
*/