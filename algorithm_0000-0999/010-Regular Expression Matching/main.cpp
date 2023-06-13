class Solution {
public:
    bool isMatchRecursive1(string s, string p) {
        if (p.empty()) {
            return s.empty();
        }

        bool firstMatch = !s.empty() && (s[0] == p[0] || p[0] == '.');
        if (2 <= p.size() && p[1] == '*') {
            return (firstMatch && isMatchRecursive1(s.substr(1), p)) || isMatchRecursive1(s, p.substr(2));
        }
        else {
            return firstMatch && isMatchRecursive1(s.substr(1), p.substr(1));
        }
    }

    bool isMatchRecursive2(const string& s, size_t sIndex, const string& p, size_t pIndex) {
        if (p.size() <= pIndex) {
            return s.size() <= sIndex;
        }

        bool firstMatch = (sIndex < s.size()) && (s[sIndex] == p[pIndex] || p[pIndex] == '.');
        if (2 <= p.size() && p[pIndex + 1] == '*') {
            return (firstMatch && isMatchRecursive2(s, sIndex + 1, p, pIndex)) || isMatchRecursive2(s, sIndex, p, pIndex + 2);
        }
        else {
            return firstMatch && isMatchRecursive2(s, sIndex + 1, p, pIndex + 1);
        }
    }

    bool btmup_dp(string s, string p) {
        int m = s.size(), n = p.size();

        s = "#" + s;
        p = "#" + p;

        // dp[i][j]: whether s[1:i] matches p[1:j]
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1));

        dp[0][0] = true;
        for (int i = 1; i <= m; ++i) {
            dp[i][0] = false;
        }
        for (int j = 1; j <= n; ++j) {
            if (j & 1) {
                dp[0][j] = false;
            }
            else {
                dp[0][j] = (p[j] == '*' && (j < 2 || dp[0][j - 2]));
            }
        }

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (std::isalpha(p[j])) {
                    dp[i][j] = (s[i] == p[j]) && dp[i - 1][j - 1];
                }
                else if (p[j] == '.') {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else {
                    assert(0 <= (j - 2));
                    bool cond1 = dp[i][j - 2];
                    bool cond2 = dp[i - 1][j] && (s[i] == p[j - 1] || p[j - 1] == '.');
                    dp[i][j] = cond1 || cond2;
                }
            }
        }

        return dp[m][n];
    }

    bool isMatch(string s, string p) {
        //return isMatchRecursive1(s, p);
        //return isMatchRecursive2(s, 0, p, 0);
        return btmup_dp(s, p);
    }
};
