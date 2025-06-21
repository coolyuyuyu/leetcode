class Solution {
public:
    int minOperations(string word1, string word2) {
        std::function<int(int, int)> computeCost = [&](int l, int r) {
            int len = r - l + 1;
            string str1 = word1.substr(l, len);
            string str2 = word2.substr(l, len);

            std::function<int(string, const string&)> f = [&](string test, const string& gold) {
                int cnts[26][26];
                for (int i = 0; i < 26; ++i) {
                    for (int j = 0; j < 26; ++j) {
                        cnts[i][j] = 0;
                    }
                }

                for (int i = 0; i < len; ++i) {
                    if (test[i] != gold[i]) {
                        ++cnts[test[i] - 'a'][gold[i] - 'a'];
                    }
                }

                int ret = 0;
                for (int i = 0; i < 26; ++i) {
                    for (int j = i + 1; j < 26; ++j) {
                        ret += (cnts[i][j] + cnts[j][i] - std::min(cnts[i][j], cnts[j][i]));
                    }
                }
                return ret;
            };

            int a = f(str1, str2);

            std::reverse(str1.begin(), str1.end());
            int b = 1 + f(str1, str2);

            return std::min(a, b);
        };

        int n = word1.size();

        word1.insert(word1.begin(), '#');
        word2.insert(word2.begin(), '#');

        // dp[i] minimum number of operations required to transform word1[1:i] into word2[1:i]
        int dp[n + 1];

        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            dp[i] = INT_MAX;
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = i; j >= 1; --j) {
                dp[i] = std::min(dp[i], dp[j - 1] + computeCost(j, i));
            }
        }

        return dp[n];
    }
};
