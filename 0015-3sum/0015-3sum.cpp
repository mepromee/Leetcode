class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        unordered_map<int,int> lastPos;
        int i = 0;
        vector<vector<int>> ans;
        set<pair<int,int>> st;
        
        sort(nums.begin(), nums.end());
        for(auto num: nums) {
            lastPos[num] = i++;
        }
        
        for(i = 0; i < nums.size(); i++) {
            for(int j = i+1; j < nums.size(); j++) {
                int k = lastPos[-nums[i]-nums[j]];
                if(k > j) {
                    
                    if(st.find({nums[i],nums[j]}) == st.end() && st.find({nums[i],nums[k]}) == st.end() && st.find({nums[j],nums[k]}) == st.end()) {
                        ans.push_back({nums[i],nums[j],nums[k]});
                        st.insert({nums[i],nums[j]});
                        st.insert({nums[i],nums[k]});
                        st.insert({nums[j],nums[k]});

                    }
                } 
            }
        }
        
        
        return ans;
    }
};
/*
11:48
*/