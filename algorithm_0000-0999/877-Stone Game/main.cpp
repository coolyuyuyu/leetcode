class Solution {
public:
    bool topdnDFS(vector<int>& piles) {
        int n = piles.size();

        int presum[n];
        std::partial_sum(piles.begin(), piles.end(), presum);
        std::function<int(int, int)> sum = [&](int lft, int rht) {
            return presum[rht] - (0 < lft ? presum[lft - 1] : 0);
        };

        // dp[i][j]: the maximum number of stones the player can take from piles[i:j]
        int dp[n][n];
        for (int lft = 0; lft < n; ++lft) {
            for (int rht = lft; rht < n; ++rht) {
                dp[lft][rht] = 0;
            }
        }
        std::function<int(int, int)> f = [&](int lft, int rht) {
            int& ret = dp[lft][rht];
            if (0 < ret) {
                return ret;
            }

            if (lft == rht) {
                return ret = piles[lft];
            }
            return ret = sum(lft, rht) - std::min(f(lft + 1, rht), f(lft, rht - 1));
        };

        return sum(0, n - 1) < f(0, n - 1) * 2;
    }

    bool btmupDP(vector<int>& piles) {
        int n = piles.size();

        int presum[n];
        std::partial_sum(piles.begin(), piles.end(), presum);
        std::function<int(int, int)> sum = [&](int lft, int rht) {
            return presum[rht] - (0 < lft ? presum[lft - 1] : 0);
        };

        // dp[i][j]: the maximum number of stones the player can take from piles[i:j]
        int dp[n][n];
        for (int i = 0; i < n; ++i) {
            dp[i][i] = piles[i];
        }
        for (int len = 2; len <= n; ++len) {
            for (int lft = 0, rht = lft + len - 1; rht < n; ++lft, ++rht) {
                dp[lft][rht] = sum(lft, rht) - std::min(dp[lft + 1][rht], dp[lft][rht - 1]);
            }
        }

        return sum(0, n - 1) < dp[0][n - 1] * 2;
    }

    bool math(vector<int>& piles) {
        return true;
    }

    bool stoneGame(vector<int>& piles) {
        return topdnDFS(piles);
        //return btmupDP(piles);
        //return math(piles);
    }
};
