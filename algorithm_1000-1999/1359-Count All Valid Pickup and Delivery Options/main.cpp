class Solution {
public:
    int M = 1e9 + 7;

    int math1(int n) {
        int cache[n * 2 + 2 + 1][3];
        std::memset(cache, -1, sizeof(cache));

        std::function<int(int, int)> comb = [&](int n, int r) {
            if ((n - r) < r) {
                r = n - r;
            }

            if (r == 0) {
                return 1;
            }
            else if (r == 1) {
                return n;
            }

            int& ret = cache[n][r];
            if (ret < 0) {
                // C(m, n) = C(m-1, n) + C(m-1, n-1)
                ret = (comb(n - 1, r - 1) + comb(n - 1, r)) % M;
            }

            return ret;
        };

        long long ret = 1;
        for (int i = 1; i < n; ++i) {
            ret *= comb(i * 2 + 2, 2);
            ret %= M;
        }

        return ret;
    }

    int math2(int n) {
        long long ret = 1;
        for (int i = 1; i <= n; ++i) {
            ret *= i;
            ret %= M;

            ret *= (2 * i - 1);
            ret %= M;
        }

        return ret;

    }

    int countOrders(int n) {
        //return math1(n);
        return math2(n);
    }
};
