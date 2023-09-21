class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();

        std::function<bool(const string& s, const string& t)> check = [&](const string& a, const string& b) -> bool {
            if (a.size() + 1 != b.size()) {
                return false;
            }

            bool inserted = false;
            for (int i = 0, j = 0; j < b.size(); ++j) {
                if (a[i] == b[j]) {
                    ++i;
                    continue;
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

        std::sort(words.begin(), words.end(), [](const string& a, const string& b) { return a.size() < b.size(); });

        // dp[i]: the length of the longest word chain ending at i
        int dp[n];
        for (int i = 0; i < n; ++i) {
            dp[i] = 1;
            for (int j = i; 0 < j-- && (words[i].size() <= words[j].size() + 1);) {
                if (check(words[j], words[i])) {
                    dp[i] = std::max(dp[i], dp[j] + 1);
                }
            }
        }

        int ret = 0;
        for (int i = 0; i < n; ++i) {
            ret = std::max(ret, dp[i]);
        }

        return ret;
    }
};
