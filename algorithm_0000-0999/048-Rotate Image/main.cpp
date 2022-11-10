class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        size_t n = matrix.size();
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = i + 1; j < n; ++j) {
                std::swap(matrix[i][j], matrix[j][i]);
            }
        }

        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < (n / 2); ++j) {
                std::swap(matrix[i][j], matrix[i][n - j - 1]);
            }
        }
    }
};
