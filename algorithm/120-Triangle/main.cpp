class Solution {
public:
    // Space(m, n) = m * n
    int minimumTotalV1(const vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle.size());
        dp.front() = triangle.front();

        for (size_t row = 1; row < triangle.size(); ++row) {
            size_t colCnt = row + 1;
            dp[row].resize(colCnt);

            dp[row][0] = dp[row - 1].front() + triangle[row].front();
            for (size_t col = 1; col < colCnt; ++col) {
                dp[row][col] = triangle[row][col];
                dp[row][col] += min(dp[row - 1][col - 1], dp[row - 1][col]);
            }
            dp[row].back() = dp[row - 1].back() + triangle[row].back();
        }

        return *min_element(dp.back().begin(), dp.back().end());
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        assert(!triangle.empty());

        return minimumTotalV1(triangle);
    }
};