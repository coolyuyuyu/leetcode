class Solution {
public:
    int maxScore(string s) {
        int n = s.size();

        int cnt1 = 0;
        for (char c : s) {
            cnt1 += (c == '1' ? 1 : 0);
        }

        int ret = 0;
        for (int i = 0, lft0 = 0, lft1 = 0; i + 1 < n; ++i) {
            ++(s[i] == '0' ? lft0 : lft1);
            ret = std::max(ret, lft0 + cnt1 - lft1);
        }

        return ret;
    }
};
