class Solution {
public:
    // Time: O(n)
    int dp1(const vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }

        // 198. House Robber
        auto f = [&](std::vector<int>::const_iterator first, std::vector<int>::const_iterator last) {
            if (first == last) {
                return 0;
            }

            int rubN = 0, rubY = *first;
            for (auto itr = first + 1; itr != last; ++itr) {
                int tmpN = rubN, tmpY = rubY;
                rubN = std::max(tmpN, tmpY);
                rubY = tmpN + *itr;
            }

            return std::max(rubN, rubY);
        };

        return std::max(f(nums.begin() + 1, nums.end()), f(nums.begin(), nums.end() - 1));
    }

    // Time: O(n^2)
    int dp2(const vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }

        int n = nums.size();

        // dp[i][j]: the maximum amount of money you can rob from nums[i:j]
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            dp[i][i] = nums[i];
        }
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; (i + len - 1) < n; ++i) {
                int j = i + len - 1;
                dp[i][j] = std::max(dp[i + 1][j], nums[i] + (i + 2 <= j ? dp[i + 2][j] : 0));
            }
        }

        return std::max(dp[0][n - 2], dp[1][n - 1]);
    }

    int rob(vector<int>& nums) {
        //return dp1(nums);
        return dp2(nums);
    }
};
