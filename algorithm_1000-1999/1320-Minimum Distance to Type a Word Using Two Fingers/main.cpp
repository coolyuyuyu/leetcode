class Solution {
public:
    int dist(int c1, int c2) {
        auto [x1, y1] = std::div(c1, 6);
        auto [x2, y2] = std::div(c2, 6);
        return std::abs(x1 - x2) + std::abs(y1 - y2);
    }

    // Time: O(n * 26^2), Space: O(n * 26^2)
    int dp1(string word) {
        int n = word.size();

        // dp[k][i][j]: the minimum total distance to type word[0:i], where lft finger is at i and rht finger is at j.
        int dp[n][26][26];
        std::fill(&dp[0][0][0], &dp[0][0][0] + n * 26 * 26, INT_MAX / 2);

        for (int i = 0; i < 26; ++i) {
            dp[0][word[0] - 'A'][i] = 0;
            dp[0][i][word[0] - 'A'] = 0;
        }
        for (int k = 1; k < n; ++k) {
            int cur = word[k] - 'A';
            for (int i = 0; i < 26; ++i) {
                for (int j = 0; j < 26; ++j) {
                    dp[k][i][cur] = std::min(dp[k][i][cur], dp[k - 1][i][j] + dist(j, cur));
                    dp[k][cur][j] = std::min(dp[k][cur][j], dp[k - 1][i][j] + dist(i, cur));
                }
            }
        }

        int ret = INT_MAX;
        for (int i = 0; i < 26; ++i) {
            ret = std::min({ret, dp[n - 1][word[n - 1] - 'A'][i], dp[n - 1][i][word[n - 1] - 'A']});
        }

        return ret;
    }

    // Time: O(n * 26), Space: O(n * 26)
    int dp2(string word) {
        int n = word.size();

        // dp[k][i]: the minimum total distance to type word[0:i], where one finger is word[k] and other finger is at i.
        int dp[n][26];
        std::fill(&dp[0][0], &dp[0][0] + n * 26, INT_MAX / 2);

        for (int i = 0; i < 26; ++i) {
            dp[0][i] = 0;
        }
        for (int k = 1; k < n; ++k) {
            int pre = word[k - 1] - 'A', cur = word[k] - 'A';
            // k-1: pre=word[k-1]   x
            // k  : cur=word[k]     y
            for (int i = 0; i < 26; ++i) {
                dp[k][i] = std::min(dp[k][i], dp[k - 1][i] + dist(pre, cur));
                dp[k][i] = std::min(dp[k][i], dp[k - 1][cur] + dist(pre, i));
            }
        }

        int ret = INT_MAX;
        for (int i = 0; i < 26; ++i) {
            ret = std::min(ret, dp[n - 1][i]);
        }

        return ret;
    }

    int minimumDistance(string word) {
        //return dp1(word);
        return dp2(word);
    }
};
