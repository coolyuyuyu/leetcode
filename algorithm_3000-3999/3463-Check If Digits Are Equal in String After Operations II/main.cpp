class Solution {
public:
    // https://oi-wiki.org/math/number-theory/lucas/
    bool hasSameDigits(string s) {
        std::function<int(int, int)> C = [&] (int n, int r) {
            int ret = 1;
            for (int i = 0; i < r; ++i) {
                ret *= (n - i);
                ret /= (i + 1);
            }

            return ret;
        };

        std::function<int(int, int, int)> Lucas = [&](int n, int m, int p) {
            if (m == 0) return 1;
            return (C(n % p, m % p) * Lucas(n / p, m / p, p)) % p;
        };

        std::function<bool(int)> check = [&](int p) {
            int n = s.size() - 2;
            int sum1 = 0, sum2 = 0;
            for (int i = 0; i <= n; ++i) {
                sum1 += Lucas(n, i, p) * (s[i] - '0') % p;
                sum1 %= p;

                sum2 += Lucas(n, i, p) * (s[i + 1] - '0') % p;
                sum2 %= p;
            }

            return sum1 == sum2;
        };

        return check(2) && check(5);
    }
};
