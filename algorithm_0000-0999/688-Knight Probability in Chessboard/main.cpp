class Solution {
public:
    vector<pair<int, int>> dirs = {{-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}};

    double topdnRecursion(int n, int k, int row, int column) {
        // dp[r][c][k]: the probability that the knight remains on the board after it starts from (r, c) and moves k times.
        double dp[n][n][k + 1];
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                for (int move = 0; move <= k; ++move) {
                    dp[r][c][move] = -1.0;
                }
            }
        }
        std::function<double(int ,int, int)> f = [&](int r, int c, int k) {
            double& ret = dp[r][c][k];
            if (0.0 <= ret) {
                return ret;
            }

            if (k == 0) {
                return ret = 1.0;
            }

            ret = 0.0;
            for (const auto& [dr, dc] : dirs) {
                int x = r + dr, y = c + dc;
                if (x < 0 || n <= x || y < 0 || n <= y) { continue; }

                ret += f(x, y, k - 1) / dirs.size();
            }

            return ret;
        };

        return f(row, column, k);
    }

    double btmupDP(int n, int k, int row, int column) {
        // dp[r][c][k]: the probability that the knight reaches (r, c) with k moves
        double dp[n][n], tmp[n][n];
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                dp[r][c] = 0.0;
            }
        }
        dp[row][column] = 1.0;

        for (int move = 0; move < k; ++move) {
            for (int r = 0; r < n; ++r) {
                for (int c = 0; c < n; ++c) {
                    tmp[r][c] = dp[r][c];
                    dp[r][c] = 0.0;
                }
            }
            for (int r = 0; r < n; ++r) {
                for (int c = 0; c < n; ++c) {
                    for (const auto& [dr, dc] : dirs) {
                        int x = r + dr, y = c + dc;
                        if (x < 0 || n <= x || y < 0 || n <= y) { continue; }

                        dp[r][c] += tmp[x][y] / dirs.size();
                    }
                }
            }
        }

        double ret = 0.0;
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                ret += dp[r][c];
            }
        }

        return ret;
    }

    double knightProbability(int n, int k, int row, int column) {
        //return topdnRecursion(n, k, row, column);
        return btmupDP(n, k, row, column);
    }
};
