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
    int greedy1(vector<vector<int>>& pairs) {
        // 435. Non-overlapping Intervals

        std::sort(pairs.begin(), pairs.end(), [](const auto& p1, const auto& p2) { return p1[1] < p2[1]; });

        int n = pairs.size();

        int ret = 0;
        for (int i = 0; i < n; ) {
            int j = i + 1;
            for (; j < n && pairs[i][1] >= pairs[j][0]; ++j) {
                ;
            }
            i = j;

            ++ret;
        }

        return ret;
    }

    // Time: O(n)
    int greedy2(vector<vector<int>>& pairs) {
        // 435. Non-overlapping Intervals

        std::sort(pairs.begin(), pairs.end(), [](const auto& p1, const auto& p2) { return p1[0] < p2[0]; });

        int ret = 0;
        int far = INT_MIN;
        for (const auto& pair : pairs) {
            if (far < pair[0]) {
                far = pair[1];
                ++ret;
            }
            else if (pair[1] < far) {
                far = pair[1];
            }
        }

        return ret;
        return ret;
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        //return dynamicProgramming(pairs);
        //return greedy1(pairs);
        return greedy2(pairs);
    }
};
