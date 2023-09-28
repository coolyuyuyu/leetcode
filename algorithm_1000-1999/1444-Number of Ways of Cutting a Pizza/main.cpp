class Solution {
public:
    int M = 1e9 + 7;

    int ways(vector<string>& pizza, int k) {
        int m = pizza.size(), n = pizza.empty() ? 0 : pizza[0].size();

        int presum[m][n];
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                presum[r][c] = (pizza[r][c] == 'A' ? 1 : 0);
                presum[r][c] += (0 < r ? presum[r - 1][c] : 0);
                presum[r][c] += (0 < c ? presum[r][c - 1] : 0 );
                presum[r][c] -= (0 < r && 0 < c ? presum[r - 1][c - 1] : 0);
            }
        }
        std::function<bool(int, int, int, int)> containApples = [&](int r1, int c1, int r2, int c2) {
            int cnt = presum[r2][c2] - (0 < r1 ? presum[r1 - 1][c2] : 0) - (0  < c1 ? presum[r2][c1 - 1] : 0) + (0 < r1 && 0 < c1 ? presum[r1 - 1][c1 - 1] : 0);
            return 0 < cnt;
        };

        // dp[r][c][remaining]: the number of ways of cutting the pizza[r:m-1][c:n-1] with remaining cut
        int dp[m][n][k];
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                for (int remaining = 0; remaining < k; ++remaining) {
                    dp[r][c][remaining] = -1;
                }
            }
        }
        std::function<int(int, int, int)> countWays = [&](int r, int c, int remaining) {
            int& ret = dp[r][c][remaining];
            if (0 <= ret) {
                return ret;
            }

            if (remaining == 0) {
                ret = containApples(r, c, m - 1, n - 1) ? 1 : 0;
                return ret;
            }

            ret = 0;
            for (int i = r; (i + 1) < m; ++i) { // horizontal
                if (containApples(r, c, i, n - 1)) {
                    ret += countWays(i + 1, c, remaining - 1);
                    ret %= M;
                }
            }
            for (int j = c; (j + 1) < n; ++j) { // vertical
                if (containApples(r, c, m - 1, j)) {
                    ret += countWays(r, j + 1, remaining - 1);
                    ret %= M;
                }
            }

            return ret;
        };

        return countWays(0, 0, k - 1);
    }
};
