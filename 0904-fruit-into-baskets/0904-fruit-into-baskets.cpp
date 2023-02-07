class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int l = 0, r = 0, types = 0, mx = 0;
        vector<int> typecnt(n);
        
        while(r < n) {
            typecnt[fruits[r]]++;
            if(typecnt[fruits[r]] == 1) {
                // got new type
                types++;
                if(types == 3) {
                    // remove leftmost type
                    while(l < r) {
                        typecnt[fruits[l]]--;
                        l++;
                        if(typecnt[fruits[l-1]] == 0) {
                            types--;
                            break;
                        }
                    }
                }
            }
            mx = max(mx, r-l+1);
            r++;
        }
        
        return mx;
    }
};
/*
8:48
*/