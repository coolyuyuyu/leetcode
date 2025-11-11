class Solution {
public:
    int maxTotalReward(vector<int>& rewardValues) {
        std::sort(rewardValues.begin(), rewardValues.end());

        int n = rewardValues.size();
        int m = 2 * rewardValues.back() - 1;
        rewardValues.insert(rewardValues.begin(), -1);

        // dp[i][s]: for the the rewardValues[1:i], is it possible to achieve total reward s?
        bool dp[n + 1][m + 1];
        dp[0][0] = true;
        for (int s = 1; s <= m; ++s) {
            dp[0][s] = false;
        }

        for (int i = 1; i <= n; ++i) {
            for (int s = 0; s <= m; ++s) {
                dp[i][s] = false;
                dp[i][s] |= dp[i - 1][s];
                if (s - rewardValues[i] < rewardValues[i] && rewardValues[i] <= s) {
                    dp[i][s] |= dp[i - 1][s - rewardValues[i]];
                }
            }
        }

        int ret = m;
        while (!dp[n][ret]) {
            --ret;
        }

        return ret;
    }
};
