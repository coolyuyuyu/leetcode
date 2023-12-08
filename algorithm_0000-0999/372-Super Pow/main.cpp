class Solution {
public:
    int M = 1337;

    int superPow(int a, vector<int>& b) {
        std::function<int(int, int)> quickPow = [&](int base, int exp) {
            int ret = 1;
            for (; exp; exp >>= 1) {
                if (exp & 1) {
                    ret *= base;
                    ret %= M;
                }
                base *= base;
                base %= M;
            }

            return ret;
        };

        std::function<int(int, int, int)> f = [&](int base, int lo, int hi) {
            if (lo >= hi) {
                return quickPow(base, b[lo]);
            }
            else {
                return quickPow(f(base, lo, hi - 1), 10) * quickPow(base, b[hi]) % M;
            }
        };

        return f(a % M, 0, (b.size() - 1));
    }
};
