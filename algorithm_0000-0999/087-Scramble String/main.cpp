class Solution {
public:
    bool btmupDP(const string& s1, const string& s2) {
        int n = s1.size();

        // dp[i][j][len]: whether s1[i:i+len-1] is a scramble of s2[j:j+len-1]
        bool dp[n][n][n + 1];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dp[i][j][1] = (s1[i] == s2[j]);
            }
        }
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; (i + len) <= n; ++i) {
                for (int j = 0; (j + len) <= n; ++j) {
                    dp[i][j][len] = false;
                    for (int xLen = 1, yLen = len - xLen; xLen + 1 <= len && !dp[i][j][len]; ++xLen, --yLen) {
                        if ((dp[i][j][xLen] && dp[i+xLen][j+xLen][yLen]) ||
                            (dp[i][j+yLen][xLen] && dp[i+xLen][j][yLen])) {
                            dp[i][j][len] = true;
                        }
                    }
                }
            }
        }

        return dp[0][0][n];
    }

    bool topdnDFS(const string& s1, const string& s2) {
        int n = s1.size();

        // dp[i][j][len]: whether s1[i:i+len-1] is a scramble of s2[j:j+len-1]
        map<tuple<int, int, int>, bool> dp;
        std::function<bool(int, int, int)> dfs = [&](int idx1, int idx2, int len) {
            if (dp.find({idx1, idx2, len}) != dp.end()) {
                return dp[{idx1, idx2, len}];
            }

            bool& ret = dp[{idx1, idx2, len}];

            bool equal = true;
            vector<int> cnts(26, 0);
            for (int i = 0; i < len; ++i) {
                if (s1[idx1 + i] != s2[idx2 + i]) { equal = false; }
                ++cnts[s1[idx1 + i] - 'a'];
                --cnts[s2[idx2 + i] - 'a'];
            }
            if (equal) {
                return ret = true;
            }
            if (std::find_if(cnts.begin(), cnts.end(), [](int cnt) { return cnt != 0; }) != cnts.end()) {
                return ret = false;
            }

            for (int xLen = 1, yLen = len - xLen; (xLen + 1) <= len && !ret; ++xLen, --yLen) {
                if ((dfs(idx1, idx2, xLen) && dfs(idx1 + xLen, idx2 + xLen, yLen)) ||
                    (dfs(idx1, idx2 + yLen, xLen) && dfs(idx1 + xLen, idx2, yLen))) {
                    ret = true;
                }
            }

            return ret;
        };

        return dfs(0, 0, s1.size());
    }

    bool isScramble(string s1, string s2) {
        //return btmupDP(s1, s2);
        return topdnDFS(s1, s2);
    }
};
