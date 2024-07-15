class Solution {
public:
    vector<int> sameEndSubstringCount(string s, vector<vector<int>>& queries) {
        int n = s.size();
        s = "#" + s;

        int prefix[n + 1][26];
        for (int j = 0; j < 26; ++j) {
            prefix[0][j] = 0;
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < 26; ++j) {
                prefix[i][j] = prefix[i - 1][j];
            }
            ++prefix[i][s[i] - 'a'];
        }

        vector<int> ret(queries.size(), 0);
        for (int i = 0; i < queries.size(); ++i) {
            int lft = queries[i][0] + 1, rht = queries[i][1] + 1;
            for (int j = 0; j < 26; ++j) {
                int cnt = prefix[rht][j] - prefix[lft - 1][j];
                if (cnt > 0) {
                    ret[i] += cnt + cnt * (cnt - 1) / 2;
                }
            }
        }

        return ret;
    }
};
