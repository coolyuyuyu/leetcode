class Solution {
public:
    // Time(m, n) = O(m * n), Space(m, n) = O(m, n)
    size_t numDistinctDpV1(const string& s, const string& t) {
        size_t rowCnt = t.size() + 1, colCnt = s.size() + 1;
        vector<vector<size_t>> dp(rowCnt, vector<size_t>(colCnt));
        for (size_t col = 0; col < colCnt; ++col) {
            dp[0][col] = 1;
        }
        for (size_t row = 1; row < rowCnt; ++row) {
            dp[row][0] = 0;
            for(size_t col = 1; col < colCnt; ++col) {
                dp[row][col] = dp [row][col - 1];
                if (t[row - 1] == s[col - 1]) {
                    dp[row][col] += dp[row - 1][col - 1];
                }
            }
        }

        return dp[rowCnt - 1][colCnt - 1];
    }

    // Time(m, n) = O(m * n), Space(m, n) = O(m)
    size_t numDistinctDpV2(const string& s, const string& t) {
        size_t rowCnt = t.size() + 1, colCnt = s.size() + 1;
        vector<size_t> dp(colCnt, 1);
        for (size_t row = 1; row < rowCnt; ++row) {
            size_t prev = dp[0];
            dp[0] = 0;
            for(size_t col = 1; col < colCnt; ++col) {
                size_t tmp = dp[col];

                dp[col] = dp[col - 1];
                if (t[row - 1] == s[col - 1]) {
                    dp[col] += prev;
                }

                prev = tmp;
            }
        }

        return dp[colCnt - 1];
    }

    size_t numDistinct(string s, string t) {
        //return numDistinctDpV1(s, t);

        return numDistinctDpV2(s, t);
    }
};