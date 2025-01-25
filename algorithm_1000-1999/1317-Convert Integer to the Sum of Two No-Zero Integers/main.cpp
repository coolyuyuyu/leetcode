class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        std::function<bool(int)> check = [](int num) {
            for (; num; num /= 10) {
                if (num % 10 == 0) {
                    return false;
                }
            }
            return true;
        };

        for (int i = 1; i <= n / 2; ++i) {
            if (check(i) && check(n - i)) {
                return {i, n - i};
            }
        }

        __builtin_unreachable();
        return {-1, -1};
    }
};
