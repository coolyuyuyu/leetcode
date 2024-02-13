class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix.empty() ? 0 : matrix[0].size();

        for (int c = 0; c < n; ++c) {
            int mx = INT_MIN;
            for (int r = 0; r < m; ++r) {
                mx = std::max(mx, matrix[r][c]);
            }

            for (int r = 0; r < m; ++r) {
                if (matrix[r][c] == -1) {
                    matrix[r][c] = mx;
                }
            }
        }

        return matrix;
    }
};
