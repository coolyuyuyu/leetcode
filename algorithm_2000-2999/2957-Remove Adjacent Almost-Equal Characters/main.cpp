class Solution {
public:
    // Time: O(676n)
    int dp1(string word) {
        int n = word.size();

        // dp[i][c]: minimum number of operations needed to remove all adjacent almost-equal characters from word[0:i], and the last character is set as c
        int dp[n][26];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 26; ++j) {
                dp[i][j] = INT_MAX;
            }
        }
        for (int j = 0; j < 26; ++j) {
            dp[0][j] = (word[0] == ('a' + j) ? 0 : 1);
        }
        for (int i = 1; i < n; ++i) {
            for (int cur = 0; cur < 26; ++cur) {
                for (int pre = 0; pre < 26; ++pre) {
                    if (abs(cur - pre) > 1) {
                        dp[i][cur] = std::min(dp[i][cur], dp[i - 1][pre] + (word[i] == ('a' + cur) ? 0 : 1));
                    }
                }
            }
        }

        int ret = INT_MAX;
        for (int j = 0; j < 26; ++j) {
            ret = std::min(ret, dp[n - 1][j]);
        }

        return ret;
    }

    // Time: O(2n)
    int dp2(string word) {
        int n = word.size();

        // dp[i][c]: minimum number of operations needed to remove all adjacent almost-equal characters from word[0:i], and the last character is unchanged(j = 0) or changed(1)
        int dp[n][2];
        dp[0][0] = 0;
        dp[0][1] = 1;
        for (int i = 1; i < n; ++i) {
            if (abs(word[i] - word[i - 1]) > 1) {
                dp[i][0] = std::min(dp[i - 1][0], dp[i - 1][1]);
                dp[i][1] = std::min(dp[i - 1][0], dp[i - 1][1]) + 1;
            }
            else {
                dp[i][0] = dp[i - 1][1];
                dp[i][1] = std::min(dp[i - 1][0], dp[i - 1][1]) + 1 ;
            }
        }

        return std::min(dp[n-1][0], dp[n-1][1]);
    }

    int removeAlmostEqualCharacters(string word) {
        //return dp1(word);
        return dp2(word);
    }
};
