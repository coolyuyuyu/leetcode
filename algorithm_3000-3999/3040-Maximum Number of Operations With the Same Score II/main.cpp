class Solution {
public:
    int maxOperations(vector<int>& nums, int score) {
        int n = nums.size();

        // dp[lft][rht]: the maximum number of operations that can be performed from nums[lft:rht]
        int dp[n][n];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dp[i][j] = 0;
            }
        }
        // len = 2
        for (int i = 0; i + 1 < n; ++i) {
            dp[i][i + 1] = (nums[i] + nums[i + 1] == score ? 1 : 0);
        }
        for (int len = 3; len <= n; ++len) {
            for (int lft = 0, rht = lft + len - 1; rht < n; ++lft, ++rht) {
                dp[lft][rht] = std::max({
                    (nums[lft] + nums[lft + 1] == score ? dp[lft + 2][rht] + 1 : 0),
                    (nums[lft] + nums[rht] == score ? dp[lft + 1][rht - 1] + 1 : 0),
                    (nums[rht - 1] + nums[rht] == score ? dp[lft][rht - 2] + 1 : 0),
                });
            }
        }

        return dp[0][n - 1];
    }
    int maxOperations(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> scores = {nums[0] + nums[1], nums[0] + nums[n - 1], nums[n - 2] + nums[n - 1]};

        int ret = 0;
        for (int score : scores) {
            ret = std::max(ret, maxOperations(nums, score));
        }

        return ret;
    }
};
