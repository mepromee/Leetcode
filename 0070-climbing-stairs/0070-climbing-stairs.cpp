class Solution {
public:
    int climbStairs(int n) {
        vector<int> way(n+3,0);
        way[1] = 1;
        way[2] = 2;
        for(int i = 3; i <= n; i++) {
            way[i] = way[i-1] + way[i-2];
        }
        return way[n];
    }
};
/*
9:06
*/