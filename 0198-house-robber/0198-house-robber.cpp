class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1,-1);
        return solve(0, nums, dp);
    }
private:
    int solve(int i, vector<int>&nums, vector<int>&dp) {
        if(i >= nums.size()) return 0;
        if(dp[i] != -1) return dp[i];
        
        return dp[i] = max(nums[i]+solve(i+2,nums,dp), solve(i+1,nums,dp));
    }
};
/*
6:40

1 2 3 4 5  6 7 8 9 


*/