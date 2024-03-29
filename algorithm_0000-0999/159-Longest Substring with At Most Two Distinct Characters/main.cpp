class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        vector<int> cnts(128, 0);

        int ret = 0;
        for (int lft = 0, rht = 0, n = s.size(), cntDistinct = 0; rht < n; ++lft) {
            for (;rht < n && (cntDistinct < 2 || (cntDistinct == 2 && cnts[s[rht]] > 0)); ++rht) {
                if (cnts[s[rht]]++ == 0) {
                    ++cntDistinct;
                }
            }

            ret = std::max(ret, rht - lft);

            if (--cnts[s[lft]] == 0) {
                --cntDistinct;
            }
        }

        return ret;
    }
};
