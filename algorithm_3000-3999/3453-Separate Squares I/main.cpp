class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double area = 0.0;
        for (const auto& square : squares) {
            double l = square[2];
            area += l * l;
        }

        std::function<double(double)> computeAreaAbove = [&](double sep) {
            double area = 0;
            for (const auto& square : squares) {
                double x = square[0], y = square[1], l = square[2];
                if (sep < y) {
                    area += l * l;
                }
                else if (sep < y + l) {
                    area += (y + l - sep) * l;
                }
            }

            return area;
        };

        double lo = 0, hi = 1e14;
        while (hi - lo > 1e-5) {
            double mid = (lo + hi) / 2;
            if (computeAreaAbove(mid) > area / 2) {
                lo = mid;
            }
            else {
                hi = mid;
            }
        }

        return lo;
    }
};
