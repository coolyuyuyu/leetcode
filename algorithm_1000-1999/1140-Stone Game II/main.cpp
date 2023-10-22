class Solution {
public:
    int topdnDFS(vector<int>& piles) {
        int n = piles.size();

        int presum[n];
        std::partial_sum(piles.begin(), piles.end(), presum);
        std::function<int(int)> sufsum = [&](int i) {
            if (i >= n) {
                return 0;
            }
            return presum[n - 1] - (0 < i ? presum[i - 1] : 0);
        };

        // dp[i]: the maximum number of stones the player can take from piles[i:]
        int dp[n][n + 1];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= n; ++j) {
                dp[i][j] = 0;
            }
        }
        std::function<int(int, int)> f = [&](int i, int M) {
            if (n <= i) {
                return 0;
            }

            int& ret = dp[i][M];
            if (0 < ret) {
                return ret;
            }

            for (int X = 1; X <= 2 * M && i + X - 1 < n; ++X) {
                //ret = std::max(ret, sum(i, i + X - 1) + sum(i + X, n) - f(i + X, std::max(M, X)));
                ret = std::max(ret, sufsum(i) - f(i + X, std::max(M, X)));
            }
            return ret;
        };

        return f(0, 1);
    }

    int stoneGameII(vector<int>& piles) {
        return topdnDFS(piles);
    }
};
