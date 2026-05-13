class Solution {
public:
    int mirrorFrequency(string s) {
        unordered_map<char, int> cnts;
        for (char c : s) {
            ++cnts[c];
        }

        int ret = 0;
        for (char c = 'a', m = 'z'; c <= m; ++c, --m) {
            ret += std::abs(cnts[c] - cnts[m]);
        }
        for (char c = '0', m = '9'; c <= m; ++c, --m) {
            ret += std::abs(cnts[c] - cnts[m]);
        }

        return ret;
    }
};
