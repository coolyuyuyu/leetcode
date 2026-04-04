class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();

        string s(n, '\0');

        int i = 0;
        for (char c = 'a'; c <= 'z' && i < n; ++c) {
            while (i < n && s[i] != '\0') {
                ++i;
            }
            for (int j = i; j < n; ++j) {
                if (lcp[i][j] > 0) {
                    s[j] = c;
                }
            }
        }
        if (s.find('\0', i) != string::npos) {
            return "";
        }

        int dp[n][n];
        std::fill(&dp[0][0], &dp[0][0] + n * n, 0);
        for (int i = n; 0 < i--;) {
            for (int j = n; 0 < j--;) {
                if (s[i] == s[j]) {
                    dp[i][j] = 1 + ((i + 1 == n || j + 1 == n) ? 0 : dp[i + 1][j + 1]);
                }
                if (dp[i][j] != lcp[i][j]) {
                    return "";
                }
            }
        }

        return s;
    }
};
