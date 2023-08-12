class Solution {
public:
    // Time: O(n^2)
    int dynamicProgramming(vector<vector<int>>& pairs) {
        std::sort(pairs.begin(), pairs.end(), [](const auto& p1, const auto& p2) {
            return p1[1] < p2[1];
        });

        int n = pairs.size();

        vector<int> dp(n, 1);
        int ret = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i; 0 < j--;) {
                if (pairs[j][1] < pairs[i][0]) {
                    dp[i] = std::max(dp[i], dp[j] + 1);
                }
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
        //return dynamicProgramming(pairs);
        return greedy(pairs);
    }
};
