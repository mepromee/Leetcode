class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> vis(n+1,vector<int>(n+1,0));
        unordered_map<int,int> memo;
        int maxFibo = 0;
        
        for(int i = 0; i < n; i++) {
            memo[arr[i]] = i;
        }
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                if(vis[i][j]) continue;
                int firstNum = arr[i], secondNum = arr[j], thirdNum = arr[i]+arr[j];
                int fiboLen = 0;
                vis[i][j] = 1;
                while(memo.find(thirdNum) != memo.end()) {
                    if(fiboLen == 0) fiboLen = 2;
                    fiboLen++;

                    vis[memo[secondNum]][memo[thirdNum]] = 1;
                    firstNum = secondNum;
                    secondNum = thirdNum;
                    thirdNum = firstNum+secondNum;
                }
                maxFibo = max(maxFibo,fiboLen);
            }
        }
        return maxFibo;
    }
};
/*
apple

1 2 3 4 5 6 7 8
*/