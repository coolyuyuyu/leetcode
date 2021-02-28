class Solution {
public:
    // Time(m, n) = O(2 ^ (m + n)), Space(m, n) = O(m + n)
    bool isInterleaveRecv(const string& s1, size_t i1, const string& s2, size_t i2, const string& s3, size_t i3) {
        if (s3.size() <= i3) {
            if (s1.size() <= i1 && s2.size() <= i2) {
                return true;
            }
            else {
                return false;
            }
        }

        if (i1 < s1.size() && s1[i1] == s3[i3]) {
            if (isInterleaveRecv(s1, i1 + 1, s2, i2, s3, i3 + 1)) {
                return true;
            }
        }
        if (i2 < s2.size() && s2[i2] == s3[i3]) {
            if (isInterleaveRecv(s1, i1, s2, i2 + 1, s3, i3 + 1)) {
                return true;
            }
        }

        return false;
    }

    // Time(m, n) = O(m * n), Space(m, n) = O(m * n)
    bool isInterleaveDpV1(const string& s1, const string& s2, const string& s3) {
        size_t rowCnt = s1.size() + 1, colCnt = s2.size() + 1;
        vector<vector<bool>> dp(rowCnt, vector<bool>(colCnt));
        for (size_t row = 0; row < rowCnt; ++row) {
            for (size_t col = 0; col < colCnt; ++col) {
                if (row == 0 && col == 0) {
                    dp[row][col] = true;
                }
                else if (row == 0) {
                    dp[row][col] = dp[row][col - 1] && s2[col - 1] == s3[row + col - 1];
                }
                else if (col == 0) {
                    dp[row][col] = dp[row - 1][col] && s1[row - 1] == s3[row + col - 1];
                }
                else {
                    dp[row][col] =
                        dp[row - 1][col] && s1[row - 1] == s3[row + col - 1] ||
                        dp[row][col - 1] && s2[col - 1] == s3[row + col - 1];
                }
            }
        }

        return dp[rowCnt - 1][colCnt - 1];
    }

    // Time(m, n) = O(m * n), Space(m, n) = O(min(m, n))
    bool isInterleaveDpV2(string s1, string s2, const string& s3) {
        if (s1.size() < s2.size()) {
            swap(s1, s2);
        }

        size_t rowCnt = s1.size() + 1, colCnt = s2.size() + 1;
        vector<bool> dp(colCnt);
        for (size_t row = 0; row < rowCnt; ++row) {
            for (size_t col = 0; col < colCnt; ++col) {
                bool tmp = dp[col];
                if (row == 0 && col == 0) {
                    dp[col] = true;
                }
                else if (row == 0) {
                    dp[col] = dp[col - 1] && s2[col - 1] == s3[row + col - 1];
                }
                else if (col == 0) {
                    dp[col] = dp[col] && s1[row - 1] == s3[row + col - 1];
                }
                else {
                    dp[col] =
                        dp[col] && s1[row - 1] == s3[row + col - 1] ||
                        dp[col - 1] && s2[col - 1] == s3[row + col - 1];
                }
            }
        }

        return dp[colCnt - 1];
    }

    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) {
            return false;
        }

        //return isInterleaveRecv(s1, 0, s2, 0, s3, 0);

        //return isInterleaveDpV1(s1, s2, s3);

        return isInterleaveDpV2(s1, s2, s3);
    }
};