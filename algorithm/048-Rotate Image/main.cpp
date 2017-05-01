class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int k = 1; k < n; ++k) {
            for (int x = 0; x + k < n ; ++x) {
                int y = x + k;
                swap(matrix[x][y], matrix[y][x]);
            }
        }

        for (int x = 0; x < n; ++x) {
            for (int y = 0; y < n / 2; ++y) {
                swap(matrix[x][y], matrix[x][n - y - 1]);
            }
        }
    }
};