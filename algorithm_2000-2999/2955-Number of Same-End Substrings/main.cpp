class Solution {
public:
    vector<int> sameEndSubstringCount(string s, vector<vector<int>>& queries) {
        int n = s.size();
        s = "#" + s;

        // cnts[i]['a']: number of 'a' of s[1:i]
        int cnts[n + 1][26];
        for (int j = 0; j < 26; ++j) {
            cnts[0][j] = 0;
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < 26; ++j) {
                cnts[i][j] = cnts[i - 1][j];
            }
            ++cnts[i][s[i] - 'a'];
        }

        int m = queries.size();
        vector<int> ret(m);
        for (int i = 0; i < m; ++i) {
            int lft = queries[i][0] + 1, rht = queries[i][1] + 1;
            for (int j = 0; j < 26; ++j) {
                int cnt = cnts[rht][j] - cnts[lft - 1][j];
                ret[i] += cnt + cnt * (cnt - 1) / 2;
            }
        }

        return ret;
    }
};
