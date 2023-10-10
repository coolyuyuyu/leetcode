class Solution {
public:
    // TLE, Time: O(n * maxPts)
    double topdnDFS(int n, int k, int maxPts) {
        // dp[i]: the probability such that Alice starts with i points
        double dp[k + 1];
        for (int i = 0; i <= k; ++i) {
            dp[i] = -1.0;
        }
        std::function<double(int)> f = [&](int i) {
            if (i >= k) {
                return (i > n ? 0.0 : 1.0);
            }

            double& ret = dp[i];
            if (0.0 <= ret) {
                return ret;
            }

            ret = 0.0;
            for (int j = 1; j <= maxPts; ++j) {
                ret += (1.0) / maxPts * f(i + j);
            }

            return ret;
        };

        return f(0);
    }

    // TLE, Time: O(n * maxPts)
    double btmupDP1(int n, int k, int maxPts) {
        // dp[i]: the probability such that Alice gets i points
        double dp[n + 1];
        dp[0] = 1.0;

        for (int i = 1; i <= n; ++i) {
            dp[i] = 0.0;
            for (int j = std::max(0, i - maxPts); j < std::min(i, k); ++j) {
                dp[i] += 1.0 / maxPts * dp[j];
            }
        }

        double ret = 0.0;
        for (int i = k; i <= n; ++i) {
            ret += dp[i];
        }
        return ret;
    }

    // Time: O(n)
    double btmupDP2(int n, int k, int maxPts) {
        // dp[i]: the probability such that Alice gets i points
        double dp[n + 1];
        dp[0] = 1.0;

        double sum = (0 < k ? dp[0] : 0.0);
        for (int i = 1; i <= n; ++i) {
            dp[i] = 1.0 / maxPts * sum;

            if (i < k) {
                sum += dp[i];
            }
            if (0 <= i - maxPts && i - maxPts < k) {
                sum -= dp[i - maxPts];
            }
        }

        double ret = 0.0;
        for (int i = k; i <= n; ++i) {
            ret += dp[i];
        }
        return ret;
    }

    double new21Game(int n, int k, int maxPts) {
        //return topdnDFS(n, k, maxPts);
        //return btmupDP1(n, k, maxPts);
        return btmupDP2(n, k, maxPts);
    }
};
