class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.length();
        string ans;
        
        for(int i = 0; i < 26; i++) par.push_back(i);
        
        for(int i = 0; i<n; i++) {
            connect(s1[i], s2[i]);
        }
        
        for(auto c: baseStr) {
            ans += find_par(c-'a') + 'a';
        }
        
        return ans;
    }
private:
    vector<int>par;
    int find_par(int a) {
        if(par[a] == a) return a;
        return par[a] = find_par(par[a]);
    }
    void connect(char a, char b) {
        int p1 = find_par(a-'a');
        int p2 = find_par(b-'a');
        
        if(p1 > p2) swap(p1,p2);
        par[p2] = p1;
    }
};
/*
6:54
*/