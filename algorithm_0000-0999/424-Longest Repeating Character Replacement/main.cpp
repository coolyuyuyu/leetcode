class Solution {
public:
    int characterReplacement(string s, int k) {
        size_t bgn = 0;
        vector<size_t> counts(26, 0);
        size_t maxf = 0;
        for (size_t end = 0; end < s.size(); ++end) {
            maxf = std::max(maxf, ++counts[s[end] - 'A']);
            if ((end - bgn + 1) > (maxf + k) ) {
                --counts[s[bgn++] - 'A'];
            }
        }

        return s.size() - bgn;
    }
};
