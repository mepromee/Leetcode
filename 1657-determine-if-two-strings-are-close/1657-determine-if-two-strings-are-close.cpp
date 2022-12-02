class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        bool ans = true;
        
        if(n!=m) return false;
        
        vector<int> word1Cnt(26,0), word2Cnt(26,0), cnt1, cnt2;
        
        for(auto ch: word1) word1Cnt[ch-'a']++;
        for(auto ch: word2) word2Cnt[ch-'a']++;
        
        for(int i = 0; i < 26; i++) {
            if(word1Cnt[i] != word2Cnt[i] && (word1Cnt[i] == 0 || word2Cnt[i] == 0))
                ans = false;
            cnt1.push_back(word1Cnt[i]);
            cnt2.push_back(word2Cnt[i]);
        }
        
        sort(cnt1.begin(), cnt1.end());
        sort(cnt2.begin(), cnt2.end());
        
        for(int i = 0; i < 26; i++) {
            if(cnt1[i] != cnt2[i]) ans = false;
        }
        
        return ans;
    }
};
/*
8:36
*/