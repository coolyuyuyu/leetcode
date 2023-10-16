class Solution {
public:
    // Time: O(n^2)
    int dp1(vector<int>& cost, vector<int>& time) {
        int n = cost.size();

        cost.insert(cost.begin(), 0);
        time.insert(time.begin(), 0);

        // dp[i][j]: the minimum amount of money required to paint walls[1:i] with time difference between paid and free printer as j
        int OFFSET = n + 1;
        int dp[n + 1][2 * n + 2];
        for (int i = 0; i <= n; ++i) {
            for (int j = -n; j <= n; ++j) {
                dp[i][j + OFFSET] = INT_MAX / 2;
            }
        }
        dp[0][0 + OFFSET] = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = -n; j <= n; ++j) {
                int jj = std::min(n, j + time[i + 1]);
                dp[i + 1][jj + OFFSET] = std::min(dp[i + 1][jj + OFFSET], dp[i][j + OFFSET] + cost[i + 1]); // paid
                dp[i + 1][j - 1 + OFFSET] = std::min(dp[i + 1][j - 1 + OFFSET], dp[i][j + OFFSET]); // free
            }
        }

        int ret = INT_MAX;
        for (int j = 0; j <= n; ++j) {
            ret = std::min(ret, dp[n][j + OFFSET]);
        }

        return ret;
    }

    int dp2(vector<int>& cost, vector<int>& time) {
        int n = cost.size();

        cost.insert(cost.begin(), 0);
        time.insert(time.begin(), 0);

        // if paid painter paints walls[i], overall 1 + times[i] walls can be painted with cost[i]
        // dp[i][j]: the minimum amount of money required to paint j walls by considering walls[1:i]
        int dp[n + 1][n + 1];
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= n; ++j) {
                dp[i][j] = INT_MAX / 2;
            }
        }
        dp[0][0] = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= n; ++j) {
                dp[i + 1][j] = std::min(dp[i + 1][j], dp[i][j]);

                int jj = std::min(n, j + 1 + time[i + 1]);
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
