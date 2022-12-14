class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        int includingPre = nums[1], notIncludingPre = nums[0];
        int includingCur, notIncludingCur;
        int ans = max(includingPre, notIncludingPre);
        
        for(int i =2; i<n; i++) {
            notIncludingCur = max(notIncludingPre, includingPre);
            includingCur = nums[i] + notIncludingPre;
            
            ans = max(ans, max(notIncludingCur, includingCur));
            
            notIncludingPre = notIncludingCur;
            includingPre = includingCur;
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