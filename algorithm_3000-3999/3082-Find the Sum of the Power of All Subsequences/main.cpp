class Solution {
public:
    int M = 1e9 + 7;

    int sumOfPower(vector<int>& nums, int k) {
        int n = nums.size();
        nums.insert(nums.begin(), 0);

        // dp[i][s][j]: the number of length j subsequences from nums[1:i], which sum is equal to s
        int dp[n + 1][k + 1][n + 1];
        for (int i = 0; i <= n; ++i) {
            for (int s = 0; s <= k; ++s) {
                for (int j = 0; j <= n; ++j) {
                    dp[i][s][j] = 0;
                }
            }
        }
        dp[0][0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int s = 0; s <= k; ++s) {
                for (int j = 0; j <= i; ++j) {
                    if (i - 1 >= j) {
                        dp[i][s][j] += dp[i - 1][s][j];
                    }
                    if (s - nums[i] >= 0 && j - 1 >= 0) {
                        dp[i][s][j] += dp[i - 1][s - nums[i]][j - 1];
                    }
                    dp[i][s][j] %= M;
                }
            }
        }

        int power2s[n + 1];
        power2s[0] = 1;
        for (int i = 1; i <= n; ++i) {
            power2s[i] = (power2s[i - 1] * 2) % M;
        }

        int ret = 0;
        for (int j = 1; j <= n; ++j) {
            ret += 1LL * dp[n][k][j] * power2s[n - j] % M;
            ret %= M;
        }

        return ret;
    }
};
