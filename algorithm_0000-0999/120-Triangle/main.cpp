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

    // Space(m, n) = n
    int minimumTotalV2(const vector<vector<int>>& triangle) {
        vector<int> dp(triangle.size(), 0);
        dp.front() = triangle.front().front();
        for (size_t row = 1; row < triangle.size(); ++row) {
            size_t colCnt = row + 1;
            dp[colCnt - 1] = dp[colCnt - 2] + triangle[row][colCnt - 1];
            for (size_t col = colCnt - 1; 1 < col--;) {
                dp[col] = min(dp[col - 1], dp[col]) + triangle[row][col];
            }
            dp[0] = dp[0] + triangle[row][0];
        }

        return *min_element(dp.begin(), dp.end());
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        assert(!triangle.empty());

        //return minimumTotalV1(triangle);

        return minimumTotalV2(triangle);
    }
};