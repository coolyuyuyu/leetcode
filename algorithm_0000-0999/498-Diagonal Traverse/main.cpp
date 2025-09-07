class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat.empty() ? 0 : mat[0].size();
        vector<int> ret(m * n);
        for (int i = 0, r = 0, c = 0; i < ret.size(); ++i) {
            ret[i] = mat[r][c];
            if ((r + c) & 1) {
                if (r + 1 == m) { ++c; }
                else if (c == 0) { ++r; }
                else { ++r, --c; }
            }
            else {
                if (c + 1 == n) { ++r; }
                else if (r == 0) { ++c; }
                else { --r, ++c; }
            }
        }

        return ret;
    }
};
