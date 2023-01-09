class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size(), mx=1, cnt, a, b, ta, tb;
        double r, rr;
        
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                b = points[i][0] - points[j][0];
                a = points[i][1] - points[j][1];
                
                r = -(b * (1.0))/a;
                cnt = 2;
                for(int k = 0; k < n; k++) {
                    if(k == i || k == j) continue;
                    tb = points[i][0] - points[k][0];
                    ta = points[i][1] - points[k][1];
                    
                    rr = -(tb * 1.0) / ta;
                    if(rr == r) {
                        cnt++;
                    }
                }
                
                mx = max(mx, cnt);
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