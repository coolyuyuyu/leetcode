class Solution {
public:
    int minimizeConcatenatedLength(vector<string>& words) {
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
};
