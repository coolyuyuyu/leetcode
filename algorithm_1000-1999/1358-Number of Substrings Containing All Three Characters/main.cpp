class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> cnts(3, 0);

        int ret = 0;
        for (int lft = 0, rht = 0, n = s.size(); lft < n; ++lft) {
            for (; rht < n && std::find(cnts.begin(), cnts.end(), 0) != cnts.end(); ++rht) {
                ++cnts[s[rht] - 'a'];
            }

            if (std::find(cnts.begin(), cnts.end(), 0) == cnts.end()) {
                ret += (n - rht + 1);
            }

            --cnts[s[lft] - 'a'];
        }

        return ret;
    }
};
