class Solution {
public:
    vector<int> bruteforce(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix.empty() ? 0 : matrix[0].size();

        vector<int> rowMins(m, INT_MAX), colMaxs(n, INT_MIN);
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                rowMins[r] = std::min(rowMins[r], matrix[r][c]);
                colMaxs[c] = std::max(colMaxs[c], matrix[r][c]);
            }
        }

        vector<int> ret;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (matrix[r][c] == rowMins[r] && matrix[r][c] == colMaxs[c]) {
                    ret.push_back(matrix[r][c]);
                }
            }
        }

        return ret;
    }

    vector<int> greedy(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix.empty() ? 0 : matrix[0].size();

        int rowMinMax = INT_MIN;
        for (int r = 0; r < m; ++r) {
            int rowMin = INT_MAX;
            for (int c = 0; c < n; ++c) {
                rowMin = std::min(rowMin, matrix[r][c]);
            }
            rowMinMax = std::max(rowMinMax, rowMin);
        }

        int colMaxMin = INT_MAX;
        for (int c = 0; c < n; ++c) {
            int colMax = INT_MIN;
            for (int r = 0; r < m; ++r) {
                colMax = std::max(colMax, matrix[r][c]);
            }
            colMaxMin = std::min(colMaxMin, colMax);
        }

        vector<int> ret;
        if (rowMinMax == colMaxMin) {
            ret.push_back(rowMinMax);
        }

        return ret;
    }

    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        //return bruteforce(matrix);
        return greedy(matrix);
    }
};
