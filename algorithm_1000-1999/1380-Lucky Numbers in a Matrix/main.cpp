class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        size_t m = matrix.size(), n = matrix.empty() ? 0 : matrix.front().size();
        vector<int> rowMinNums(m, INT_MAX), colMaxNums(n, INT_MIN);
        for (size_t i = 0; i < m; ++i) {
            for (size_t j = 0; j < n; ++j) {
                rowMinNums[i] = std::min(rowMinNums[i], matrix[i][j]);
                colMaxNums[j] = std::max(colMaxNums[j], matrix[i][j]);
            }
        }

        for (size_t i = 0; i < m; ++i) {
            for (size_t j = 0; j < n; ++j) {
                if (rowMinNums[i] == colMaxNums[j]) {
                    return {rowMinNums[i]};
                }
            }
        }

        return {};
    }
};
