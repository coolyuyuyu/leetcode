class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size(), n = mat.front().size();
        if (m * n != r * c) {
            return mat;
        }

        vector<vector<int>> ans;
        int k = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (k == 0) {
                    ans.push_back(vector<int>());
                }
                if (++k == c) {
                    k = 0;
                }
                ans.back().push_back(mat[i][j]);
            }
        }

        return ans;
    }
};
