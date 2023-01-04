class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> cnt;
        bool invalid = false;
        int ans = 0, rem, res ;
        
        for(auto task: tasks) {
            cnt[task]++;
        }
        for(auto x: cnt) {
            rem = x.second % 3;
            res = x.second / 3;
            
            if(rem == 0 || rem == 2) {
                ans += res + (rem == 2 ? 1 : 0);
            }
            else {
                // rem == 1
                if(res > 0) ans += res - 1 + 2;
                else invalid = true;
            }
        }
        
        return invalid ? -1 : ans;
    }
};
/*
11:36

x-3 >= 2
*/