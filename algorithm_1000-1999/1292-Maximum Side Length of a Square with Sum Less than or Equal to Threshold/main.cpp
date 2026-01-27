class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size(), n = mat.empty() ? 0 : mat[0].size();

        int dp[m][n];
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                dp[r][c] = mat[r][c];
                if (r > 0) { dp[r][c] += dp[r - 1][c]; }
                if (c > 0) { dp[r][c] += dp[r][c - 1]; }
                if (r > 0 && c > 0) { dp[r][c] -= dp[r - 1][c - 1]; }
            }
        }

        std::function<int(int, int, int, int)> sumRec = [&](int r1, int c1, int r2, int c2) {
            int ret = dp[r2][c2];
            if (r1 > 0) { ret -= dp[r1 - 1][c2]; }
            if (c1 > 0) { ret -= dp[r2][c1 - 1]; }
            if (r1 > 0 && c1 > 0) { ret += dp[r1 - 1][c1 - 1]; }
            return ret;
        };

        std::function<bool(int)> checkOk = [&](int s) {
            for (int r = 0; r + s - 1 < m; ++r) {
                for (int c = 0; c + s - 1 < n; ++c) {
                    if (sumRec(r, c, r + s - 1, c + s - 1) <= threshold) {
                        return true;
                    }
                }
            }
            return false;
        };

        int lo = 0, hi = std::min(m, n);
        while (lo < hi) {
            int mid = hi - (hi - lo) / 2;
            if (checkOk(mid)) {
                lo = mid;
            }
            else {
                hi = mid - 1;
            }
        }

        return lo;
    }
};
