class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) {
            return {};
        }

        int top = 0, btm = matrix.size() - 1, lft = 0, rht = matrix.front().size() - 1;
        vector<int> result;
        result.reserve((btm - top + 1) * (rht - lft + 1));
        while (true) {
            for (int col = lft; col <= rht; ++col) {
                result.push_back(matrix[top][col]);
            }
            if (++top > btm) {
                break;
            }

            for (int row = top; row <= btm; ++row) {
                result.push_back(matrix[row][rht]);
            }
            if (--rht < lft) {
                break;
            }

            for (int col = rht; lft <= col; --col) {
                result.push_back(matrix[btm][col]);
            }
            if (--btm < top) {
                break;
            }

            for (int row = btm; top <= row; --row) {
                result.push_back(matrix[row][lft]);
            }
            if (++lft > rht) {
                break;
            }
        }

        return result;
    }
};