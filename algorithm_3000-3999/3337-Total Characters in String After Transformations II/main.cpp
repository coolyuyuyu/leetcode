class Solution {
public:
    int M = 1e9 + 7;

    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        int m = mat1.size(), p = mat1[0].size(), n = mat2[0].size();

        vector<vector<int>> ret(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int k = 0; k < p; ++k) {
                if (mat1[i][k] == 0) { continue; }
                for (int j = 0; j < n; ++j) {
                    ret[i][j] = (ret[i][j] + 1L * mat1[i][k] * mat2[k][j]) % M;
                }
            }
        }

        return ret;
    }

    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        vector<vector<int>> base(26, vector<int>(26, 0));
        for (int c = 0; c < 26; ++c) {
            int num = nums[c];
            for (int r = (c + 1) % 26; num; --num, r = (r + 1) % 26) {
                base[r][c] += 1;
                base[r][c] % M;
            }
        }

        vector<vector<int>> mat(26, vector<int>(26, 0));
        for (int i = 0; i < 26; ++i) {
            mat[i][i] = 1;
        }
        for (; t; t >>= 1) {
            if (t & 1) {
                mat = multiply(mat, base);
            }
            base = multiply(base, base);
        }

        int cnts[26];
        for (char c : s) {
            ++cnts[c - 'a'];
        }

        int ret = 0;
        for (int r = 0; r < 26; ++r) {
            for (int c = 0; c < 26; ++c) {
                ret = (ret + (1L * mat[r][c] * cnts[c]) % M) % M;
            }
        }

        return ret;
    }
};
