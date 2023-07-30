class Solution {
public:
    std::vector<pair<int, int>> dirs = {{-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}};

    double recursion(int n, int k, int row, int column) {
        double cache[k + 1][n][n];
        for (int i = 0; i <= k; ++i) {
            for (int r = 0; r < n; ++r) {
                for (int c = 0; c < n; ++c) {
                    cache[i][r][c] = -1.0;
                }
            }
        }
        std::function<double(int, int, int, double)> f = [&](int depth, int r, int c, double prob) {
            if (r < 0 || n <= r || c < 0 || n <= c) {
                return 0.0;
            }

            double& ret = cache[depth][r][c];
            if (0.0 <= ret) {
                return ret;
            }

            if (k <= depth) {
                ret = prob;
                return prob;
            }

            ret = 0.0;
            for (const auto& [dr, dc] : dirs) {
                int x = r + dr, y = c + dc;
                ret += f(depth + 1, x, y, prob) / dirs.size();
            }

            return ret;
        };

        return f(0, row, column, 1.0);
    }

    double dp(int n, int k, int row, int column) {
        vector<vector<double>> dp1(n, vector<double>(n));
        dp1[row][column] = 1.0;
        for (int d = 0; d < k; ++d) {
            vector<vector<double>> dp2(n, vector<double>(n));
            for (int r = 0; r < n; ++r) {
                for (int c = 0; c < n; ++c) {
                    for (const auto& [dr, dc] : dirs) {
                        int x = r + dr, y = c + dc;
                        if (x < 0 || n <= x || y < 0 || n <= y) {
                            continue;
                        }
                        dp2[r][c] += dp1[x][y] / dirs.size();
                    }
                }
            }

            dp1.swap(dp2);
        }

        double ret = 0.0;
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                ret += dp1[r][c];
            }
        }

        return ret;
    }

    double knightProbability(int n, int k, int row, int column) {
        //return recursion(n, k, row, column);
        return dp(n, k, row, column);
    }
};
