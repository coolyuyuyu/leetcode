class Solution {
public:
    double btmupDP(int n) {
        if (5000 < n) {
           return 1.0;
        }

        n = (n + 24) / 25;

        // dp[i][j]: the probability that soup A is (n - i) units and soup B is (n - j) units
        double dp[n + 1][n + 1];
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= n; ++j) {
                dp[i][j] = 0.0;
            }
        }
        dp[0][0] = 1.0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dp[std::min(n, i + 4)][std::min(n, j + 0)] += dp[i][j] * 0.25;
                dp[std::min(n, i + 3)][std::min(n, j + 1)] += dp[i][j] * 0.25;
                dp[std::min(n, i + 2)][std::min(n, j + 2)] += dp[i][j] * 0.25;
                dp[std::min(n, i + 1)][std::min(n, j + 3)] += dp[i][j] * 0.25;
            }
        }

        double ret = 0.0;
        for (int j = 0; j < n; ++j) {
            ret += dp[n][j];
        }
        ret += (dp[n][n]/ 2);

        return ret;
    }

    double topdnRecursion(int n) {
        if (5000 < n) {
           return 1.0;
        }

        n = (n + 24) / 25;

        // dp[i][j]: the probability that initially we have i ml of A and j ml of B
        double dp[n + 1][n + 1];
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= n; ++j) {
                dp[i][j] = -1.0;
            }
        }
        std::function<double(int, int)> f = [&](int a, int b) {
            if (a <= 0 && b > 0) {
                return 1.0;
            }
            else if (a > 0 && b <= 0) {
                return 0.0;
            }
            else if (a <= 0 && b <= 0){
                return 0.5;
            }

            double& ret = dp[a][b];
            if (ret >= 0.0) {
                return ret;
            }

            ret = 0;
            ret += f(a - 4, b - 0) * 0.25;
            ret += f(a - 3, b - 1) * 0.25;
            ret += f(a - 2, b - 2) * 0.25;
            ret += f(a - 1, b - 3) * 0.25;

            return ret;
        };

        return f(n, n);
    }

    double soupServings(int n) {
        //return btmupDP(n);
        return topdnRecursion(n);
    }
};
