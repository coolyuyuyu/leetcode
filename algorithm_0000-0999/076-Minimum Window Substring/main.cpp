class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> freqs(128, 0);
        for (char c : t) {
            ++freqs[c];
        }

        size_t index = 0;
        size_t minLen = std::numeric_limits<size_t>::max();
        for (size_t bgn = 0, end = 0, cnt = t.size(); end < s.size(); ++end) {
            if (0 < freqs[s[end]]--) {
                --cnt;
            }

            for (; cnt == 0; ++bgn) {
                size_t len = end - bgn + 1;
                if (len < minLen) {
                    minLen = len;
                    index = bgn;
                }

                if (0 == freqs[s[bgn]]++) {
                    ++cnt;
                }
            }
        }

        return minLen == std::numeric_limits<size_t>::max() ? "" : s.substr(index, minLen);
    }
};
