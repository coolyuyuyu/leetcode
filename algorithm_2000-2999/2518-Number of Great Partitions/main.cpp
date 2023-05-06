class Solution {
public:
    int M = 1e9 + 7;

    int countPartitions(vector<int>& nums, int k) {
        if (accumulate(nums.begin(), nums.end(), 0LL) < (2 * k)) {
            return 0;
        }

        int n = nums.size();

        nums.insert(nums.begin(), 0);

        vector<vector<int>> dp(n + 1, vector<int>(k));
        dp[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < k; ++j) {
                dp[i][j] = dp[i - 1][j];
                if (nums[i] <= j) {
                    dp[i][j] += dp[i - 1][j - nums[i]];
                }
                dp[i][j] %= M;
            }
        }

        int t = 1;
        for (int i = 0; i < n; ++i) {
            t *= 2;
            t %= M;
        }

        for (int j = 0; j < k; ++j) {
            t -= ((2 * dp[n][j]) % M);
            t = (t + M) % M;
        }

        return t;
    }
};

// assumption: sum of elements >= 2 * k

// dp[i][j]: from the first i elements, the number of partitions such that sum of group A is j
// dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i]]

// the number of partitions such that sum of group A >= k
// => 2^n - sum(dp[n][0], dp[n][1], dp[n][2], ... dp[n][k - 1])

// the number of great partitions
// => 2^n - sum(dp[n][0], dp[n][1], dp[n][2], ... dp[n][k - 1]) - (the number of partitions such that sum of group A >= k && sum of group B < k)

// the number of partitions such that sum of group A >= k && sum of group B < k
// => the number of partitions such that sum of group A < k
