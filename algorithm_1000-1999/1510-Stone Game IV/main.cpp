class Solution {
public:
    bool topdnDFS(int n) {
        //dp[i]: whether the player can win when there are n stones
        char dp[n + 1];
        std::fill(dp, dp + n + 1, -1);
        std::function<bool(int)> f = [&](int n) {
            char& ret = dp[n];
            if (ret >= 0) {
                return ret;
            }

            if (n == 0) {
                return ret = 0;
            }
            for (int i = std::sqrt(n); i >= 1; --i) {
                if (!f(n - i * i)) {
                    return ret = 1;
                }
            }

            return ret = 0;
        };

        return f(n);
    }

    bool btmupDP(int n) {
        //dp[i]: whether the player can win when there are n stones
        bool dp[n + 1];
        dp[0] = false;
        for (int i = 1; i <= n; ++i) {
            dp[i] = false;
            for (int j = std::sqrt(i); j >= 1; --j) {
                if (!dp[i - j * j]) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }

    bool winnerSquareGame(int n) {
        //return topdnDFS(n);
        return btmupDP(n);
    }
};
