class Solution {
public:
    vector<pair<int, int>> diffs = {{0, 0}, {0, -1}, {-1, 0}, {0, 1}, {1, 0}};

    bool check(const vector<vector<int>>& mat, int state) {
        int m = mat.size(), n = mat.empty() ? 0 : mat[0].size();
        vector<vector<int>> flip(m, vector<int>(n, 0));

        for (int i = 0; i < m * n; ++i) {
            if (state & (1 << i)) {
                int r = i / n, c = i % n;
                for (const auto& [dr, dc] : diffs) {
                    int x = r + dr, y = c + dc;
                    if (x < 0 || m <= x || y < 0 || n <= y) { continue; }
                    flip[x][y] = 1 - flip[x][y];
                }
            }
        }

        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (mat[r][c] != flip[r][c]) {
                    return false;
                }
            }
        }

        return true;
    }

    int byIterateAll(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat.empty() ? 0 : mat[0].size();

        int ret = INT_MAX;
        for (int state = 0; state < (1 << (m * n)); ++state) {
            if (check(mat, state)) {
                ret = std::min(ret, __builtin_popcount(state));
            }
        }

        return ret == INT_MAX ? -1 : ret;
    }

    int byGopherHack(vector<vector<int>>& mat) {
        if (check(mat, 0)) {
            return 0;
        }

        int rowCnt = mat.size(), colCnt = mat.empty() ? 0 : mat[0].size();
        int m = rowCnt * colCnt;

        int ret = INT_MAX;
        for (int k = 1; k <= m; ++k) {
            // Gosper's hack: Iterate all the m-bit state where there are k 1-bits.
            int state = (1 << k) - 1;
            while (state < (1 << m)) {
                if (check(mat, state)) {
                    return k;
                }

                int c = state & - state;
                int r = state + c;
                state = (((r ^ state) >> 2) / c) | r;
            }
        }

        return -1;
    }

    int minFlips(vector<vector<int>>& mat) {
        //return byIterateAll(mat);
        return byGopherHack(mat);
    }
};
