class Solution {
public:
    vector<vector<int>> f1(const vector<vector<int>>& mat1, const vector<vector<int>>& mat2) {
        int m = mat1.size(), k = mat1[0].size(), n = mat2[0].size();

        vector<vector<int>> ret(m, vector<int>(n, 0));
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                for (int i = 0; i < k; ++i) {
                    ret[r][c] += mat1[r][i] * mat2[i][c];
                }
            }
        }

        return ret;
    }

    vector<vector<int>> f2(const vector<vector<int>>& mat1, const vector<vector<int>>& mat2) {
        int m = mat1.size(), k = mat1[0].size(), n = mat2[0].size();

        vector<vector<int>> ret(m, vector<int>(n, 0));
        for (int r = 0; r < m; ++r) {
            for (int i = 0; i < k; ++i) {
                if (mat1[r][i] == 0) {
                    continue;
                }
                for (int c = 0; c < n; ++c) {
                    ret[r][c] += mat1[r][i] * mat2[i][c];
                }
            }
        }

        return ret;
    }

    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        //return f1(mat1, mat2);
        return f2(mat1, mat2);
    }
};
