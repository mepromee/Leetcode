class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> hashmap;
        int ans = 0;
        for(int i = 0, l = 0; i < s.length(); i++) {
            if(hashmap.find(s[i]) != hashmap.end() && hashmap[s[i]] >= l) {
                l = hashmap[s[i]] + 1;
            }
            hashmap[s[i]] = i;
            ans = max(ans, i-l+1);
        }
        
        return ans;
    }
};
/*
microsoft
4:41
*/