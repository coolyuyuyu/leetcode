class Solution {
public:
    int commonFactors(int a, int b) {
        int x = std::gcd(a, b);
        int ret = 0;
        for (int i = 1; i <= x; ++i) {
            if ((x % i) == 0) {
                ++ret;
            }
        }

        return ret;
    }
};
