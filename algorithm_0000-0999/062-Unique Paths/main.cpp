class Solution {
public:
    // Time: O(m*n), Space: O(m*n)
    int dp1(int m, int n) {
        vector<vector<int>> cnts(m, vector<int>(n));
        for (size_t r = 0; r < m; ++r) {
            for (size_t c = 0; c < n; ++c) {
                if (r == 0 || c == 0) {
                    cnts[r][c] = 1;
                }
                else {
                    cnts[r][c] = cnts[r - 1][c] + cnts[r][c - 1];
                }
            }
        }

        return cnts[m - 1][n - 1];
    }

    // Time: O(m*n), Space: O(m*2)
    int dp2(int m, int n) {
        vector<int> curCnts(n), preCnts(n);
        for (size_t r = 0; r < m; ++r) {
            curCnts.swap(preCnts);
            for (size_t c = 0; c < n; ++c) {
                if (r == 0 || c == 0) {
                    curCnts[c] = 1;
                }
                else {
                    curCnts[c] = preCnts[c] + curCnts[c - 1];
                }
            }
        }

        return curCnts[n - 1];
    }

    // Time: O(m*n), Space: O(m)
    int dp3(int m, int n) {
        vector<int> cnts(n);
        for (size_t r = 0; r < m; ++r) {
            for (size_t c = 0; c < n; ++c) {
                if (r == 0 || c == 0) {
                    cnts[c] = 1;
                }
                else {
                    cnts[c] += cnts[c - 1];
                }
            }
        }

        return cnts[n - 1];
    }

    // Time: O(m+n), Space: O(1)
    int math(int m, int n) {
        auto combination = [](int n, int r) -> long {
            if (r < (n / 2)) {
                r = n - r;
            }

            long ans = 1;
            for (int i = r + 1, j = 1; j <= (n - r); ++i, ++j) {
                ans *= i;
                ans /= j;
            }
            return ans;
        };

        return combination(m + n - 2, m - 1);
    }

    int uniquePaths(int m, int n) {
        //return dp1(m, n);
        //return dp2(m, n);
        //return dp3(m, n);
        return math(m, n);
    }
};