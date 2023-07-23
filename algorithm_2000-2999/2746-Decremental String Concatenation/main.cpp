class Solution {
public:
    int dp(vector<string>& words) {
        int n = words.size();

        map<pair<char, char>, int> dp;
        dp[{words[0].front(), words[0].back()}] = words[0].size();

        for (int k = 1; k < n; ++k) {
            char a = words[k].front(), b = words[k].back();
            for (auto [key, len] : map<pair<char, char>, int>(std::move(dp))) {
                auto [i, j] = key;

                if (dp.find({i, b}) == dp.end()) {
                    dp[{i, b}] = INT_MAX;
                }
                if (dp.find({a, j}) == dp.end()) {
                    dp[{a, j}] = INT_MAX;
                }

                dp[{i, b}] = std::min(dp[{i, b}], len + (int)words[k].size() - (j == a ? 1 : 0));
                dp[{a, j}] = std::min(dp[{a, j}], (int)words[k].size() + len - (b == i ? 1 : 0));
            }
        }

        int ret = INT_MAX;
        for (auto [_, len] : dp) {
             ret = std::min(ret, len);
        }

        return ret;
    }

    int dfs(vector<string>& words) {
        int cache[words.size()][26][26];
        for (int i = 0; i < words.size(); ++i) {
            for (char bgn = 'a'; bgn <= 'z'; ++bgn) {
                for (char end = 'a'; end <= 'z'; ++end) {
                    cache[i][bgn - 'a'][end - 'a'] = -1;
                }
            }
        }

        // f(i, bgn, end): the minimum appended length if we already constructed first i words with bgn as first and end as last character
        std::function<int(int, char, char)>f = [&](int i, char bgn, char end) -> int {
            if (words.size() <= i) {
                return 0;
            }

            int& ret = cache[i][bgn - 'a'][end - 'a'];
            if (0 <= ret) {
                return ret;
            }
            ret = INT_MAX;

            int len = words[i].size();
            ret = std::min(ret, len - (end == words[i].front() ? 1 : 0) + f(i + 1, bgn, words[i].back()));
            ret = std::min(ret, len - (words[i].back() == bgn ? 1 : 0) + f(i + 1, words[i].front(), end));

            return ret;
        };

        return words[0].size() + f(1,  words[0].front(),  words[0].back());
    }

    int minimizeConcatenatedLength(vector<string>& words) {
        //return dp(words);
        return dfs(words);
    }
};
