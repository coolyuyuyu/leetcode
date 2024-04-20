class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        int n = points.size();
        std::sort(points.begin(), points.end(), [](auto& p1, auto& p2){ return p1[0] < p2[0]; });

        int ret = 0;
        for (int lft = 0; lft < n;) {
            ++ret;

            int rht = lft;
            while (rht + 1 < n && points[lft][0] + w >= points[rht + 1][0]) {
                ++rht;
            }

            lft = rht + 1;
        }

        return ret;
    }
};
