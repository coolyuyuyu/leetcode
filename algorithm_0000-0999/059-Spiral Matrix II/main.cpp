class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ret(n, vector<int>(n));
        int i = 0;
        for (size_t lft = 0, top = 0, rht = n - 1, btm = n - 1; true;) {
            for (int col = lft; col <= rht; ++col) {
                ret[top][col] = ++i;
            }
            if (btm < ++top) {
                break;
            }

            for (int row = top; row <= btm; ++row) {
                ret[row][rht] = ++i;
            }
            if (rht-- <= lft) {
                break;
            }

            for (int col = rht + 1; lft < col--;) {
                ret[btm][col] = ++i;
            }
            if (btm-- <= top) {
                break;
            }

            for (int row = btm + 1; top < row--;) {
                ret[row][lft] = ++i;
            }
            if (rht < ++lft) {
                break;
            }
        }

        return ret;
    }
};
