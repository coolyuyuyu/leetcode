class Solution {
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid.empty() ? 0 : grid[0].size();

        vector<vector<unordered_set<int>>> TL(m, vector<unordered_set<int>>(n)), BR(m, vector<unordered_set<int>>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i > 0 && j > 0) {
                    TL[i][j].insert(TL[i - 1][j - 1].begin(), TL[i - 1][j - 1].end());
                }
                TL[i][j].insert(grid[i][j]);
            }
        }
        for (int i = m; 0 < i--;) {
            for (int j = n; 0 < j--;) {
                if (i + 1 < m && j + 1 < n) {
                    BR[i][j].insert(BR[i + 1][j + 1].begin(), BR[i + 1][j + 1].end());
                }
                BR[i][j].insert(grid[i][j]);
            }
        }

        vector<vector<int>> ret(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int a = 0, b = 0;
                if (i > 0 && j > 0) {
                    a = TL[i - 1][j - 1].size();
                }
                if (i + 1 < m && j + 1 < n) {
                    b = BR[i + 1][j + 1].size();
                }
                ret[i][j] = abs(a - b);
            }
        }

        return ret;
    }
};
