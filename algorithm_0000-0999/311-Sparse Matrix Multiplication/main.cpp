class Solution {
public:

    vector<vector<int>> f1(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        int m = mat1.size(), p = mat1[0].size(), n = mat2[0].size();

        vector<vector<int>> ret(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < p; ++k) {
                    ret[i][j] += mat1[i][k] * mat2[k][j];
                }
            }
        }

        return ret;
    }

    vector<vector<int>> f2(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        int m = mat1.size(), p = mat1[0].size(), n = mat2[0].size();

        vector<vector<int>> ret(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int k = 0; k < p; ++k) {
                if (mat1[i][k] == 0) { continue; }
                for (int j = 0; j < n; ++j) {
                    ret[i][j] += mat1[i][k] * mat2[k][j];
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
