class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> len(n+1,vector<int>(n+1,0));
        unordered_map<int,int> memo;
        int ans = 0;
        
        for(int i = 0; i < n; i++) {
            memo[arr[i]] = i;
        }
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                int z = arr[i]+arr[j];
                if(memo.find(z) != memo.end()) {
                    int k = memo[z];
                    len[j][k] = len[i][j] + 1;
                    ans = max(ans, len[j][k] + 2);
                }
            }
        }
        return ans;
    }
};
/*
apple

1 2 3 4 5 6 7 8
*/