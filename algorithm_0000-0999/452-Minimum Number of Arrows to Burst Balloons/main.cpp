class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        std::sort(points.begin(), points.end());

        int ret = 1;
        for (int coverR = points[0][1], i = 1; i < points.size(); ++i) {
            if (coverR < points[i][0]) { // not covered
                ++ret;
                coverR = points[i][1];
            }
            else {
                coverR = std::min(coverR, points[i][1]);
            }
        }

        return ret;
    }
};
