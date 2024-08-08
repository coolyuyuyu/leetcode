class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        unordered_map<int, int> cnts[n];
        for (const auto& p : pick) {
            int x = p[0], y = p[1];
            ++cnts[x][y];
        }

        int ret = 0;
        for (int i = 0; i < n; ++i) {
            for (const auto& [_, cnt] : cnts[i]) {
                if (cnt > i) {
                    ++ret;
                    break;
                }
            }
        }

        return ret;
    }
};
