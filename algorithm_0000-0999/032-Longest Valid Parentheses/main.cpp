class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        if (n == 0) {
            return 0;
        }

        // dp[i]: the length of the longest valid parentheses substring ending at s[i]
        int dp[n];

        dp[0] = 0;
        for (int i = 1; i < n; ++i) {
            dp[i] = 0;
            if (s[i] == '(') {
                continue;
            }

            if (s[i - 1] == '(') {
                dp[i] = (2 <= i ? dp[i - 2] : 0) + 2;
            }
            else {
                int j = i - dp[i - 1] - 1;
                if (0 <= j && s[j] == '(') {
                    dp[i] = dp[i - 1] + 2 + ((1 <= j) ? dp[j - 1] : 0);
                }
                
            }
        }

        int ret = 0;
        for (int i = 1; i < n; ++i) {
            ret = std::max(ret, dp[i]);
        }

        return ret;
    }
};
