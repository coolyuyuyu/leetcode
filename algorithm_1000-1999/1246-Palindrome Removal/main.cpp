class Solution {
public:
    int minimumMoves(vector<int>& arr) {
        int n = arr.size();

        arr.insert(arr.begin(), 0);

        //dp[i][j]: the minimum number of moves needed to remove all numbers from arr[i:j]
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        for (int len = 1; len <= n; ++len) {
            for (int i = 1, j = i + len - 1; j <= n; ++i, ++j) {
                dp[i][j] = dp[i][j - 1] + 1;
                for (int k = i; k <= j; ++k) {
                    if (arr[k] == arr[j]) {
                        dp[i][j] = std::min(dp[i][j], dp[i][k - 1] + std::max(1, dp[k + 1][j - 1]));
                    }
                }
            }
        }

        return dp[1][n];
    }
};
