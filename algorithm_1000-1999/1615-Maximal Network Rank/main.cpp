class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> cnts(n);
        set<pair<int, int>> connected;
        for (const auto& road : roads) {
            int a = road[0], b = road[1];
            if (a > b) {
                std::swap(a, b);
            }
            ++cnts[a];
            ++cnts[b];
            connected.emplace(a, b);
        }

        int ret = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int rank = cnts[i] + cnts[j] - (connected.find({i, j}) == connected.end() ? 0 : 1);
                ret = std::max(ret, rank);
            }
        }

        return ret;
    }
};
