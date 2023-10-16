class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = ages.size();

        int indexes[n];
        std::iota(indexes, indexes + n, 0);
        std::sort(indexes, indexes + n, [&](int i1, int i2) {
            return
                (ages[i1] < ages[i2]) ||
                (ages[i1] == ages[i2] && scores[i1] < scores[i2]); });

        // dp[i]: the highest overall score from teams[0:i] and teams[i] is included
        int dp[n];
        for (int i = 0; i < n; ++i) {
            dp[i] = scores[indexes[i]];
            for (int j = 0; j < i; ++j) {
                if (scores[indexes[j]] <= scores[indexes[i]]) {
                    dp[i] = std::max(dp[i], dp[j] + scores[indexes[i]]);
                }
            }
        }

        int ret = 0;
        for (int i = 0; i < n; ++i) {
            ret = std::max(ret, dp[i]);
        }

        return ret;
    }
};
