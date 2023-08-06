class Solution {
public:
    bool canSplitArray(vector<int>& nums, int m) {
        int n = nums.size();
        if (n <= 2) {
            return true;
        }

        vector<int> presum(n);
        std::partial_sum(nums.begin(), nums.end(), presum.begin());
        std::function<int(int, int)> sum = [&](int lo, int hi) {
            return presum[hi] - (0 < lo ? presum[lo - 1] : 0);
        };

        // dp[i][j]: nums[i:j] is splittable
        vector<vector<bool>> dp(n, vector<bool>(n));
        for (int i = 0; i < n; ++i) {
            dp[i][i] = true;
        }
        for (int len = 2; len <= n; ++len) {
            for (int i = 0, j = i + len - 1; j < n; ++i, ++j) {
                dp[i][j] = false;
                if (sum(i, j) < m) {
                    continue;
                }
                for (int k = i; k < j; ++k) {
                    if (dp[i][k] && dp [k + 1][j]) {
                        dp[i][j] = true;
                        break;
                    }
                }
            }
        }

        return dp[0][n - 1];
    }
};
