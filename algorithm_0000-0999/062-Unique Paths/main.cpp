class Solution {
public:
    // Time: O(m*n), Space: O(m*n)
    int dp1(int m, int n) {
        // dp[r][c] the number of possible unique paths that the robot can take to reach (r, c)
        int dp[m][n];
        dp[0][0] = 1;
        for (int r = 1; r < m; ++r) {
            dp[r][0] = 1;
        }
        for (int c = 1; c < n; ++c) {
            dp[0][c] = 1;
        }
        for (int r = 1; r < m; ++r) {
            for (int c = 1; c < n; ++c) {
                dp[r][c] = dp[r - 1][c] + dp[r][c - 1];
            }
        }

        return dp[m - 1][n - 1];
    }

    // Time: O(m*n), Space: O(m*2)
    int dp2(int m, int n) {
        int dp[n];
        for (int c = 0; c < n; ++c) {
            dp[c] = 1;
        }
        for (int r = 1; r < m; ++r) {
            for (int c = 1; c < n; ++c) {
                dp[c] += dp[c - 1];
            }
        }
        return dp[n - 1];
    }

    int math(int m, int n) {
        std::map<pair<int, int>, int> cache;
        std::function<int(int, int)> combination = [&](int n, int r) {
            if ((n - r) < r) {
                return combination(n, n - r);
            }

            if (r == 0 || r == n) {
                return 1;
            }
            else if (r == 1) {
                return n;
            }
            else if (cache.find({n, r}) != cache.end()) {
                return cache[{n, r}];
            }

            int& ret = cache[{n, r}];
            ret = combination(n - 1, r - 1) + combination(n - 1, r);
            return ret;
        };

        return combination(m + n - 2, m - 1);
    }

    int uniquePaths(int m, int n) {
        //return dp1(m, n);
        //return dp2(m, n);
        return math(m, n);
    }
};
