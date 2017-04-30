class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        if (n < m) {
            return false;
        }

        vector<int> cur(26, 0);
        for (int i = 0; i < m; ++i) {
            ++cur[s2[i] - 'a'];
        }

        vector<int> cnt(26, 0);
        for (int i = 0; i < m; ++i) {
            ++cnt[s1[i] - 'a'];
        }

        if (cur == cnt) {
            return true;
        }

        for (int i = 1; (i + m  - 1)< n; ++i) {
            --cur[s2[i - 1] - 'a'];
            ++cur[s2[i + m - 1] - 'a'];
            if (cur == cnt) {
                return true;
            }
        }

        return false;
    }
};