class Solution {
public:
    vector<string> getWordsInLongestSubsequence(int n, vector<string>& words, vector<int>& groups) {
        // adjacent[j][i]: whether index i can be a successor of j in a qualified subsequence
        bool adjacent[n][n];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (groups[j] == groups[i]) {
                    adjacent[j][i] = false;
                }
                else if (words[j].size() != words[i].size()) {
                    adjacent[j][i] = false;
                }
                else {
                    int cnt = 0;
                    for (int k = 0, len = words[j].size(); k < len; ++k) {
                        if (words[j][k] != words[i][k]) {
                            if (++cnt > 1) {
                                break;
                            }
                        }
                    }
                    adjacent[j][i] = (cnt == 1);
                }
            }
        }

        // dp[i]: the length of the longest qualified subsequence from words/groups[0:i] ending at index i
        int dp[n];

        // prev[i]: the previous index of the longest qualified subsequence from words/groups[0:i] ending at index i
        int prev[n];
        std::fill(prev, prev + n, -1);

        for (int i = 0; i < n; ++i) {
            dp[i] = 1;
            for (int j = 0; j < i; ++j) {
                if (adjacent[j][i] && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
        }

        int retLen = 0;
        int retIdx = -1;
        for (int i = 0; i < n; ++i) {
            if (dp[i] > retLen) {
                retLen = dp[i];
                retIdx = i;
            }
        }

        vector<string> ret;
        while (retIdx != -1) {
            ret.push_back(words[retIdx]);
            retIdx = prev[retIdx];
        }
        std::reverse(ret.begin(), ret.end());

        return ret;
    }
};
