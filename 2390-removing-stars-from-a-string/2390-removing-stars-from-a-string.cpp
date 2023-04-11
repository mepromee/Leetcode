class Solution {
public:
    string removeStars(string s) {
        string ans;
        for(auto &ch: s) { 
            if(ch == '*' && ans.size() > 0) {
                ans.pop_back();
            }
            else if(ch != '*') {
                ans += ch;
            }
        }
        
        return ans;
    }
};
/*
1:43
*/