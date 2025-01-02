class Solution {
public:
    int M = 1e9 + 7;

    int countGoodArrays(int n, int m, int k) {
        vector<int> factorial(n);
        factorial[0] = 1;
        for (int i = 1; i < n; ++i) {
            factorial[i] = 1L * factorial[i - 1] * i % M;
        }

        std::function<int(int, int)> quickPow = [&](int base, int exp) {
            int ret = 1;
            for (; exp; exp >>= 1) {
                if (exp & 1) {
                    ret = 1L * ret * base % M;
                }
                base = 1L * base * base % M;
            }

            return ret;
        };

        std::function<int(int, int)> comb = [&](int m, int n) -> int {
            if (m < n) { return 0; }
            int a = factorial[m];
            int b = 1L * factorial[n] * factorial[m - n] % M;
            int invB = quickPow(b, M - 2);

            return 1L * a * invB % M;
        };

        return 1L * comb(n - 1, k) * m  % M * quickPow(m - 1, n - k - 1) % M;
    }
};
