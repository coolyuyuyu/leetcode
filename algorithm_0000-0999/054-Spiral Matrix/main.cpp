class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix.front().empty()) {
            return {};
        }

        vector<int> nums;
        for (size_t lft = 0, top = 0, rht = matrix.front().size() -1, btm = matrix.size() - 1; true;) {
            for (size_t col = lft; col <= rht; ++col) { 
                nums.push_back(matrix[top][col]);
            }
            if (btm < ++top) {
                break;
            }

            for (size_t row = top; row <= btm; ++row) { 
                nums.push_back(matrix[row][rht]);
            }
            if (rht-- <= lft) {
                break;
            }

            for (size_t col = rht + 1; lft < col--;) { 
                nums.push_back(matrix[btm][col]);
            }
            if (btm-- <= top) {
                break;
            }

            for (size_t row = btm + 1; top < row--;) { 
                nums.push_back(matrix[row][lft]);
            }
            if (rht < ++lft) {
                break;
            }
        }

        return nums;
    }
};
