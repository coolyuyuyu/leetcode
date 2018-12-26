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

    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        return updateMatrixBfs(matrix);
    }
};