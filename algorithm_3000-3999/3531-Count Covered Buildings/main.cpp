class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        pair<int, int> rowMnMx[n + 1], colMnMx[n + 1];
        std::fill(rowMnMx, rowMnMx + n + 1, pair<int, int>{INT_MAX, INT_MIN});
        std::fill(colMnMx, colMnMx + n + 1, pair<int, int>{INT_MAX, INT_MIN});
        for (const auto& building : buildings) {
            int x = building[0], y = building[1];
            auto& [rmn, rmx] = rowMnMx[y];
            rmn = std::min(rmn, x), rmx = std::max(rmx, x);
            auto& [cmn, cmx] = colMnMx[x];
            cmn = std::min(cmn, y), cmx = std::max(cmx, y);
        }

        int ret = 0;
        for (const auto& building : buildings) {
            int x = building[0], y = building[1];
            auto& [rmn, rmx] = rowMnMx[y];
            rmn = std::min(rmn, x), rmx = std::max(rmx, x);
            auto& [cmn, cmx] = colMnMx[x];
            cmn = std::min(cmn, y), cmx = std::max(cmx, y);
            if (rmn < x && x < rmx && cmn < y && y < cmx) {
                ++ret;
            }
        }

        return ret;
    }
};
