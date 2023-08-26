class Solution {
public:
    // Time: O(n^2)
    int dynamicProgramming(vector<vector<int>>& pairs) {
        std::sort(pairs.begin(), pairs.end(), [](const auto& p1, const auto& p2) { return p1[1] < p2[1]; });

        int n = pairs.size();

        // dp[i]: length longest chain ending at i
        vector<int> dp(n);

        int ret = 0;
        for (int i = 0; i < n; ++i) {
            dp[i] = 1;
            for (int j = 0; j < i && pairs[j][1] < pairs[i][0]; ++j) {
                dp[i] = std::max(dp[i], 1 + dp[j]);
            }

            ret = std::max(ret, dp[i]);
        }

        return ret;
    }

    // Time: O(n)
    int greedy(vector<vector<int>>& pairs) {
        // 435. Non-overlapping Intervals

        std::sort(pairs.begin(), pairs.end(), [](const auto& p1, const auto& p2) {
            return p1[1] < p2[1];
        });

        int n = pairs.size();

        int ret = 0;
        for (int i = 0; i < n;) {
            int j;
            for (j = i + 1; j < n && pairs[i][1] >= pairs[j][0]; ++j) {
                ;
            }
            ++ret;
            i = j;
        }

        return ret;
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        return dynamicProgramming(pairs);
        //return greedy(pairs);
    }
};
