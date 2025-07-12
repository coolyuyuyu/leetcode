class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();

        std::sort(events.begin(), events.end(), [](const auto& e1, const auto& e2){ return e1[1] < e2[1]; });
        events.insert(events.begin(), {0, 0, 0});

        // dp[i][j]: the maximum sum of values by attending j events from events[:i];
        int dp[n + 1][k + 1];
        dp[0][0] = 0;
        for (int i = 1; i <= n; ++i) {
            dp[i][0] = 0;
        }
        for (int j = 1; j <= k; ++j) {
            dp[0][j] = INT_MIN;
        }
        for (int i = 1; i <= n; ++i) {
            auto itr = std::lower_bound(
                events.begin(), events.begin() + i,
                vector<int>{0, events[i][0], 0},
                [](const auto& e1, const auto& e2){ return e1[1] < e2[1]; });
            int x = std::distance(events.begin(), itr) - 1;;
            for (int j = 1; j <= k; ++j) {
                // do not attend events[i] V.S. do attend events[i]
                dp[i][j] = std::max(dp[i - 1][j], dp[x][j - 1] + events[i][2]);
            }
        }

        int ret = 0;
        for (int j = 1; j <= k; ++j) {
            ret = std::max(ret, dp[n][j]);
        }

        return ret;
    }
};
