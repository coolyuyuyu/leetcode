class Solution {
public:
    int minimumIncrements(vector<int>& nums, vector<int>& target) {
        int n = nums.size(), m = target.size();

        nums.insert(nums.begin(), -1);

        // state: binary representation of subset of target
        // dp[i][state]: the minimum number of operations required so that subset state of target has at least one multiple in nums[1:i]
        int dp[n + 1][1 << m];
        for (int i = 0; i <= n; ++i) {
            for (int state = 0; state < (1 << m); ++state) {
                dp[i][state] = INT_MAX / 2;
            }
        }
        dp[0][0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int state = 0; state < (1 << m); ++state) {
                dp[i][state] = dp[i - 1][state];
                for (int subset = state; subset > 0; subset = (subset - 1) & state) {
                    long long l = 1;
                    for (int j = 0; j < m; ++j) {
                        if ((subset >> j) & 1) {
                            l = std::lcm<long long>(l, target[j]);
                        }
                    }

                    long long cost = nums[i] % l == 0 ? 0 : (l - nums[i] % l);
                    dp[i][state] = std::min<long long>(dp[i][state], dp[i - 1][state - subset] + cost);
                }
            }
        }

        return dp[n][(1 << m) - 1];
    }
};
