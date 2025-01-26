class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size();

        costs.insert(costs.begin(), {1});

        // dp[i][diff]: the minimum cost from costs[1:i] and the difference between city A and B is diff
        int dp[n + 1][2 * n + 1];
        int OFFSET = n;
        for (int i = 0; i <= n; ++i) {
            for (int diff = -n; diff <= n; ++diff) {
                dp[i][diff + OFFSET] = INT_MAX / 2;
            }
        }
        dp[0][0 + OFFSET] = 0;

        for (int i = 1; i <= n; ++i) {
            //cout << i << endl;
            int a = costs[i][0], b = costs[i][1];
            for (int diff = -n; diff <= n; ++diff) {

                if (diff - 1 >= -n) {
                    dp[i][diff + OFFSET] = dp[i - 1][diff - 1 + OFFSET] + a;
                }
                if (diff + 1 <= n) {
                    dp[i][diff + OFFSET] = std::min(dp[i][diff + OFFSET], dp[i - 1][diff + 1  + OFFSET] + b);
                }
            }
        }

        return dp[n][0 + OFFSET];
    }
};
