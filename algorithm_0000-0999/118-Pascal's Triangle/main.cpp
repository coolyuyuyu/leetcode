class Solution {
public:
    vector<vector<int>> dynamic_programing(int numRows) {
        vector<vector<int>> dp(numRows);
        for (int r = 0; r < numRows; ++r) {
            dp[r].resize(r + 1);
            for (int c = 0; c < (r / 2 + 1); ++c) {
                if (r == 0 || c == 0) {
                    dp[r][c] = dp[r][r - c] = 1;
                }
                else {
                    dp[r][c] = dp[r][r - c] = dp[r - 1][c - 1] + dp[r - 1][c];
                }
            }
        }

        return dp;
    }

    vector<vector<int>> math(int numRows) {
        vector<vector<int>> ret(numRows);
        for (int r = 0; r < numRows; ++r) {
            ret[r].resize(r + 1);
            for (int c = 0; c < (r / 2 + 1); ++c) {
                if (c == 0) {
                    ret[r][c] = ret[r][r - c] = 1;
                }
                else {
                    ret[r][c] = ret[r][r - c] = ret[r][c - 1] * (r - c + 1) / c;
                }
            }
        }

        return ret;
    }

    vector<vector<int>> generate(int numRows) {
        return dynamic_programing(numRows);
        //return math(numRows);
    }
};
