class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        std::sort(points.begin(), points.end(), [](const auto& p1, const auto& p2){ return p1[1] < p2[1]; });

        int ret = 1;
        for (int i = 1, maxRht = points[0][1]; i < points.size(); ++i) {
            if (points[i][0] > maxRht) {
                ++ret;
                maxRht = points[i][1];
            }
        }

        return ret;
    }
};
