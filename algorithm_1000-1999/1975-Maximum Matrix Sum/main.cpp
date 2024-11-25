class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix.empty() ? 0 : matrix[0].size();

        long long sum = 0;
        bool anyZero = false;
        int negCnt = 0;
        int minAbs = INT_MAX;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (matrix[r][c] == 0) {
                    anyZero = true;
                }
                else {
                    minAbs = std::min(minAbs, std::abs(matrix[r][c]));
                    if (matrix[r][c] < 0) {
                        sum -= matrix[r][c];
                        ++negCnt;
                    }
                    else {
                        sum += matrix[r][c];
                    }
                }
            }
        }

        if (anyZero) {
            return sum;
        }
        else {
            if (negCnt & 1) {
                return sum - 2 * minAbs;
            }
            else {
                return sum;
            }
        }
    }
};
