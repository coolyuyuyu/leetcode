class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        int minDiff = -5000, maxDiff = 5000;
        int m = maxDiff - minDiff + 1;
        int OFFSET = 0 - minDiff;
        
        // dp[diff]: the largest possible left support of billboard such that diff = height of left - height of right
        int dp[m];
        for (int diff = minDiff; diff <= maxDiff; ++diff) {
            dp[diff + OFFSET] = INT_MIN;
        }
        dp[0 + OFFSET] = 0;
        for (int rod : rods) {
            int tmp[m];
            std::copy(dp, dp + m, tmp);
            for (int diff = minDiff; diff <= maxDiff; ++diff) {
                if (diff + rod <= maxDiff) {
                    dp[diff + rod +  + OFFSET] = std::max(dp[diff + rod +  + OFFSET], tmp[diff + OFFSET] + rod); // welded with left support
                }
                if (minDiff <= diff - rod) {
                    dp[diff - rod + OFFSET] = std::max(dp[diff - rod + OFFSET], tmp[diff + OFFSET]); // welded with right support
                }
            }
        }

        return dp[0 + OFFSET];
    }
};
