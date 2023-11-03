class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        size_t m = matrix.size(), n = matrix.empty() ? 0 : matrix[0].size();

        vector<int> ret(m * n);
        for (size_t lft = 0, rht = n - 1, top = 0, btm = m - 1, idx = 0; true;) {
            for (size_t c = lft; c <= rht; ++c) {
                ret[idx++] = matrix[top][c];
            }
            if (++top > btm) { break; }

            for (size_t r = top; r <= btm; ++r) {
                ret[idx++] = matrix[r][rht];
            }
            if (lft >= rht--) { break; }

            for (size_t c = rht + 1; lft < c--;) {
                ret[idx++] = matrix[btm][c];
            }
            if (btm-- <= top) { break; }

            for (size_t r = btm + 1; top < r--;) {
                ret[idx++] = matrix[r][lft];
            }
            if (++lft > rht) { break; }
        }

        return ret;
    }
};
