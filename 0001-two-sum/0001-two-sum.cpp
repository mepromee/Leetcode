class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,vector<int>> hashmap;
        vector<int>ans;
        int rem;
        
        for(int i = 0; i < nums.size(); i++) {
            if(hashmap.find(nums[i]) == hashmap.end()) {
                hashmap[nums[i]] = vector<int>();
            }
            hashmap[nums[i]].push_back(i);
        }
        
        for(int i = 0; i < nums.size(); i++) {
            rem = target - nums[i];
            if(rem == nums[i]) {
                if(hashmap.find(rem) != hashmap.end() && hashmap[rem].size() > 1) {
                    ans = vector<int> {hashmap[rem][0], hashmap[rem][1]};
                    break;
                }
            } 
            else if(hashmap.find(rem) != hashmap.end()) {
                ans = vector<int> {i, hashmap[rem][0]};
                break;
            }
        }
        
        return ans;
    }
};
/*
microsoft
8:51
*/