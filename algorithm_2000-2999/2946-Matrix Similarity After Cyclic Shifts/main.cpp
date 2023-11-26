class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat.empty() ? 0 : mat[0].size();
        k %= n;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i & 1) { // odd
                    if (mat[i][j] != mat[i][(j - k + n) % n]) { return false; }
                }
                else {
                    if (mat[i][j] != mat[i][(j + k) % n]) { return false; }
                }
            }
        }

        return true;
    }
};
