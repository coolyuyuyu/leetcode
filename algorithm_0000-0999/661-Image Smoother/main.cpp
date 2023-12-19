class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size(), n = img.empty() ? 0 : img[0].size();

        int presum[m][n];
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                presum[r][c] = img[r][c]
                    + (r > 0 ? presum[r - 1][c] : 0)
                    + (c > 0 ? presum[r][c - 1] : 0)
                    - (r > 0 && c > 0 ? presum[r - 1][c - 1] : 0);
            }
        }

        vector<vector<int>> ret(m, vector<int>(n));
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                int rt = std::max(r - 1, 0), rb = std::min(r + 1, m - 1);
                int cl = std::max(c - 1, 0), cr = std::min(c + 1, n - 1);
                int sum = presum[rb][cr]
                    - (rt > 0 ? presum[rt - 1][cr] : 0)
                    - (cl > 0 ? presum[rb][cl - 1] : 0)
                    + (rt > 0 && cl > 0 ? presum[rt - 1][cl - 1] : 0);
                int cnt = (rb - rt + 1) * (cr - cl + 1);
                ret[r][c] = sum / cnt;
            }
        }

        return ret;
    }
};
