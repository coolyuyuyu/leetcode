class Solution {
public:
    string minWindow(string s, string t) {
        int freq[128];
        std::fill(freq, freq + 128, 0);
        for (char c : t) {
            ++freq[c - 'A'];
        }
        int uniqCnt = std::count_if(freq, freq + 128, [](int f){ return f != 0; });

        int n = s.size();
        int bgn = 0, end = INT_MAX;
        for (int lft = 0, rht = 0; lft < n; ++lft) {
            for (; rht < n && uniqCnt > 0; ++rht) {
                if (--freq[s[rht] - 'A'] == 0) {
                    --uniqCnt;
                }
            }

            if (uniqCnt == 0 && (rht - lft < end - bgn)) {
                bgn = lft, end = rht;
            }

            if (freq[s[lft] - 'A']++ == 0) {
                ++uniqCnt;
            }
        }

        return end == INT_MAX ? "" : s.substr(bgn, end - bgn);
    }
};
