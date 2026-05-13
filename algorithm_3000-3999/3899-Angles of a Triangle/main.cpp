class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {
        std::sort(sides.begin(), sides.end());
        int a = sides[0], b = sides[1], c= sides[2];
        if (a + b <= c) {
            return {};
        }

        double A = std::acos(1.0 * (b * b + c * c - a * a) / (2 * b * c));
        A = A * 180 / std::numbers::pi;
        double B = std::acos(1.0 * (a* a + c * c - b * b) / (2 * a * c));
        B = B * 180 / std::numbers::pi;
        double C = std::acos(1.0 * (a * a + b * b - c * c) / (2 * a * b));
        C = C * 180 / std::numbers::pi;

        vector<double> ret = {A, B, C};
        std::sort(ret.begin(), ret.end());

        return ret;
    }
};
