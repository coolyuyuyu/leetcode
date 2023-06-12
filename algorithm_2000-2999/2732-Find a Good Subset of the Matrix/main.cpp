class Solution {
public:
    vector<int> goodSubsetofBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid.empty() ? 0 : grid[0].size();

        vector<vector<int>> rows(1 << n);
        for (int r = 0; r < m; ++r) {
            int num = 0;
            for (int c = 0; c < n; ++c) {
                num += (grid[r][c] << c);
            }

            if (num == 0) {
                return {r};
            }
            rows[num].push_back(r);
        }

        for (int i = 0; i < (1 << n); ++i) {
            for (int j = 0; j < (1 << n); ++j) {
                if ((i & j) == 0) {
                    if (i == j && 2 <= rows[i].size()) {
                        return {rows[i][0], rows[i][1]};
                    }
                    else if (rows[i].size() && rows[j].size()) {
                        auto p = std::minmax(rows[i][0], rows[j][0]);
                        return {p.first, p.second};
                    }
                }
            }
        }

        return {};
    }
};
