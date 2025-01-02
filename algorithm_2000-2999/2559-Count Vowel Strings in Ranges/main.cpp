class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        std::function<bool(char)> checkVowel = [](char c) {
            switch (c) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                return true;
            default:
                return false;
            };
        };

        int n = words.size();

        // dp[i]: number of vowel strings from words[0:i]
        int dp[n];
        for (int i = 0; i < n; ++i) {
            dp[i] = (checkVowel(words[i].front()) && checkVowel(words[i].back())) ? 1 : 0;
            if (i > 0) {
                dp[i] += dp[i - 1];
            }
        }

        vector<int> ret(queries.size());
        for (int i = 0; i < ret.size(); ++i) {
            int l = queries[i][0], r = queries[i][1];
            ret[i] = dp[r] - (l > 0 ? dp[l - 1] : 0);
        }

        return ret;
    }
};
