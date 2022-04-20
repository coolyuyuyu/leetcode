class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        int product = 0;
        for (size_t i = 0; (i + 2) < points.size(); ++i) {
            int xa = points[i][0], ya = points[i][1];
            for (size_t j = i + 1; (j + 1) < points.size(); ++j) {
                int xb = points[j][0], yb = points[j][1];
                for (size_t k = j + 1; k < points.size(); ++k) {
                    int xc = points[k][0], yc = points[k][1];
                    product = std::max(product, std::abs((xb - xa) * (yc - ya) - (xc - xa) * (yb - ya)));
                }
            }
        }

        return double(product) / 2;
    }
};
