class Solution {
public:
    vector<long long> countBlackBlocks(int m, int n, vector<vector<int>>& coordinates) {
        vector<pair<int, int>> deltas = {{-1, -1}, {-1, 0}, {0, -1}, {0, 0}};

        std::function<long long(int, int)> encode = [&](int r, int c) {
            return static_cast<long long>(r) * n + c;
        };
        unordered_map<long long, int> cnts;
        for (const vector<int>& coordinate : coordinates) {
            int r = coordinate[0], c = coordinate[1];
            for (auto [deltaR, deltaC] : deltas) {
                int x = r + deltaR, y = c + deltaC;
                if (x < 0 || m <= (x + 1) || y < 0 || n <= (y + 1)) {
                    continue;
                }
                cnts[encode(x, y)]++;
            }
        }

        vector<long long> ret(5, 0);
        for (const auto& [_, cnt] : cnts) {
            ++ret[cnt];
        }
        ret[0] = static_cast<long long>(m - 1) * (n - 1) - ret[1] - ret[2] - ret[3] - ret[4];

        return ret;
    }
};
