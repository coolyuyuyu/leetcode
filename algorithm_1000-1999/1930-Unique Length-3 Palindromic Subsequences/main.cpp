class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int lftMosts[26];
        std::fill(lftMosts, lftMosts + 26, -1);
        for (int i = 0, n = s.size(); i < n; ++i) {
            if (lftMosts[s[i] - 'a'] == -1) {
                lftMosts[s[i] - 'a'] = i;
            }
        }

        int rhtMosts[26];
        std::fill(rhtMosts, rhtMosts + 26, -1);
        for (int i = s.size(); 0 < i--;) {
            if (rhtMosts[s[i] - 'a'] == -1) {
                rhtMosts[s[i] - 'a'] = i;
            }
        }

        int ret = 0;
        for (int i = 0; i < 26; ++i) {
            bitset<26> flags;
            for (int j = lftMosts[i] + 1; j < rhtMosts[i]; ++j) {
                flags.set(s[j] - 'a');
            }

            ret += flags.count();
        }

        return ret;
    }
};
