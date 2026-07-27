class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int m = s.size(), n = t.size();
        if (m > n) { return false; }
        if (m == 1) { return true; }

        // pre[i]: the min idx such that s[0:i] is subsequence t[0:idx]
        int pre[m];
        std::fill(pre, pre + m, n);
        for (int j = 0, i = 0; j < n && i < m; ++j) {
            if (s[i] != t[j]) { continue; }
            pre[i++] = j;
        }
        if (pre[m - 1] < n || (m >= 2 && pre[m - 2] < n - 1)) {
            return true;
        }

        // suf[i]: the max idx such that s[i:] is subsequence t[idx:]
        int suf[m];
        std::fill(suf, suf + m, -1);
        for (int j = n - 1, i = m - 1; j >= 0 && i >= 0; --j) {
            if (s[i] != t[j]) { continue; }
            suf[i--] = j;
        }
        if (suf[0] >= 0 || (m >= 2 && suf[1] > 0)) {
            return true;
        }

        for (int i = 1; i < m - 1; ++i) {
            if (pre[i - 1] + 1 < suf[i + 1]) {
                return true;
            }
        }

        return false;
    }
};
