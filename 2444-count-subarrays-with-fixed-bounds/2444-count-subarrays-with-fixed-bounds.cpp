class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int l = INT_MAX, r = INT_MIN;
        long long ans = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] >= minK && nums[i] <= maxK) {
                l = min(l,i);
                r = max(r,i);
            }
            else {
                ans += calc(l,r,nums,minK,maxK);
                l = INT_MAX;
                r = INT_MIN;
            }
        }
        ans += calc(l,r,nums,minK,maxK);
        return ans;
    }
private:
    long long calc(int l, int r, vector<int>&nums, int& minK, int &maxK) {
        if(l > r) return 0;
        int minKCnt = 0, maxKCnt = 0;
        long long res = 0;
        for(int i = l,j=l; i <= r; i++) {
            if(i > j) j = i;
            for(;j<=r;j++) {
                if(minKCnt>0&&maxKCnt>0) {
                    break;
                }                
                if(nums[j] == minK) minKCnt++;
                if(nums[j] == maxK) maxKCnt++;
            }
            if(minKCnt>0&&maxKCnt>0) {
                res += r-j+2;
            }            
            if(nums[i]==minK) minKCnt--;
            if(nums[i]==maxK) maxKCnt--;
        }
        return res;
    }
};
/*
9:39
*/