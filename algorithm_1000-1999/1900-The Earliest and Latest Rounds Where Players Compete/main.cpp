class Solution {
public:
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        // dp[n][a][b]: the earliest and latest round number for n player where a and b are the best two player.
        pair<int, int> dp[n + 1][n + 1][n + 1];
        std::function<pair<int, int>(int, int, int)> f = [&](int n, int a, int b) -> pair<int, int> {
            if (a + b == n + 1) {
                return {1, 1};
            }

            if (dp[n][a][b] != pair<int, int>(0, 0)) {
                return dp[n][a][b];
            }

            // m: middle point of n players
            // c: symmetric point of a
            // d: symmetric point of b
            float m = (n + 1) / 2.0;
            int c = n + 1 - a, d = n + 1 - b;

            // always assume a < b
            if (b < a) {
                return f(n, b, a);
            }

            // make a and b lean to left
            if (m < (a + b) / 2.0) {
                return f(n, d, c);
            }

            auto& [mn, mx] = dp[n][a][b];
            mn = INT_MAX / 2, mx = INT_MIN / 2;

            if (m < b) {
                // . . . a . . d . M . b . . c . . .
                // _____   ___   _____
                //   x      y      z
                int z = b - d - 1;
                for (int x = 0; x <= a - 1; ++x) {
                    for (int y = 0; y <= d - a - 1; ++y) {
                        auto [mnSub, mxSub] = f((n + 1) / 2, x + 1, x + 1 + y + (z + 1) / 2 + 1);
                        mn = std::min(mn, mnSub + 1);
                        mx = std::max(mx, mxSub + 1);
                    }
                }
            }
            else {
                // . . . a . . b . M . d . . c . . .
                // _____ a ___ b
                //    x     y
                for (int x = 0; x <= a - 1; ++x) {
                    for (int y = 0; y <= b - a - 1; ++y) {
                        auto [mnSub, mxSub] = f((n + 1) / 2, x + 1, x + 1 + y + 1);
                        mn = std::min(mn, mnSub + 1);
                        mx = std::max(mx, mxSub + 1);
                    }
                }
            }

            return {mn, mx};
        };

        auto [mn, mx] = f(n, firstPlayer, secondPlayer);
        return {mn, mx};
    }
};
