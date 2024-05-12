class Solution {
public:
    int minimumSubstringsInPartition(string s) {
        int n = s.size();
        s = "#" + s;

        // dp[i]: the minimum number of substrings that you can partition s[1:i] into
        int dp[n + 1];
        std::fill(dp, dp + n + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i <= n; ++i) {
            vector<int> cnts(26, 0);
            int maxCntNum = 0, maxCntFreq = 0;
            for (int j = i; j >= 1; --j) {
                ++cnts[s[j] - 'a'];
                if (cnts[s[j] - 'a'] > maxCntNum) {
                    maxCntNum = cnts[s[j] - 'a'];
                    maxCntFreq = 1;
                }
                else if (cnts[s[j] - 'a'] == maxCntNum) {
                    ++maxCntFreq;
                }

                if (maxCntNum * maxCntFreq == i - j + 1) {
                    dp[i] = std::min(dp[i], dp[j - 1] + 1);
                }
            }
        }

        return dp[n];
    }
};
