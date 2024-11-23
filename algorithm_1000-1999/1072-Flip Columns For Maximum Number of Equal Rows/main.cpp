class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix.empty() ? 0 : matrix[0].size();

        unordered_map<string, int> cnts;
        for (int r = 0; r < m; ++r) {
            string pattern;
            for (int c = 1; c < n; ++c) {
                pattern += (matrix[r][c] == matrix[r][0] ? '1' : '0');
            }

            ++cnts[pattern];
        }

        int ret = 0;
        for (const auto& [_, cnt] : cnts) {
            ret = std::max(ret, cnt);
        }

        return ret;
    }
};
