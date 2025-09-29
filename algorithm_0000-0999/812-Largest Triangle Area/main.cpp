class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        int product = 0;
        for (int i = 0, n = points.size(); i < n; ++i) {
            int x1 = points[i][0], y1 = points[i][1];
            for (int j = i + 1; j < n; ++j) {
                int x2 = points[j][0], y2 = points[j][1];
                for (int k = j + 1; k < n; ++k) {
                    int x3 = points[k][0], y3 = points[k][1];
                    product = std::max(product, std::abs((x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1)));
                }
            }
        }

        return 1.0 * product / 2;
    }
};
