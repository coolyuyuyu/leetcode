class Solution {
public:
    int maxHeightOfTriangle(int red, int blue) {
        std::function<int(int, int)> f = [](int sum1, int sum2) {
            int n1 = std::sqrt(sum1);
            int n2 = (-1 + std::sqrt(1 + 4 * sum2)) / 2;
            if (n1 > n2) {
                return n2 * 2 + 1;
            }
            else if (n1 == n2) {
                return n1 + n2;
            }
            else {
                return n1 * 2;
            }
        };

        return std::max(f(red, blue),  f(blue, red));
    }
};
