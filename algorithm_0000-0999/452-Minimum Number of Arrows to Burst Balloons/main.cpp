class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        std::sort(points.begin(), points.end());

        int ret = 1;
        for (int coverL = points[0][0], coverR = points[0][1], cnt = 1, i = 1; i < points.size(); ++i) {
            int newCoverL = std::max(coverL, points[i][0]);
            int newCoverR = std::min(coverR, points[i][1]);
            if (newCoverR < newCoverL) { // not covered
                ret += cnt;
                coverL = points[i][0];
                coverR = points[i][1];
                cnt = 1;
            }
            else {
                coverL = newCoverL;
                coverR = newCoverR;
            }
        }

        return ret;
    }
};
