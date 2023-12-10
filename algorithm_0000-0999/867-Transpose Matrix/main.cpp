class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        size_t m = matrix.size(), n = matrix.empty() ? 0 : matrix[0].size();
        if (m < n) {
            matrix.resize(n, vector<int>(m));
        }
        else if (m > n) {
            for (size_t i = 0; i < n; ++i) {
                matrix[i].resize(m);
            }
        }

        auto [mn, mx] = std::minmax(m, n);
        for (int i = 0; i < mn; ++i) {
            for (int j = i + 1; j < mx; ++j) {
                std::swap(matrix[i][j], matrix[j][i]);
            }
        }

        if (m < n) {
            for (size_t i = 0; i < m; ++i) {
                matrix[i].resize(m);
            }
        }
        else if (m > n) {
            matrix.resize(n);
        }

        return matrix;
    }
};
