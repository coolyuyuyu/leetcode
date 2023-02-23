class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();

        string s(n, '\0');
        int i = 0;
        for (char c = 'a'; c <= 'z'; ++c) {
            for (; i < n && s[i] != '\0'; ++i) {
                ;
            }
            if (n <= i) {
                break;
            }

            for (int j = 0; j < n; ++j) {
                if (0 < lcp[i][j]) {
                    s[j] = c;
                }
            }
        }
        if (s.find('\0') != string::npos) {
            return "";
        }

        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = n; 0 < i--;) {
            for (int j = n; 0 < j--;) {
                if (s[i] == s[j]) {
                    dp[i][j] = (i == n-1 || j == n-1) ? 1 : (dp[i + 1][j + 1] + 1);
                }

                if (dp[i][j] != lcp[i][j]) {
                    return "";
                }
            }
        }

        return s;
    }
};
