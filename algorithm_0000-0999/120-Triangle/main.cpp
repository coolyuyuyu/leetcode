class Solution {
public:
    // Space: O(m^2)
    int dp1(const vector<vector<int>>& triangle) {
        int m = triangle.size();

        vector<vector<int>> dp(m);
        dp[0].push_back(triangle[0][0]);
        for (int i = 1; i < m; ++i) {
            int n = i + 1;
            dp[i].resize(i + 1);
            dp[i][0] = dp[i - 1][0] + triangle[i][0];
            for (int j = 1; (j + 1) < n; ++j) {
                dp[i][j] = std::min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
            }
            dp[i][n - 1] = dp[i - 1][n - 2] + triangle[i][n - 1];
        }

        return *std::min_element(dp[m - 1].begin(), dp[m - 1].end());
    }

    // Space: O(m)
    int dp2(const vector<vector<int>>& triangle) {
        int m = triangle.size();

        vector<int> dp(m);
        dp[0] = triangle[0][0];
        for (int i = 1; i < m; ++i) {
            int n = i + 1;
            dp[n - 1] = dp[n - 2] + triangle[i][n - 1];
            for (int j = i; 1 < j--;) {
                dp[j] = std::min(dp[j - 1], dp[j]) + triangle[i][j];
            }
            dp[0] = dp[0] + triangle[i][0];
        }

        return *std::min_element(dp.begin(), dp.end());
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        //return dp1(triangle);
        return dp2(triangle);
    }
};
