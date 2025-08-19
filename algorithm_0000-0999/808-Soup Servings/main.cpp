class Solution {
public:
    double btmupDP(int n) {
        if (n > 5000) {
            return 1.0;
        }

        n = (n + 25 - 1) / 25;

        // dp[a][b]: the probability that A is poured a units and B is poured b units.
        double dp[n + 1][n + 1];
        for (int a = 0; a <= n; ++a) {
            for (int b = 0; b <= n; ++b) {
                dp[a][b] = 0;
            }
        }

        dp[0][0] = 1.0;
        for (int a = 0; a < n; ++a) {
            for (int b = 0; b < n; ++b) {
                dp[std::min(a + 4, n)][std::min(b + 0, n)] += dp[a][b] * 0.25;
                dp[std::min(a + 3, n)][std::min(b + 1, n)] += dp[a][b] * 0.25;
                dp[std::min(a + 2, n)][std::min(b + 2, n)] += dp[a][b] * 0.25;
                dp[std::min(a + 1, n)][std::min(b + 3, n)] += dp[a][b] * 0.25;
            }
        }

        double ret = 0;
        for (int b = 0; b < n; ++b) {
            ret += dp[n][b];
        }
        ret += dp[n][n] * 0.5;

        return ret;
    }

    double topdnDP(int n) {
        if (n > 5000) {
            return 1.0;
        }

        n = (n + 25 - 1) / 25;
        double dp[n + 1][n + 1];
        for (int a = 0; a <= n; ++a) {
            for (int b = 0; b <= n; ++b) {
                dp[a][b] = -1.0;
            }
        }
        std::function<double(int, int)> f = [&](int a, int b) {
            if (a <= 0 && b > 0) {
                return 1.0;
            }
            else if (a <= 0 && b <= 0) {
                return 0.5;
            }
            else if (a >= 0 && b <= 0) {
                return 0.0;
            }

            double& ret = dp[a][b];
            if (ret >= 0) {
                return ret;
            }

            ret = 0.0;
            ret += f(a - 4, b - 0) * 0.25;
            ret += f(a - 3, b - 1) * 0.25;
            ret += f(a - 2, b - 2) * 0.25;
            ret += f(a - 1, b - 3) * 0.25;
            return ret;
        };

        return f(n, n);
    }

    double soupServings(int n) {
        return btmupDP(n);
        //return topdnDP(n);
    }
};
