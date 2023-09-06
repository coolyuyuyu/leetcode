class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        int minDiff = -5000, maxDiff = 5000;
        int offset = 0 - minDiff;

        // dp[diff]: the maximum left support such that diff = left height - right height
        int dp[maxDiff - minDiff + 1];
        for (int diff = minDiff; diff <= maxDiff; ++diff) {
            dp[diff + offset] = INT_MIN;
        }
        dp[0 + offset] = 0;


        for (int rod : rods) {
            int tmp[maxDiff - minDiff + 1];
            memcpy(tmp, dp, sizeof(dp));
            for (int diff = minDiff; diff <= maxDiff; ++diff) {
                if (diff + rod <= maxDiff) {
                    dp[diff + rod + offset] = std::max(dp[diff + rod + offset], tmp[diff + offset] + rod);
                }
                if (minDiff <= diff - rod) {
                    dp[diff - rod + offset] = std::max(dp[diff - rod + offset], tmp[diff + offset]);
                }
            }
        }
        
        return dp[0 + offset];
    }
};
