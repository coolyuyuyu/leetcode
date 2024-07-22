class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int m = rowSum.size(), n = colSum.size();

        vector<vector<int>> ret(m, vector<int>(n));
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                int v = std::min(rowSum[r], colSum[c]);
                ret[r][c] = v;
                rowSum[r] -= v;
                colSum[c] -= v;
            }
        }

        return ret;
    }
};
