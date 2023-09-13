class Solution {
public:
    // Time: O(n^2)
    int dynamicProgramming(vector<vector<int>>& envelopes) {
        int n = envelopes.size();

        std::sort(
            envelopes.begin(), envelopes.end(),
            [](const auto& e1, const auto& e2) {
                return e1[0] < e2[0];
            });

        // dp[i]: the maximum number of envelopes from envelopes[0:i] and envelopes[i] is the largest
        int dp[n];
        for (int i = 0; i < n; ++i) {
            dp[i] = 1;
            for (int j = 0; j < i; ++j) {
                if (envelopes[j][0] < envelopes[i][0] && envelopes[j][1] < envelopes[i][1]) {
                    dp[i] = std::max(dp[i], dp[j] + 1);
                }
            }
        }

        int ret = 0;
        for (int i = 0; i < n; ++i) {
            ret = std::max(ret, dp[i]);
        }

        return ret;
    }

    // Time: O(nlogn)
    int greedy(vector<vector<int>>& envelopes) {
        int n = envelopes.size();

        std::sort(
            envelopes.begin(), envelopes.end(),
            [](const auto& e1, const auto& e2) {
                return (e1[0] < e2[0]) || (e1[0] == e2[0] && e1[1] > e2[1]);
            });

        vector<int> lis; // longest increasing subsequence
        for (int i = 0; i < n; ++i) {
            if (lis.empty() || lis.back() < envelopes[i][1]) {
                lis.push_back(envelopes[i][1]);
            }
            else {
                auto itr = std::lower_bound(lis.begin(), lis.end(), envelopes[i][1]);
                *itr = envelopes[i][1];
            }
        }

        return lis.size();
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        //return dynamicProgramming(envelopes);
        return greedy(envelopes);
    }
};
