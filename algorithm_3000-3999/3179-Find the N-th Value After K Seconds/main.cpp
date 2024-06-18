class Solution {
public:
    int M = 1e9 + 7;

    int combination(int n, int k) {
        int a = n + k - 1, b = n - 1;
        b = std::min(b, a - b);

        int cache[a + 1][b + 1];
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

        return comb(a, b);
    }

    int bruteforce(int n, int k) {
        int a[n];
        std::fill(a, a + n, 1);
        while (k--) {
            for (int i = 1; i < n; ++i) {
                a[i] += a[i - 1];
                a[i] %= M;
            }
        }

        return a[n - 1];
    }

    int valueAfterKSeconds(int n, int k) {
        //return combination(n, k);
        return bruteforce(n, k);
    }
};
