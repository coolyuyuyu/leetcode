class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        int m = n;

        int diffs[m][n];
        std::fill(&diffs[0][0], &diffs[0][0] + m * n, 0);

        for (const auto& query : queries) {
            int t = query[0], l = query[1], b = query[2], r = query[3];
            diffs[t][l] += 1;
            if (b + 1 < m) {
                diffs[b + 1][l] -= 1;
            }
            if (r + 1 < m) {
                diffs[t][r + 1] -= 1;
            }
            if (b + 1 < m && r + 1 < n) {
                diffs[b + 1][r + 1] += 1;
            }
        }

        vector<vector<int>> ret(m, vector<int>(n));
        ret[0][0] = diffs[0][0];
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                ret[r][c] = diffs[r][c];
                if (r > 0) {
                    ret[r][c] += ret[r - 1][c];
                }
                if (c > 0) {
                    ret[r][c] += ret[r][c - 1];
                }
                if (r > 0 && c > 0) {
                    ret[r][c] -= ret[r - 1][c - 1];
                }
            }
        }

        return ret;
    }
};
