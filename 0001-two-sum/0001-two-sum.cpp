class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hashmap;
        vector<int>ans;
        int rem;
        
        for(int i = 0; i < nums.size(); i++) {
            rem = target - nums[i];
            if(hashmap.find(rem) != hashmap.end()) {
                ans = vector<int> {i, hashmap[rem]};
                break;
            }
            
            hashmap[nums[i]] = i;
        }
        
        return ans;
    }
};
/*
microsoft
8:51
*/