class Solution {
public:
    string reverseStr(string s, int k) {
        assert(0 <= k);

        size_t bgn = 0;
        while (bgn + k <= s.size()) {
            size_t i = bgn;
            size_t j = bgn + k - 1;
            while (i < j) {
                swap(s[i++], s[j--]);
            }

            bgn += (2 * k);
        }

        if (!s.empty()) {
            size_t i = bgn;
            size_t j = s.size() - 1;
            while (i < j) {
                swap(s[i++], s[j--]);
            }
        }

        return s;
    }
};