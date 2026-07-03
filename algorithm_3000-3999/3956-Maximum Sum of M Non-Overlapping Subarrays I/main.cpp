class Solution {
public:
    long long maximumSum(vector<int>& nums, int m, int l, int r) {
        int n = nums.size();

        nums.insert(nums.begin(), 0);

        long long presums[n + 1];
        presums[0] = nums[0];
        for (int i = 1; i <= n; ++i) {
            presums[i] = presums[i - 1] + nums[i];
        }

        // maximum total sum from first i numbers and j non-overlapping subarrays
        long long dp[n + 1][m + 1];
        dp[0][0] = 0;
        for (int j = 1; j <= m; ++j) {
            dp[0][j] = LLONG_MIN / 2;
        }
        for (int i = 1; i <= n; ++i) {
            dp[i][0] = 0;
        }

        for (int j = 1; j <= m; ++j) {
            deque<int> dq;
            for (int i = 1; i <= n; ++i) {
                dp[i][j] = dp[i - 1][j];

                // dp[i][j] = max(dp[i - k][j - 1] + presums[i] - presums[i - k]) for k in [l, r]
                // => dp[i][j] = presums[i] + max(dp[i - k][j - 1] - presums[i - k]) for k in [l, r]

                // l <= k <= r
                // i - r <= i - k <= i - l

                // assume i - k: idx
                // dp[i][j] = presums[i] + max(dp[idx][j - 1] - presums[idx]) for idx in [i-r, i-l]
                if (!dq.empty() && dq.front() <= i - r - 1) {
                    dq.pop_front();
                }
                if (i - l >= 0) {
                    int idx = i - l;
                    while (!dq.empty() && dp[dq.back()][j - 1] - presums[dq.back()] <= dp[idx][j - 1] - presums[idx]) {
                        dq.pop_back();
                    }
                    dq.push_back(idx);
                }
                if (!dq.empty()) {
                    int idx = dq.front();
                    dp[i][j] = std::max(dp[i][j], dp[idx][j - 1] + presums[i] - presums[idx]);
                }
            }
        }

        long long ret = LLONG_MIN;
        for (int j = 1; j <= m; ++j) {
            ret = std::max(ret, dp[n][j]);
        }

        return ret;
    }
};
