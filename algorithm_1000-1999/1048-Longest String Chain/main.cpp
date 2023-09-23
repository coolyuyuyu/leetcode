class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        std::sort(words.begin(),words.end(), [](const string& word1, const string& word2) { return word1.size() < word2.size(); });

        std::function<bool(const string&, const string&)> check = [](const string& a, const string& b) {
            if (a.size() + 1 != b.size()) { return false; }
            bool inserted = false;
            for (int i = 0, j = 0; j < b.size(); ++j) {
                if (a[i] == b[j]) {
                    ++i;
                }
                else if (inserted) {
                    return false;
                }
                else {
                    inserted = true;
                }
            }
            return true;
        };

        // dp[i]: the longest word chain from words[0:i] and ending at words[i]
        int dp[n];
        for (int i = 0; i < n; ++i) {
            dp[i] = 1;
        }

        for (int i = 0; i < n; ++i) {
            for (int j = i; 0 < j-- && words[j].size() + 1 >= words[i].size();) {
                if (check(words[j], words[i])) {
                    dp[i] = std::max(dp[i], dp[j] + 1);
                }
            }
        }

        int ret = INT_MIN;
        for (int i = 0; i < n; ++i) {
            ret = std::max(ret, dp[i]);
        }

        return ret;
    }
};
