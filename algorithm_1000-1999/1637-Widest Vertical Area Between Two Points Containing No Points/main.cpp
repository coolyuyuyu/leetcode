class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        std::sort(points.begin(), points.end(), [](const auto& point1, const auto& point2){ return point1[0] < point2[0]; });

        int ret = 0;
        for (int i = 1; i < points.size(); ++i) {
            ret = std::max(ret, points[i][0] - points[i - 1][0]);
        }

        return ret;
    }
};
