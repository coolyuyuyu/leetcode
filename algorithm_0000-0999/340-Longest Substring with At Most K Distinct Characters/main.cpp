class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        vector<int> cnts(256, 0);

        int ret = 0;
        for (int lft = 0, rht = 0, n = s.size(); lft < n; ++lft) {
            for (;rht < n && (rht < lft || 0 < k || (k == 0 && 0 < cnts[s[rht]])); ++rht) {
                if (cnts[s[rht]]++ == 0) {
                    k--;
                }
            }

            ret = std::max(ret, rht - lft);

            if (--cnts[s[lft]] == 0) {
                ++k;
            }
        }

        return ret;
    }
};
