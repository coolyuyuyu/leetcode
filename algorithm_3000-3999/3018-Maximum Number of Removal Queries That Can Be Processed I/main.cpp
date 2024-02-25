class Solution {
public:
    int maximumProcessableQueries(vector<int>& nums, vector<int>& queries) {
        int m = nums.size(), n = queries.size();

        nums.insert(nums.begin(), 0);
        nums.push_back(0);

        // dp[i][j]: the maximum number of passed queries k when nums is cut down to nums[i:j]
        int dp[m + 2][m + 2];
        for (int i = 0; i < m + 2; ++i) {
            for (int j = 0; j < m + 2; ++j) {
                dp[i][j] = 0;
            }
        }
        for (int len = m; len >= 1; --len) {
            for (int i = 1, j = i + len - 1; j <= m; ++i, ++j) {
                int k;

                k = dp[i - 1][j];
                if (k < n && nums[i - 1] >= queries[k]) {
                    dp[i][j] = std::max(dp[i][j], dp[i - 1][j] + 1);
                }
                else {
                    dp[i][j] = std::max(dp[i][j], dp[i - 1][j]);
                }

                k = dp[i][j + 1];
                if (k < n && nums[j + 1] >= queries[k]) {
                    dp[i][j] = std::max(dp[i][j], dp[i][j + 1] + 1);
                }
                else {
                    dp[i][j] = std::max(dp[i][j], dp[i][j + 1]);
                }
            }
        }

        int ret = 0;
        for (int i = 1; i <= m; ++i) {
            int k = dp[i][i];
            if (k < n && nums[i] >= queries[k]) {
                ret = std::max(ret, k + 1);
            }
            else {
                ret = std::max(ret, k);
            }
        }

        return ret;
    }
};
