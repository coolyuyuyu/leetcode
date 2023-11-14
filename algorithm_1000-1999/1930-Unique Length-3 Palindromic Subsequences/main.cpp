class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();

        size_t lft[26];
        std::fill(lft, lft + 26, string::npos);
        for (int i = 0; i < n; ++i) {
            if (lft[s[i] - 'a'] == string::npos) {
                lft[s[i] - 'a'] = i;
            }
        }

        size_t rht[26];
        std::fill(rht, rht + 26, string::npos);
        for (int i = n; 0 < i--;) {
            if (rht[s[i] - 'a'] == string::npos) {
                rht[s[i] - 'a'] = i;
            }
        }

        int ret = 0;
        for (char c = 'a'; c <= 'z'; ++c) {
            if (lft[c - 'a'] == string::npos) { continue; }

            bitset<26> flags;
            for (int i = lft[c - 'a'] + 1; i < rht[c - 'a']; ++i) {
                flags.set(s[i] - 'a');
            }
            ret += flags.count();
        }

        return ret;
    }
};
