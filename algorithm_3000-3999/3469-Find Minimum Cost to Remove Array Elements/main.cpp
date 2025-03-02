class Solution {
public:
    int minCost(vector<int>& nums) {
        int n = nums.size();

        // dp[pre][cur]: the minimum cost required to remove all nums[pre] and nums[cur:]
        int dp[n + 1][n + 1];
        std::memset(dp, 0, sizeof(dp));
        std::function<int(int, int)> f = [&](int pre, int cur) {
            int& ret = dp[pre][cur];
            if (ret > 0) {
                return ret;
            }

            if (cur == n) {
                return ret = nums[pre];
            }
            else if (cur + 1 >= n) {
                return ret = std::max(nums[pre], nums[cur]);
            }

            ret = std::min({
                std::max(nums[pre], nums[cur]) + f(cur + 1, cur + 2),
                std::max(nums[pre], nums[cur + 1]) + f(cur, cur + 2),
                std::max(nums[cur], nums[cur + 1]) + f(pre, cur + 2),

            });
            return ret;
        };

        return f(0, 1);
    }
};
