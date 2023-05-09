class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        size_t m = matrix.size(), n = matrix.empty() ? 0 : matrix[0].size();
        if (m == 0 || n == 0) {
            return {};
        }

        vector<int> nums(m * n);
        for (size_t lft = 0, top = 0, rht = n - 1, btm = m - 1, i = 0; true;) {
            for (size_t col = lft; col <= rht; ++col) {
                nums[i++] = matrix[top][col];
            }
            if (btm < ++top) {
                break;
            }

            for (size_t row = top; row <= btm; ++row) {
                nums[i++] = matrix[row][rht];
            }
            if (rht-- <= lft) {
                break;
            }

            for (size_t col = rht + 1; lft < col--;) {
                nums[i++] = matrix[btm][col];
            }
            if (btm-- <= top) {
                break;
            }

            for (size_t row = btm + 1; top < row--;) {
                nums[i++] = matrix[row][lft];
            }
            if (rht < ++lft) {
                break;
            }
        }

        return nums;
    }
};
