class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        memset(dp,-1,sizeof(dp));
        vector<int> prefixSum;
        int sum = 0;
        for(int i = 0; i < stones.size(); i++) {
            prefixSum.push_back(stones[i]+sum);
            sum += stones[i];
        }

        return solve(0,stones.size()-1,0,prefixSum);
    }
private:
    int dp[1001][1001][2];
    int solve(int l, int r, int curTurn, vector<int>&prefixSum) {
        if(l > r) return 0;
        if(dp[l][r][curTurn] != -1) return dp[l][r][curTurn];

        int prefixSum1 = getSubArrSum(l,r-1,prefixSum);
        int prefixSum2 = getSubArrSum(l+1,r,prefixSum);
        int r1 = solve(l,r-1,1-curTurn,prefixSum);
        int r2 = solve(l+1,r,1-curTurn,prefixSum);
        dp[l][r][0] = max(prefixSum1+r1,prefixSum2+r2); // Alice
        dp[l][r][1] = min(-prefixSum1+r1,-prefixSum2+r2); // Bob
        
        return dp[l][r][curTurn];
    }

    int getSubArrSum(int l, int r, vector<int>&prefixSum) {
        if(l>r) return 0;
        if(l == 0) return prefixSum[r];
        else return prefixSum[r] - prefixSum[l-1];
    }
};