class Solution {
public:
    int byDP1(string s, int k) {
        int n = s.size();

        // dp[i]: the length of the longest ideal subsequence ending at s[i]
        int dp[n];
        std::fill(dp, dp + n, 1);

        vector<int> prev(26, -1);
        for (int i = 0; i < n; ++i) {
            for (char c = std::max(s[i] - 'a' - k , 0) + 'a'; c <= std::min(s[i] - 'a' + k, 25) + 'a'; ++c) {
                if (prev[c - 'a'] != -1) {
                    dp[i] = std::max(dp[i], dp[prev[c - 'a']] + 1);
                }
            }
            prev[s[i] - 'a'] = i;
        }

        int ret = 0;
        for (int i = 0; i < n; ++i) {
            ret = std::max(ret, dp[i]);
        }

        return ret;
    }

    int byDP2(string s, int k) {
        int n = s.size();

        // dp[c]: the length of the longest ideal subsequence ending at character c
        int dp[26];
        std::fill(dp, dp + 26, 0);

        for (int i = 0; i < n; ++i) {
            int mx = 0;
            for (char c = std::max(s[i] - 'a' - k , 0) + 'a'; c <= std::min(s[i] - 'a' + k, 25) + 'a'; ++c) {
                mx = std::max(mx, dp[c - 'a']);
            }
            dp[s[i] - 'a'] = mx + 1;
        }

        int ret = 0;
        for (int i = 0; i < 26; ++i) {
            ret = std::max(ret, dp[i]);
        }

        return ret;
    }

    int longestIdealString(string s, int k) {
        //return byDP1(s, k);
        return byDP2(s, k);
    }
};
