class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        int cnt[n];
        std::fill(cnt, cnt + n, 0);

        bool connected[n][n];
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                connected[i][j] = false;
            }
        }

        for (const auto& road : roads) {
            auto [a, b] = std::minmax(road[0], road[1]);
            ++cnt[a];
            ++cnt[b];
            connected[a][b] = true;
        }

        int ret = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int rank = cnt[i] + cnt[j] - (connected[i][j] ? 1 : 0);
                ret = std::max(ret, rank);
            }
        }

        return ret;
    }
};
