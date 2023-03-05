class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int minPos = -1, maxPos = -1, lastOutNumPos = -1;
        long long ans = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] < minK || nums[i] > maxK) {
                lastOutNumPos = i;
                minPos = -1;
                maxPos = -1;
            }
            else {
                if(nums[i] == minK) minPos = i;
                if(nums[i] == maxK) maxPos = i;
                ans += max(0,min(minPos, maxPos) - lastOutNumPos);
            }
        }
        return ans;
    }
};
/*
*/