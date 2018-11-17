class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double maxArea = 0.0;

        size_t n = points.size();
        for (size_t i = 0; i + 2 < n; ++i) {
            double x0 = points[i][0], y0 = points[i][1];
            for (size_t j = i + 1; j + 1 < n; ++j) {
                double x1 = points[j][0], y1 = points[j][1];
                for (size_t k = j + 1; k < n; ++k) {
                    double x2 = points[k][0], y2 = points[k][1];
                    double area = fabs((x1 - x0) * (y2 - y0) - (x2 - x0) * (y1 - y0)) / 2;
                    if (maxArea < area) {
                        maxArea = area;
                    }
                }
            }
        }

        return maxArea;
    }
};