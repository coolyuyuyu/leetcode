class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        assert(!s1.empty() && !s2.empty());

        size_t m = s1.size();
        size_t n = s2.size();
        if (n < m) {
            return false;
        }

        vector<int> cnt(26, 0);
        for (char c : s1) {
            ++cnt[c - 'a'];
        }

        vector<int> cur(26, 0);
        for (size_t i = 0; i < m; ++i) {
            ++cur[s2[i] - 'a'];
        }
        if (cur == cnt) {
            return true;
        }

        for (size_t i = m; i < n; ++i) {
            ++cur[s2[i] - 'a'];
            --cur[s2[i - m] - 'a'];
            if (cur == cnt) {
                return true;
            }
        }

        return false;
    }
};