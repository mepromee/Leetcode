class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        vector<int> cnt(10001);
        int m, half, rem = 0, tot = 0;
        
        for(auto pile: piles) {
            cnt[pile]++;
            tot += pile;
        }
        
        for(int i = 10000; i>=0; i--) {
            if(k == 0) break;
            if(cnt[i]) {
                m = min(cnt[i],k);
                half = i/2;
                
                rem += m * half;
                cnt[i-half] += m;
                
                k -= m;
            }
        }
        return tot-rem;
    }
};
/*
5:48
*/