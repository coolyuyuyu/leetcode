class Solution {
public:
    long long M = 1e9 + 7;

    // count the number of subsequence with length = len and its power is (nums[b] - nums[a])
    long long countSubsequence(vector<int>& nums, int len, int a, int b) {
        int n = nums.size();
        int d = nums[b] - nums[a];

        // dp1[i][j] the number of j-element-long subsequence from nums[0:a], ending at nums[i], power > d
        long long dp1[n][len + 1];
        for (int i = 0; i <= a; ++i) {
            for (int j = 1; j <= len; ++j) {
                dp1[i][j] = 0;
            }
        }
        for (int i = 0; i <= a; ++i) {
            dp1[i][1] = 1;
        }
        for (int i = 0; i <= a; ++i) {
            for (int j = 2; j <= len; ++j) {
                for (int k = 0; k < i && nums[i] - nums[k] > d; ++k) {
                    dp1[i][j] += dp1[k][j - 1];
                    dp1[i][j] %= M;
                }
            }
        }

        // dp2[i][j] the number of j-element-long subsequence from nums[b:], starting at nums[i], power >= d
        long long dp2[n][len + 1];
        for (int i = n - 1; i >= b; --i) {
            for (int j = 1; j <= len; ++j) {
                dp2[i][j] = 0;
            }
        }
        for (int i = n - 1; i >= b; --i) {
            dp2[i][1] = 1;
        }
        for (int i = n - 1; i >= b; --i) {
            for (int j = 2; j <= len; ++j) {
                for (int k = n - 1; k > i && nums[k] - nums[i] >= d; --k) {
                    dp2[i][j] += dp2[k][j - 1];
                    dp2[i][j] %= M;
                }
            }
        }

        long long ret = 0;
        for (int lft = 1, rht = len - 1; lft < len; ++lft, --rht) {
            ret += dp1[a][lft] * dp2[b][rht];
            ret %= M;
        }

        return ret;
    }

    int sumOfPowers(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        long long ret = 0;
        for (int a = 0; a < n; ++a) {
            for (int b = a + 1; b < n; ++b) {
                ret += (countSubsequence(nums, k, a, b) * (nums[b] - nums[a])) % M;
                ret %= M;
            }
        }

        return ret;
    }
};
