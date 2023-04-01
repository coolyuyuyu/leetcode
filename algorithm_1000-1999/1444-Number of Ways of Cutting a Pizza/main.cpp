class Solution {
public:
    int M = 1e9 + 7;

    int ways(vector<string>& pizza, int k) {
        size_t m = pizza.size(), n = pizza.empty() ? 0 : pizza[0].size();

        vector<vector<int>> sum(m, vector<int>(n, 0));
        sum[0][0] = (pizza[0][0] == 'A' ? 1 : 0);
        for (int r = 1; r < m; ++r) {
            sum[r][0] = sum[r - 1][0] + (pizza[r][0] == 'A' ? 1 : 0);
        }
        for (int c = 1; c < n; ++c) {
            sum[0][c] = sum[0][c - 1] + (pizza[0][c] == 'A' ? 1 : 0);
        }
        for (int r = 1; r < m; ++r) {
            for (int c = 1; c < n; ++c) {
                sum[r][c] = (pizza[r][c] == 'A' ? 1 : 0) + sum[r - 1][c] + sum[r][c - 1] - sum[r-1][c-1];
            }
        }
        std::function<bool(int, int, int, int)> hasApples = [&](int r1, int c1, int r2, int c2) -> bool {
            return (0 < (sum[r2][c2] - (0 < r1 ? sum[r1 - 1][c2] : 0) - (0 < c1 ? sum[r2][c1 - 1] : 0) + ((0 < r1 && 0 < c1 )? sum[r1 - 1][c1 - 1] : 0)));
        };

        map<tuple<int, int, int>, int> cache;

        // dp(r, c, remaining): number of ways of cutting the pizza[r:m][c:n] with remaining cut
        std::function<int(int, int, int)> dp = [&](int r, int c, int remaining) -> int {
            if (remaining == 0) {
                return hasApples(r, c, m - 1, n - 1) ? 1 : 0;
            }

            if (cache.find({r, c, remaining}) != cache.end()) {
                return cache[{r, c, remaining}];
            }

            int& ret = cache[{r, c, remaining}];
            for (int i = r + 1; i < m; ++i) { // horizontal
                if (hasApples(r, c, i - 1, n - 1)) {
                    ret = (ret + dp(i, c, remaining - 1)) % M;
                }
            }
            for (int j = c + 1; j < n; ++j) { // vertical
                if (hasApples(r, c, m - 1, j - 1)) {
                    ret = (ret + dp(r, j, remaining - 1)) % M;
                }
            }

            return ret;
        };

        return dp(0, 0, k - 1);
    }
};
