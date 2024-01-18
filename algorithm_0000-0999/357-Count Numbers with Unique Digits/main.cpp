class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        std::function<int(int, int)> p = [](int n , int r) {
            int ret = 1;
            for (int i = 0; i < r; ++i) {
                ret *= (n - i);
            }

            return ret;
        };

        int ret = 1;
        for (int len = 1; len <= n; ++len) {
            // p(9, len - 1): number with leading 0
            ret += p(10, len) - p(9, len - 1);
        }

        return ret;
    }
};
