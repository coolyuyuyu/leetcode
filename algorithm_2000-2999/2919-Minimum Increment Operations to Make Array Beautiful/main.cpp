class Solution {
public:
    // Time: O(n), Space: O(n)
    long long dp1(vector<int>& nums, int k) {
        int n = nums.size();

        // dp[i]: the minimum number of increment operations needed to make nums[0:i] beautiful
        long long dp[n];
        dp[0] = std::max(k - nums[0], 0);
        dp[1] = std::max(k - nums[1], 0);
        dp[2] = std::max(k - nums[2], 0);
        for (int i = 3; i < n; ++i) {
            dp[i] = std::min({dp[i - 3], dp[i - 2], dp[i - 1]}) + std::max(k - nums[i], 0);
        }

        return std::min({dp[n - 3], dp[n - 2], dp[n - 1]});
    }

    // Time: O(n), Space: O(1)
    long long dp2(vector<int>& nums, int k) {
        int n = nums.size();

        // dp[i]: the minimum number of increment operations needed to make nums[0:i] beautiful
        long long x = std::max(k - nums[0], 0);
        long long y = std::max(k - nums[1], 0);
        long long z = std::max(k - nums[2], 0);
        for (int i = 3; i < n; ++i) {
            long long tmp = x;
            x = y;
            y = z;
            z = std::min({tmp, x, y}) + std::max(k - nums[i], 0);
        }

        return std::min({x, y, z});
    }

    long long minIncrementOperations(vector<int>& nums, int k) {
        //return dp1(nums, k);
        return dp2(nums, k);
    }
};
