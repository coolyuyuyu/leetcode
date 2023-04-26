class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size(), n = mat.empty() ? 0 : mat[0].size();
        if (m * n != r * c) {
            return mat;
        }

        vector<vector<int>> ret(r, vector<int>(c));
        int x = 0, y = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ret[x][y++] = mat[i][j];
                if (y == c) {
                    ++x;
                    y = 0;
                }
            }
        }

        return ret;
    }
};
