class Solution {
public:
    // Space: O(m^2)
    int dp1(const vector<vector<int>>& triangle) {
        int m = triangle.size();

        vector<vector<int>> dp(m);
        dp[0].push_back(triangle[0][0]);
        for (int r = 1; r < m; ++r) {
            dp[r].resize(r + 1);
            for (int c = 0, n = r + 1; c < n; ++c) {
                dp[r][c] = std::min(c > 0 ? dp[r - 1][c - 1] : INT_MAX, c < r ? dp[r - 1][c] : INT_MAX) + triangle[r][c];
            }
        }

        return *std::min_element(dp[m - 1].begin(), dp[m - 1].end());ㄤ
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
