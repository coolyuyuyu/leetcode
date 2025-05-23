class Solution {
public:
    // Space: O(m + n)
    void setZeroes1(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix.empty() ? 0 : matrix.front().size();

        vector<bool> rows(m, false), cols(n, false);
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (matrix[r][c] == 0) {
                    rows[r] = true;
                    cols[c] = true;
                }
            }
        }

        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (rows[r] || cols[c]) {
                    matrix[r][c] = 0;
                }
            }
        }
    }

    // Space: O(1)
    void setZeroes2(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix.empty() ? 0 : matrix[0].size();

        bool zeroRow0 = false;
        for (int c = 0; c < n && !zeroRow0; ++c) {
            if (matrix[0][c] == 0) { zeroRow0 = true; }
        }
        bool zeroCol0 = false;
        for (int r = 0; r < m && !zeroCol0; ++r) {
            if (matrix[r][0] == 0) { zeroCol0 = true; }
        }

        for (int r = 1; r < m; ++r) {
            for (int c = 1; c < n; ++c) {
                if (matrix[r][c] == 0) {
                    matrix[r][0] = matrix[0][c] = 0;
                }
            }
        }
        for (int r = 1; r < m; ++r) {
            for (int c = 1; c < n; ++c) {
                if (matrix[r][0] == 0 || matrix[0][c] == 0) {
                    matrix[r][c] = 0;
                }
            }
        }

        if (zeroRow0) {
            for (int c = 0; c < n; ++c) {
                matrix[0][c] = 0;
            }
        }
        if (zeroCol0) {
            for (int r = 0; r < m; ++r) {
                matrix[r][0] = 0;
            }
        }
    }

    void setZeroes(vector<vector<int>>& matrix) {
        //setZeroes1(matrix);
        setZeroes2(matrix);
    }
};
