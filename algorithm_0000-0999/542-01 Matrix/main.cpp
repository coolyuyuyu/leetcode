class Solution {
public:
    vector<vector<int>> updateMatrixBfs(vector<vector<int>>& matrix) {
        size_t rowCnt = matrix.size();
        size_t colCnt = matrix.empty() ? 0 : matrix.front().size();

        vector<pair<size_t, size_t>> points;
        for (size_t row = 0; row < rowCnt; ++row) {
            for (size_t col = 0; col < colCnt; ++col) {
                if (matrix[row][col] == 0) {
                    points.emplace_back(row, col);
                }
                else {
                    matrix[row][col] = -1;
                }
            }
        }

        int distance = 0;
        while (!points.empty()) {
            for (const pair<size_t, size_t>& point : points) {
                matrix[point.first][point.second] = distance;
            }

            vector<pair<size_t, size_t>> pointsTmp;
            for (const pair<size_t, size_t>& point : points) {
                size_t row = point.first, col = point.second;

                // lft
                if (0 < col && matrix[row][col - 1] < 0) {
                    pointsTmp.emplace_back((row), (col - 1));
                }

                // upr
                if (0 < row && matrix[row - 1][col] < 0) {
                    pointsTmp.emplace_back((row - 1) , + (col));
                }

                // rht
                if (col + 1 < colCnt && matrix[row][col + 1] < 0) {
                    pointsTmp.emplace_back((row) , (col + 1));
                }

                // btm
                if (row + 1 < rowCnt && matrix[row + 1][col] < 0) {
                    pointsTmp.emplace_back((row + 1) , (col));
                }
            }
            points.swap(pointsTmp);

            ++distance;
        }

        return matrix;
    }

    vector<vector<int>> updateMatrixDp(vector<vector<int>>& matrix) {
        size_t rowCnt = matrix.size();
        size_t colCnt = matrix.empty() ? 0 : matrix.front().size();

        for (size_t row = 0; row < rowCnt; ++row) {
            for (size_t col = 0; col < colCnt; ++col) {
                if (matrix[row][col] == 1) {
                    int lftMax = 0 < col ? matrix[row][col - 1] : INT_MAX;
                    int uprMax = 0 < row ? matrix[row - 1][col] : INT_MAX;
                    int neighborMax = min(lftMax, uprMax);
                    matrix[row][col] = (neighborMax == INT_MAX ? INT_MAX : (neighborMax + 1));
                }
            }
        }

        for (size_t row = rowCnt; 0 < row--;) {
            for (size_t col = colCnt; 0 < col--;) {
                int rhtMax = col + 1 < colCnt ? matrix[row][col + 1] : INT_MAX;
                int btmMax = row + 1 < rowCnt ? matrix[row + 1][col] : INT_MAX;
                int neighborMax = min(rhtMax, btmMax);
                matrix[row][col] = min(matrix[row][col], neighborMax == INT_MAX ? INT_MAX : (neighborMax + 1));
            }
        }

        return matrix;
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        //return updateMatrixBfs(matrix);

        return updateMatrixDp(matrix);
    }
};