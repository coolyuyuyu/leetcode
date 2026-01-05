class Solution {
public:
    int M = 1e9 + 7;

    int numberOfRoutes(vector<string>& grid, int d) {
        int m = grid.size(), n = grid.empty() ? 0 : grid[0].size();

        // dp[r][c]: number of routes reaches (r, c);
        int dp[n];
        int tmp[n];
        std::function<void(const string& mask, int)>move = [&](const string& mask, int d) {
            std::copy(dp, dp + n, tmp);

            int sum = 0;
            for (int c = 0; c < d && c < n; ++c) {
                sum += tmp[c];
                sum %= M;
            }

            for (int c = 0; c < n; ++c) {
                if (c + d < n) {
                    sum += tmp[c + d];
                    sum %= M;
                }

                dp[c] = (mask[c] == '.' ? sum : 0);

                if (c - d >= 0) {
                    sum -= tmp[c - d];
                    sum = (sum + M) % M;
                }
            }
        };

        std::fill(dp, dp + n, 1);
        for (int c = 0; c < n; ++c) {
            dp[c] = (grid[m - 1][c] == '.' ? 1 : 0);
        }
        move(grid[m - 1], d);

        for (int r = m - 2; r >= 0; --r) {
            move(grid[r], std::sqrt(d * d - 1)); // move up
            move(grid[r], d); // move lft/rht
        }

        int ret = 0;
        for (int c = 0; c < n; ++c) {
            ret += dp[c];
            ret %= M;
        }

        return ret;
    }
};
