class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int m = ring.size(), n = key.size();
        unordered_map<int, vector<int>> char2indexes;
        for (int i = 0; i < m; ++i) {
            char2indexes[ring[i]].push_back(i);
        }

        //dp[i][idx] the minimum number of steps to spell key[0:i] and the key[i] is at the idx of ring
        int dp[n][m];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                dp[i][j] = INT_MAX;
            }
        }
        for (int idx : char2indexes[key[0]]) {
            dp[0][idx] = std::min(idx, m - idx) + 1;
        }

        for (int i = 1; i < n; ++i) {
            for (int cur : char2indexes[key[i]]) {
                for (int pre : char2indexes[key[i - 1]]) {
                    int diff = std::abs(cur - pre);
                    dp[i][cur] = std::min({dp[i][cur], dp[i - 1][pre] + diff + 1, dp[i - 1][pre] + m - diff + 1});
                }
            }
        }

        int ret = INT_MAX;
        for (int idx : char2indexes[key[n - 1]]) {
            ret = std::min(ret, dp[n - 1][idx]);
        }

        return ret;
    }
};
