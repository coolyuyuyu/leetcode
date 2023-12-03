class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ret = 0;
        for (int i = 1; i < points.size(); ++i) {
            int diffX = std::abs(points[i][0] - points[i - 1][0]);
            int diffY = std::abs(points[i][1] - points[i - 1][1]);
            ret += std::max(diffX, diffY);
        }

        return ret;
    }
};
