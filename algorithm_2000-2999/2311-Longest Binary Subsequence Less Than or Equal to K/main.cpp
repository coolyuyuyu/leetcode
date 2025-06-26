class Solution {
public:
    int longestSubsequence(string s, int k) {
        string t;
        for (; k; k /= 2) {
            t.push_back('0' + (k & 1));
        }
        std::reverse(t.begin(), t.end());

        int m = s.size(), n = t.size();
        if (m < n) {
            return m;
        }

        int ret = std::count(s.begin(), s.begin() + m - (n - 1), '0') + n - 1;
        if (s.substr(m - n) <= t) {
            ret = std::max<int>(ret, std::count(s.begin(), s.begin() + m - n, '0') + n);
        }

        return ret;
    }
};
