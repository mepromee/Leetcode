class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        for(auto &word: words) {
            hashmap[word] = 1;
        }
        
        vector<int>dp;
        vector<string>ans;
        
        for(auto &word: words) {
            int n = word.size();
            dp.clear();
            dp.resize(n, -1);
            
            if(isConcatenated(0,word,dp)) {
                ans.push_back(word);
            }
        }
        
        return ans;
    }
private:
    unordered_map<string,int> hashmap;

    int isConcatenated(int i, string &word, vector<int>&dp) {
        //cout<<word<<" "<<i<<endl;
        if(i == word.size()) return 1;
        if(dp[i] != -1) return dp[i];
        
        string s;
        int isValid = 0;
        
        for(int j = i; j < word.size(); j++) {
            if(i == 0 && j == word.size()-1) break;
            s += word[j];
            //cout<<s<<endl;
            if(hashmap.find(s) != hashmap.end()) {
                //cout<<"s exists "<<s<<endl;
                // Exists in hashmap
                if(isConcatenated(j+1, word, dp)) {
                    isValid = 1;
                    break;
                }
            }
        }
        
        return dp[i] = isValid;
    }
};
/*
12:09
*/