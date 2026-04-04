class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat.empty() ? 0 : mat[0].size();
        k %= n;

        for (int r = 0; r < m; ++r) {
            if (r & 1) {
                for (int c = 0; c < n; ++c) {
                    if (mat[r][c] != mat[r][(c - k + n) % n]) {
                        return false;
                    }
                }
            }
            else {
                for (int c = 0; c < n; ++c) {
                    if (mat[r][c] != mat[r][(c + k ) % n]) {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};
