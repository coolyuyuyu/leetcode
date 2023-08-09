class Solution {
public:
    int dynamicProgramming(const vector<int>& nums, int m) {
        int n = nums.size();

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
        for (int i = 0, j = 1; j < n; ++i, ++j) {
            dp[i][j] = true;
        }
        for (int len = 3; len <= n; ++len) {
            for (int i = 0, j = i + len - 1; j < n; ++i, ++j) {
                dp[i][j] = (dp[i + 1][j] && m <= sum(i + 1, j)) || (dp[i][j - 1] && m <= sum(i, j - 1));
            }
        }

        return dp[0][n - 1];
    }

    int greedy(const vector<int>& nums, int m) {
        int n = nums.size();
        if (n <= 2) {
            return true;
        }

        for (int i = 1; i < n; ++i) {
            if (m <= (nums[i - 1] + nums[i])) {
                return true;
            }
        }

        return false;
    }

    bool canSplitArray(vector<int>& nums, int m) {
        //return dynamicProgramming(nums, m);
        return greedy(nums, m);
    }
};
