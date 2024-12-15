class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int m = nums.size(), n = queries.size();

        // dp[i]: from nums[0:i] the number of pairs of adjacent elements contains two numbers with same parity.
        int dp[m];
        dp[0] = 0;
        for (int i = 1; i < m; ++i) {
            dp[i] = dp[i - 1] + ((nums[i - 1] & 1) == (nums[i] & 1) ? 1 : 0);
        }

        vector<bool> ret(n);
        for (int i = 0; i < n; ++i) {
            ret[i] = (dp[queries[i][0]] == dp[queries[i][1]]);
        }

        return ret;
    }
};
