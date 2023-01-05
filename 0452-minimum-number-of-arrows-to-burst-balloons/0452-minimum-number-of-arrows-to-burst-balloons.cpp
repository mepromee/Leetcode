class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int s = points[0][0], e = points[0][1], arrows = 0;
        
        for(auto point: points) {
            if(point[0] >= s && point[0] <= e) {
                // overlaps
                s = point[0];
                e = min(point[1], e);
            }
            else {
                // not overlap
                arrows++;
                s = point[0];
                e = point[1];
            }
        }
        
        arrows++;
        
        return arrows;
    }
};
/*
6:39
*/