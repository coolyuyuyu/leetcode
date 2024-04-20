class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int m = land.size(), n = land.empty() ? 0 : land[0].size();

        vector<vector<int>> ret;
        for (int t = 0; t < m; ++t) {
            for (int l = 0; l < n; ++l) {
                if (land[t][l] == 0) { continue; }

                int b = t, r = l;
                while (b + 1 < m && land[b + 1][l] == 1) {
                    ++b;
                }
                while (r + 1 < n && land[b][r + 1] == 1) {
                    ++r;
                }
                for (int x = t; x <= b; ++x) {
                    for (int y = l; y <= r; ++y) {
                        land[x][y] = 0;
                    }
                }

                ret.push_back({t, l, b, r});
            }
        }

        return ret;
    }
};
