class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size(), mx=1, a, b;
        double r;
        unordered_map<double, int> cnt;
        
        for(int i = 0; i < n; i++) {
            cnt.clear();
            for(int j = 0; j < n; j++) {
                if(i == j) continue;
                b = points[j][0] - points[i][0];
                a = points[j][1] - points[i][1];
                
                r = atan2(a,b);
                
                
                cnt[r]++;
                mx = max(mx, cnt[r]+1);
            }
        }
        return mx;
    }
};
/*
9:29


1,4 2,3 3,2 4,1

ax+by=c
x1-x2 / y1-y2 = -b/a
*/