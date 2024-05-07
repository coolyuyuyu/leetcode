class Solution {
public:
    void f1(long long n, vector<long long>& cnts) {
        for (int d = 1; d <= cnts.size(); ++d) {
            long long lower = 1;
            long long upper = std::min(n - d, n);
            cnts[d - 1] += std::max(upper - lower + 1, 0LL);
        }
    }

    void f2(long long a, long long b, vector<long long>& cnts) {
        for (int d = 1; d <= cnts.size(); ++d) {
            long long lower = std::max(a + 3 - d, 1LL);
            long long upper = std::min(a + 2 + b - d, a);
            cnts[d - 1] += std::max(upper - lower + 1, 0LL);
        }
    }

    void f3(long long n, long long p, long long q, vector<long long>& cnts) {
        for (int d = 1; d <= cnts.size(); ++d) {
            long long lower = std::max(n + 2 - d, 1LL);
            long long upper = std::min(n + 1 + p - d, n);
            cnts[d - 1] += std::max(0LL + upper - lower + 1, 0LL);
        }

        for (int d = 1; d <= cnts.size(); ++d) {
            long long lower = std::max(n + 2 - d, 1LL);
            long long upper = std::min(n + 1 + q - d, n);
            cnts[d - 1] += std::max(0LL + upper - lower + 1, 0LL);
        }

        for (int d = 1; d <= cnts.size(); ++d) {
            if (d <= n) {
                cnts[d - 1] += 1;
            }
        }
    }

    void f4(long long n, vector<long long>& cnts) {
        for (int d = 1; d <= cnts.size(); ++d) {
            if (d < n - d) {
                cnts[d - 1] += n * 2;
            }
            else if (d == n - d ) {
                cnts[d - 1] += n;
            }
        }
    }

    vector<long long> countOfPairs(int n, int x, int y) {
        if (x > y) { std::swap(x, y); }

        long long a = x - 1;
        long long b = n - y;
        long long c = y - x + 1;
        vector<long long> ret(n);

        if (c <= 1) {
            for (int d = 1; d <= ret.size(); ++d) {
                ret[d - 1] = (n - d) * 2;
            }
            return ret;
        }

        // AA
        f1(a, ret);

        // BB
        f1(b, ret);

        // AB
        f2(a, b, ret);

        // AC
        f3(a, (c - 1) / 2, (c - 1) - (c - 1) / 2, ret);

        // BC
        f3(b, (c - 1) / 2, (c - 1) - (c - 1) / 2, ret);

        for (long long& cnt : ret) {
            cnt *= 2;
        }

        // CC
        f4(c, ret);

        return ret;
    }
};

// A   A   C   C   C   C   B   B
// o - o - o - o - o - o - o - o
//         |           |
//         - - - - - - -

// AA => f1(a)
// BB => f1(b)
// AB => f2(a, b)
// AC => f3(a, (c - 1) / 2) + f3(a, (c - 1) - (c - 1) / 2))
// BC => f3(b, (c - 1) / 2) + f3(b, (c - 1) - (c - 1) / 2))
// CC => f4(c)
