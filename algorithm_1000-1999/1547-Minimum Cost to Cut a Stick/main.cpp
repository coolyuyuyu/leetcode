class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        std::sort(cuts.begin(), cuts.end());
        cuts.insert(cuts.begin(), 0);
        cuts.insert(cuts.end(), n);
        int m = cuts.size();

        // dp[i][j]: the minimum total cost of the cuts for stick of ith cut position to jth cut position
        int dp[m + 1][m + 1];
        for (int i = 0; i < m; ++i) { // len = 2;
            dp[i][i + 1] = 0;
        }
        for (int len = 3; len <= m; ++len) {
            for (int i = 0, j = i + len - 1; j < m; ++i, ++j) {
                dp[i][j] = INT_MAX;
                for (int k = i + 1; k < j; ++k) {
                    dp[i][j] = std::min(dp[i][j], dp[i][k] + dp[k][j]);;
                }
                dp[i][j] += (cuts[j] - cuts[i]);
            }
        }

        return dp[0][m - 1];
    }
};
