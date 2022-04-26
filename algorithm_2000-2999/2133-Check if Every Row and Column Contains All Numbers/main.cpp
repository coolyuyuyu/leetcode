class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<bool> row(n + 1), col(n + 1);
        for (int i = 0; i < n; ++i) {
            std::fill_n(row.begin() + 1, n, false);
            std::fill_n(col.begin() + 1, n, false);
            for (int j = 0; j < n; ++j) {
                if (row[matrix[i][j]]) {
                    return false;
                }
                row[matrix[i][j]] = true;

                if (col[matrix[j][i]]) {
                    return false;
                }
                col[matrix[j][i]] = true;
            }
        }

        return true;
    }
};
