class Solution {
public:
    bool topdnDFS(vector<int>& nums) {
        int n = nums.size();

        int presum[n];
        std::partial_sum(nums.begin(), nums.end(), presum);
        std::function<int(int, int)> sum = [&](int lo, int hi) {
            return presum[hi] - (0 < lo ? presum[lo - 1] : 0);
        };

        // dp[i][j]: the maximum score the player can get from nums[i:j]
        int dp[n][n];
        for (int lft = 0; lft < n; ++lft) {
            for (int rht = lft; rht < n; ++rht) {
                dp[lft][rht] = -1;
            }
        }
        std::function<int(int, int)> f = [&](int lft, int rht) {
            int& ret = dp[lft][rht];
            if (0 <= ret) {
                return ret;
            }

            if (lft == rht) {
                return ret = nums[lft];
            }
            // return ret = std::max(nums[lft] + sum(lft + 1, rht) - f(lft + 1, rht), sum(lft, rht - 1) - f(lft, rht - 1) + nums[rht]);
            return ret = sum(lft, rht) - std::min(f(lft + 1, rht), f(lft, rht - 1));
        };

        return (f(0, n - 1) * 2 >= sum(0, n - 1));
    }

    bool btmupDP(vector<int>& nums) {
        int n = nums.size();

        int presum[n];
        std::partial_sum(nums.begin(), nums.end(), presum);
        std::function<int(int, int)> sum = [&](int lo, int hi) {
            return presum[hi] - (0 < lo ? presum[lo - 1] : 0);
        };

        // dp[i][j]: the maximum score the player can get from nums[i:j]
        int dp[n][n];
        for (int i = 0; i < n; ++i) {
            dp[i][i] = nums[i];
        }
        for (int len = 2; len <= n; ++len) {
            for (int lft = 0, rht = lft + len - 1; rht < n; ++lft, ++rht) {
                // dp[lft][rht] = std::max(nums[lft] + sum(lft + 1, rht) - dp[lft + 1][rht], sum(lft, rht - 1) - dp[lft][rht - 1] + nums[rht]);
                dp[lft][rht] = sum(lft, rht) - std::min(dp[lft + 1][rht], dp[lft][rht - 1]);
            }
        }

        return (dp[0][n - 1] * 2 >= sum(0, n - 1));
    }

    bool predictTheWinner(vector<int>& nums) {
        return topdnDFS(nums);
        //return btmupDP(nums);
    }
};
