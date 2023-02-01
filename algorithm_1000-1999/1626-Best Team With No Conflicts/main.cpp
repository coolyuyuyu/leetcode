class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();

        vector<int> indexes(n);
        std::iota(indexes.begin(), indexes.end(), 0);
        std::sort(indexes.begin(), indexes.end(), [&](int i1, int i2) { return (ages[i1] < ages[i2]) || (ages[i1] == ages[i2] && scores[i1] < scores[i2]); });

        int ret = 0;

        //dp[i]: highest overall score of increasing subsequence[0:i-1] and scores[i]
        vector<int> dp(n);
        for (int i = 0; i < n; ++i) {
            dp[i] = scores[indexes[i]];
            for (int j = 0; j < i; ++j) {
                if (scores[indexes[j]] <= scores[indexes[i]]) {
                    dp[i] = std::max(dp[i], dp[j] + scores[indexes[i]]);
                }
            }
            ret = std::max(ret, dp[i]);
        }

        return ret;
    }
};
