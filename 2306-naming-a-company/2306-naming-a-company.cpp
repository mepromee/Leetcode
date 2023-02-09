class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        unordered_set<string>init_grp[26];
        long long int ans = 0;
        
        for(string idea: ideas) {
            init_grp[idea[0]-'a'].insert(idea.substr(1));
        }
        for(int i = 0 ; i < 26; i++) {
            for(int j = i+1; j < 26; j++) {
                int mutual = 0;
                for(auto idea: init_grp[i]) {
                    if(init_grp[j].count(idea)) mutual++;
                }
                ans += 2LL * (init_grp[i].size() - mutual) * (init_grp[j].size() - mutual);
            }
        }
        return ans;
    }
};
/*
10:46

cut out
*/