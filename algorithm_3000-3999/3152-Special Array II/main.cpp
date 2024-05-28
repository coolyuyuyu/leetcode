class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int m = nums.size(), n = queries.size();

        // dp[i]: the number of break points from nums[0:i];
        int dp[m];
        dp[0] = 0;
        for (int i = 1; i < m; ++i) {
            dp[i] = dp[i - 1] + ((nums[i - 1] & 1) == (nums[i] & 1) ? 1 : 0);
        }

        vector<bool> ret(n);
        for (int j = 0; j < n; ++j) {
            ret[j] = (dp[queries[j][0]] == dp[queries[j][1]]);
        }

        return ret;
    }
};
