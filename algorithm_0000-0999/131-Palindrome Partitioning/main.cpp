class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();

        // dp[i][j]: whether s[i:j] is palindrome or not
        int dp[n][n];
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                dp[i][j] = false;
            }
        }
        for (int i = 0; i < n; ++i) {
            dp[i][i] = true;
        }
        for (int i = 0; i + 1 < n; ++i) {
            dp[i][i + 1] = s[i] == s[i + 1];
        }
        for (int len = 3; len <= n; ++len) {
            for (int i = 0, j = i + len - 1; j < n; ++i, ++j) {
                dp[i][j] = s[i] == s[j] && dp[i + 1][j - 1];
            }
        }

        vector<vector<string>> ret;
        std::function<void(int, vector<string>&)> dfs = [&](int i, vector<string>& partition) {
            if (i >= n) {
                ret.push_back(partition);
                return;
            }

            for (int j = i; j < n; ++j) {
                if (dp[i][j]) {
                    partition.push_back(s.substr(i, j - i + 1));
                    dfs(j + 1, partition);
                    partition.pop_back();
                }
            }
        };

        vector<string> partition;
        dfs(0, partition);

        return ret;
    }
};
