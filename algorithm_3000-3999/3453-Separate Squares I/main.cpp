class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double area = 0;
        for (const auto& square : squares) {
            int l = square[2];
            area += 1.0 * l * l;
        }

        std::function<double(double)> computeAreaAbove = [&](double sep) {
            double ret = 0;
            for (const auto& square : squares) {
                double y = square[1], l = square[2];
                if (sep >= y + l) {
                }
                else if (sep > y) {
                    ret += (y + l - sep) * l;
                }
                else {
                    ret += l * l;
                }
            }

            return ret;
        };

        double lo = 0, hi = 1e10;
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
