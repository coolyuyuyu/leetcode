class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size(), n = mat.empty() ? 0 : mat[0].size();

        vector<pair<int, int>> indexes(m * n + 1);
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                indexes[mat[r][c]] = {r, c};
            }
        }

        vector<int> rowCnts(m, 0), colCnts(n, 0);
        for (int ret = 0; ret < arr.size(); ++ret) {
            const auto& [r, c] = indexes[arr[ret]];
            if (++rowCnts[r] == n) {
                return ret;
            }
            if (++colCnts[c] == m) {
                return ret;
            }
        }

        __builtin_unreachable();
        return -1;
    }
};
