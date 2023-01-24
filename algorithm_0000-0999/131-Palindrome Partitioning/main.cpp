class Solution {
public:
    vector<vector<bool>> computePalindrom(const string& s) {
        size_t n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (size_t i = 0; i < n; ++i) {
            dp[i][i] = true;
        }
        for (size_t i = 0; (i + 1) < n; ++i) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
            }
        }
        for (size_t len = 3; len <= n; ++len) {
            for (size_t i = 0; (i + len) <= n; ++i) {
                if (dp[i + 1][i + len - 2] && s[i] == s[i + len - 1]) {
                    dp[i][i + len - 1] = true;
                }
            }
        }

        return dp;
    }

    void dfs(const string& s, vector<vector<bool>>& palidrome, int start, vector<string>& partition, vector<vector<string>>& partitions) {
        if (palidrome.size() <= start) {
            partitions.emplace_back(partition.begin(), partition.end());
            return;
        }

        for (int i = start; i < palidrome.size(); ++i) {
            if (!palidrome[start][i]) {
                continue;
            }

            partition.emplace_back(s.begin() + start, s.begin() + i + 1);
            dfs(s, palidrome, i + 1, partition, partitions);
            partition.pop_back();
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<bool>> palidrome = computePalindrom(s);

        vector<string> partition;
        vector<vector<string>> partitions;
        dfs(s, palidrome, 0, partition, partitions);
        return partitions;
    }
};
