class Solution {
public:
    // Time: O(n^2), TLE
    int dynamicProgramming(vector<vector<int>>& envelopes) {
        int n = envelopes.size();

        std::sort(envelopes.begin(), envelopes.end(), [&](const auto& e1, const auto& e2){ return e1[0] < e2[0]; });

        // dp[i]: the maximum number of envelopes you can Russian doll from envelopes[0:i] and envelopes[i] is the lagrest of doll
        int dp[n];
        std::fill(dp, dp + n, 1);

        int ret = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i && envelopes[j][0] < envelopes[i][0]; ++j) {
                if (envelopes[j][1] < envelopes[i][1]) {
                    dp[i] = std::max(dp[i], dp[j] + 1);
                }
            }
            ret = std::max(ret, dp[i]);
        }

        return ret;
    }

    // Time: O(nlogn)
    int greedy(vector<vector<int>>& envelopes) {
        int n = envelopes.size();

        std::sort(envelopes.begin(), envelopes.end(), [&](const auto& e1, const auto& e2){ return (e1[0] < e2[0]) || (e1[0] == e2[0] && e1[1] > e2[1]); });

        // dp[i]: the maximum number of envelopes you can Russian doll from envelopes[0:i] and envelopes[i] is the lagrest of doll
        int dp[n];
        std::fill(dp, dp + n, 1);

        vector<int> lis; // longest increasing subsequence
        for (const auto& envelope : envelopes) {
            if (lis.empty() || lis.back() < envelope[1]) {
                lis.push_back(envelope[1]);
            }
            else {
                auto itr = std::lower_bound(lis.begin(), lis.end(), envelope[1]);
                *itr = envelope[1];
            }
        }

        return lis.size();
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
       //return dynamicProgramming(envelopes);
       return greedy(envelopes);
    }
};
