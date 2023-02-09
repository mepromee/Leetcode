class Solution {
public:
    int jump(vector<int>& nums) {
        set<int> st;
        int n = nums.size(), mn, j;
        vector<int>jumps(n);
        jumps[n-1] = 0;
        
        for(int i = n-2; i>=0; i--) {
            mn = i+nums[i] >= n-1 ? 1 : INT_MAX;
            while(!st.empty()) {
                set<int>::iterator itr = --st.end();
                j = *itr * (-1);
                if(j > i+nums[i] || min(n-1,j+nums[j]) > min(n-1,i+nums[i])) break;
                cout<<i<<" removed "<<j<<endl;
                st.erase(itr);
            }
            if(!st.empty()) {
                auto itr = st.lower_bound(-(i+nums[i]));
                if(itr != st.end()) {
                    j = *itr * (-1);
                    cout<<i<<" ("<<i+nums[i]<<") "<<j<<" "<<jumps[j]<<endl;
                    if(jumps[j] != INT_MAX)
                        mn = min(mn, jumps[j]+1);
                }
            }
            st.insert(-i);
            jumps[i] = mn;
        }
        
        return jumps[0];
    }
};
/*
9:09

-12 -10 -8 -6
*/