class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();

        int lftMost[26];
        std::fill(lftMost, lftMost + 26, -1);
        for (int i = 0; i < n; ++i) {
            if (lftMost[s[i] - 'a'] != string::npos) { continue; }
            lftMost[s[i] - 'a'] = i;
        }

        int rhtMost[26];
        std::fill(rhtMost, rhtMost + 26, -1);
        for (int i = n; 0 < i--;) {
            if (rhtMost[s[i] - 'a'] != string::npos) { continue; }
            rhtMost[s[i] - 'a'] = i;
        }

        int ret = 0;
        for (char c = 'a'; c <= 'z'; ++c) {
            bitset<26> flags;
            for (int i = lftMost[c - 'a'] + 1; i < rhtMost[c - 'a']; ++i) {
                flags[s[i] - 'a'] = true;
            }

            ret += flags.count();
        }

        return ret;
    }
};
