class Solution {
public:
    int M = 1e9 + 7;

    int countVisiblePeople(int n, int pos, int k) {
        vector<int> factorial(n);
        factorial[0] = 1;
        for (int i = 1; i < n; ++i) {
            factorial[i] = 1L * factorial[i - 1] * i % M;
        }

        std::function<int(int, int)> quickPow = [&](int base, int exp) -> int {
            int ret = 1;
            for (; exp; exp >>= 1) {
                if (exp & 1) {
                    ret = 1L * ret * base % M;
                }
                base = 1L * base * base % M;
            }

            return ret;
        };

        // (a / b) % p != (a % p) / (b % p)

        // Fermat's little Therom
        // (a / b) % p = a * inv(b) % p
        // inv(b) = b ^ (p - 2)
        // 1. p must be a prime
        // 2. b cannot be divisible by p

        // Version 3: C(n, r) = n! / (r! * (n - r)!)
        std::function<int(int, int)> comb = [&](int m, int n) -> int {
            if (m < n) { return 0; }
            int a = factorial[m];
            int b = 1L * factorial[n] * factorial[m - n] % M;
            int invB = quickPow(b, M - 2);

            return 1L * a * invB % M;
        };

        int ret = 0;
        for (int lftCnt = pos, rhtCnt = n - pos - 1, l = 0; l <= lftCnt && l <= k; ++l) {
            int r = k - l;
            if (r > rhtCnt) { continue; }

            ret += 1L* comb(lftCnt, l) * 2 % M * comb(rhtCnt, r) % M;
            ret %= M;
        }

        return ret;
    }
};
