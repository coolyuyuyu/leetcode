class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> ret(m, string(n, '#'));
        for (int r = 0; r < m; ++r) {
            ret[r][0] = '.';
        }
        for (int c = 1; c < n; ++c) {
            ret[m - 1][c] = '.';
        }

        return ret;
    }
};
