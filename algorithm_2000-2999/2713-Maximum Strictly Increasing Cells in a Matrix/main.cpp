class Solution {
public:
    int maxIncreasingCells(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat.empty() ? 0 : mat[0].size();

        vector<tuple<int, int, int>> cells;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                cells.emplace_back(mat[r][c], r, c);
            }
        }
        std::sort(cells.begin(), cells.end());

        // dpRow[r]: dp for the r-th row
        // dpRow[r][v]: condsidering r-th row, the maximum number of cells can be visited and reaching here where the corresponding cell value is v
        vector<map<int, int>> dpRow(m, map<int, int>({{INT_MIN, 0}}));
        vector<map<int, int>> dpCol(n, map<int, int>({{INT_MIN, 0}}));

        int ret = 0;
        for (const auto& [v, r, c] : cells) {
            auto itrRow = dpRow[r].rbegin();
            if (itrRow->first == v) {
                ++itrRow;
            }

            auto itrCol = dpCol[c].rbegin();
            if (itrCol->first == v) {
                ++itrCol;
            }

            int len = 1 + std::max(itrRow->second, itrCol->second);
            dpRow[r][v] = std::max(dpRow[r][v], len);
            dpCol[c][v] = std::max(dpCol[c][v], len);

            ret = std::max(ret, len);
        }

        return ret;
    }
};
