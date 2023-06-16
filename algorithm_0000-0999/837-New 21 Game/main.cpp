class Solution {
public:
    // TLE, Time: O(n * maxPts)
    double dfs(int n, int k, int maxPts) {
        std::function<double(int)> recursive = [&](int cur) {
            if (cur >= k) {
                if (cur <= n) {
                    return 1.0;
                }
                else {
                    return 0.0;
                }
            }

            double sum = 0.0;
            for (int i = 1; i <= maxPts; ++i) {
                sum += 1.0 / maxPts * recursive(cur + i);
            }

            return sum;
        };
        return recursive(0);
    }

    // TLE, Time: O(n * maxPts)
    double dfs_memo(int n, int k, int maxPts) {
        vector<double> cache(n + 1, DBL_MIN);
        std::function<double(int)> recursive = [&](int cur) {
            if (cur >= k) {
                if (cur <= n) {
                    return 1.0;
                }
                else {
                    return 0.0;
                }
            }

            if (cache[cur] != DBL_MIN) {
                return cache[cur];
            }

            double& sum = cache[cur];
            sum = 0;
            for (int i = 1; i <= maxPts; ++i) {
                sum += 1.0 / maxPts * recursive(cur + i);
            }

            return sum;
        };
        return recursive(0);
    }

    // TLE, Time: O(n * maxPts)
    double dp(int n, int k, int maxPts) {
        vector<double> p(n + 1, 0);
        p[0] = 1.0;
        for (int i = 1; i <= n; ++i) {
            for (int j = std::max(i - maxPts, 0); j <= (i - 1) && j < k; ++j) {
                p[i] += (p[j] * 1.0 / maxPts);
            }
        }

        double ret = 0.0;
        for (int i = k; i <= n; ++i) {
            ret += p[i];
        }

        return ret;
    }

    // Time: O(n)
    double dp_presum(int n, int k, int maxPts) {
        vector<double> p(n + 1, 0);
        p[0] = 1.0;

        double sum = 0.0;
        for (int i = 1; i <= n; ++i) {
            if (0 <= i - maxPts - 1 && (i - maxPts - 1) < k) {
                sum -= p[i - maxPts - 1];
            }
            if ((i - 1) < k) {
                sum += p[i - 1];
            }

            p[i] = sum * 1.0 / maxPts;
        }

        double ret = 0.0;
        for (int i = k; i <= n; ++i) {
            ret += p[i];
        }

        return ret;
    }

    double new21Game(int n, int k, int maxPts) {
        //return dfs(n, k, maxPts);
        //return dfs_memo(n, k, maxPts);

        //return dp(n, k, maxPts);
        return dp_presum(n, k, maxPts);
    }
};
