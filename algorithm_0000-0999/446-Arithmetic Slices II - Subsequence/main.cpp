class Solution {
public:
    // Time: O(n^2)
    int dp1(vector<int>& nums) {
        int n = nums.size();

        // dp[i][diff]: the number of arithmetic sequence from nums[0:i]. The length of arithmetic sequence is >= 2 and ending at nums[i].
        unordered_map<long, int> dp[n];

        int ret = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                long diff = 1L * nums[i] - nums[j];
                dp[i][diff] += (dp[j][diff] + 1);
                ret += dp[j][diff];
            }
        }

        return ret;
    }

    // Time: O(n^3)
    int dp2(vector<int>& nums) {
        int n = nums.size();

        // dp[j][i]: the number of arithmetic sequence from nums[0:i]. The length of arithmetic sequence is >= 3, and the last 2 elements are nums[j] and nums[i]
        int dp[n][n];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                dp[j][i] = 0;
            }
        }

        unordered_map<int, vector<int>> m;
        for (int i = 0; i < n; ++i) {
            m[nums[i]].push_back(i);
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                long val = 2L * nums[j] - nums[i];
                if (val < INT_MIN || INT_MAX < val) { continue; }
                for (int k : m[val]) {
                    if (k >= j) {
                        break;
                    }
                    dp[j][i] += (dp[k][j] + 1);
                }
            }
        }

        int ret = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                ret += dp[j][i];
            }
        }

        return ret;
    }

    int numberOfArithmeticSlices(vector<int>& nums) {
        //return dp1(nums);
        return dp2(nums);
    }
};
