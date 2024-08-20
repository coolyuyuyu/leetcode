class Solution {
public:
    int topdnDFS(vector<int>& piles) {
        int n = piles.size();

        int presums[n];
        std::partial_sum(piles.begin(), piles.end(), presums);
        std::function<int(int, int)> sum = [&](int lo, int hi) {
            if (lo > hi) {
                return 0;
            }
            return presums[hi] - (lo > 0 ? presums[lo - 1] : 0);
        };

        // dp[i][j]: the maximum number of stones the player can take from piles[i:] where M = j
        int dp[n][n + 1];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= n; ++j) {
                dp[i][j] = 0;
            }
        }
        std::function<int(int, int)> solve = [&](int i, int M) {
            if (i >= n) {
                return 0;
            }

            int& ret = dp[i][M];
            if (ret > 0) {
                return ret;
            }

            for (int X = 1; X <= 2 * M && i + X - 1 < n; ++X) {
                ret = std::max(ret, sum(i, i + X - 1) + sum(i + X, n - 1) - solve(i + X, std::max(X, M)));
            }

            return ret;
        };

        return solve(0, 1);
    }

    int stoneGameII(vector<int>& piles) {
        return topdnDFS(piles);
    }
};
