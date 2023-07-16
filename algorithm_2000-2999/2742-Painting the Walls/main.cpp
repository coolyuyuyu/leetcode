class Solution {
public:
    int dp1(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        int offset = n + 1;

        cost.insert(cost.begin(), 0);
        time.insert(time.begin(), 0);

        // dp[i][diff]: the minimum amount of money to paint first i walls with cost difference between paid and free painter as diff
        vector<vector<int>> dp(n + 1, vector<int>(2 * n + 2, INT_MAX / 2));
        dp[0][0 + offset] = 0;

        for (int i = 0; i < n; ++i) {
            for (int diff = -n; diff <= n; ++diff) {
                // free
                dp[i + 1][diff - 1 + offset] = std::min(dp[i + 1][diff - 1 + offset], dp[i][diff  + offset]);

                // paid
                dp[i + 1][std::min(diff + time[i + 1], n) + offset] = std::min(dp[i + 1][std::min(diff + time[i + 1], n) + offset], dp[i][diff + offset] + cost[i + 1]);
            }
        }

        int ret = INT_MAX;
        for (int diff = 0; diff <= n; ++diff) {
            ret = std::min(ret, dp[n][diff + offset]);
        }

        return ret;
    }

    int dp2(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        cost.insert(cost.begin(), 0);
        time.insert(time.begin(), 0);

        // dp[i][j]: the minimum amount of money to paint j walls by considering the first i worker
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MAX / 2));
        dp[0][0] = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= n; ++j) {
                dp[i + 1][j] = std::min(dp[i + 1][j], dp[i][j]);

                int jj = std::min(j + 1 + time[i + 1], n);
                dp[i + 1][jj] = std::min(dp[i + 1][jj], dp[i][j] + cost[i + 1]);
            }
        }

        return dp[n][n];
    }

    int paintWalls(vector<int>& cost, vector<int>& time) {
        //return dp1(cost, time);
        return dp2(cost, time);
    }
};
