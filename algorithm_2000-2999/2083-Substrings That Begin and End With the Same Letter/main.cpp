class Solution {
public:
    long long numberOfSubstrings(string s) {
        vector<int> cnts(26, 0);
        for (char c : s) {
            ++cnts[c - 'a'];
        }

        long long ret = 0;
        for (int cnt : cnts) {
            ret += 1L * (cnt + 1) * cnt / 2;
        }

        return ret;
    }
};
