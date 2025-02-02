class Solution {
public:
    double minAreaFreeRect(vector<vector<int>>& points) {
        map<pair<int, int>, vector<pair<int, int>>> vec2pairs;
        for (int i = 0; i < points.size(); ++i) {
            for (int j = 0; j < points.size(); ++j) {
                if (i == j) { continue; }
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];
                vec2pairs[{dx, dy}].emplace_back(i, j);
            }
        }

        double ret = DBL_MAX;
        for (const auto& [vec, pairs] : vec2pairs) {
            const auto& [dx1, dy1] = vec;
            int n = pairs.size();
            for (int i = 0; i < n; ++i) {
                for (int j = i + 1; j < n; ++j) {
                    const auto& [a, _] = pairs[i];
                    const auto& [c, _] = pairs[j];
                    int dx2 = points[c][0] - points[a][0];
                    int dy2 = points[c][1] - points[a][1];
                    if (dx1 * dx2 + dy1 * dy2 != 0) { continue; }

                    double w = std::sqrt(dx1 * dx1 + dy1 * dy1);
                    double h = std::sqrt(dx2 * dx2 + dy2 * dy2);
                    ret = std::min(ret, w * h);
                }
            }
        }

        return ret == DBL_MAX ? 0 : ret;
    }
};
