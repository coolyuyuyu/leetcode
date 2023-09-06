class Solution {
public:
    int minBuildTime(vector<int>& blocks, int split) {
        std::sort(blocks.rbegin(), blocks.rend());
        int n = blocks.size();

        // dp[i][j]: minimum time needed to build blocks[i:] by j workers
        int dp[n][n];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dp[i][j] = -1;
            }
        }
        std::function<int(int, int)> f = [&](int i, int j) {
            if (i == n) {
                return 0;
            }
            else if ((n - i) <= j) {
                return blocks[i];
            }
            else if (j == 0) {
                return INT_MAX / 2;
            }
            else if (dp[i][j] != -1) {
                return dp[i][j];
            }

            int& ret = dp[i][j];
            ret = std::min(split + f(i, j * 2), std::max(blocks[i], f(i + 1, j - 1)));

            return ret;
        };

        return f(0, 1);
    }
};
