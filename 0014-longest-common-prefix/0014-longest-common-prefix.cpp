class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        bool finish = false;
        
        for(int i = 0; ; i++) {
            for(auto str: strs) {
                if(str.size() < i+1 || str[i] != strs[0][i]) {
                    finish = true;
                    break;
                }
            }
            if(finish) break;
            ans += strs[0][i];
        }
        return ans;
    }
};