class Solution {
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();

        bool connected[n][n];
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (groups[i] == groups[j]) {
                    connected[i][j] = false;
                }
                else if (words[i].size() != words[j].size()) {
                    connected[i][j] = false;
                }
                else {
                    int cnt = 0;
                    for (int k = 0, m = words[i].size(); k < m && cnt <= 1; ++k) {
                        cnt += (words[i][k] != words[j][k] ? 1 : 0);
                    }
                    connected[i][j] = (cnt == 1);
                }
            }
        }

        // the length of the longest subsequence from words[0:i] ending at words[i]
        int dp[n];
        std::fill(dp, dp + n, 1);

        // prev[i]: the previous index of i from the longest subsequence ending at words[i]
        int prev[n];
        std::fill(prev, prev + n, -1);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (connected[j][i] && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
        }

        int retLen = 0, retIdx = -1;
        for (int i = 0; i < n; ++i) {
            if (dp[i] > retLen) {
                retLen = dp[i];
                retIdx = i;
            }
        }

        vector<string> ret;
        for (int i = retIdx; i != -1; i = prev[i]) {
            ret.push_back(words[i]);
        }
        std::reverse(ret.begin(), ret.end());

        return ret;
    }
};
