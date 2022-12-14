class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        int rob1 = 0, rob2 = nums[0], cur;
        int ans = max(rob1, rob2);
        
        for(int i =1; i<n; i++) {
            cur = max(rob1 + nums[i], rob2);
            rob1 = rob2;
            rob2 = cur;
            ans = max(ans, cur);
        }
        return ans;
    }
};
/*
6:40

1 2 3 4 5  6 7 8 9 
0 0 0

2 1 1 2
2 1 3 


*/