class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        size_t m = matrix.size(), n = matrix.empty() ? 0 : matrix.front().size();

        if (m < n) {
            matrix.resize(n, vector<int>(m));
        }
        else if (n < m) {
            for (size_t i = 0; i < n; ++i) {
                matrix[i].resize(m);
            }
        }

        const auto minmax = std::minmax(m, n);
        for (size_t i = 0; i < minmax.first; ++i) {
            for (size_t j = i + 1; j < minmax.second; ++j) {
                std::swap(matrix[i][j], matrix[j][i]);
            }
        }

        matrix.resize(n);
        for (auto& row : matrix) {
            row.resize(m);
        }

        return matrix;
    }
};
