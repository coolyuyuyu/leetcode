class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        int minDiff = -5000, maxDiff = 5000;
        int offset = 0 - minDiff;

        // dp[diff]: the maximum support of left length such that "left length - right right = diff"
        vector<int> dp(maxDiff - minDiff + 1, -1);
        dp[0 + offset] = 0;

        for (int rod : rods) {
            vector<int> tmp = dp;
            for (int diff = minDiff; diff <= maxDiff; ++diff) {
                if (tmp[diff + offset] == -1) {
                    continue;
                } 

                if (diff + rod + offset < dp.size()) {
                    dp[diff + rod + offset] = std::max(dp[diff + rod + offset], tmp[diff + offset] + rod);
                }

                if (0 <= diff - rod + offset) {
                    dp[diff - rod + offset] = std::max(dp[diff - rod + offset], tmp[diff + offset]);
                }
            }
        }

        return dp[0 + offset];
    }
};
