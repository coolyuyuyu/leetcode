class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        vector<int> freq(256, 0);
        int distinctCnt = 0;

        int ret = 0;
        for (int lft = 0, rht = 0, n = s.size(), distinctCnt = 0; rht < n; ++lft) {
            for (; rht < n && (distinctCnt < 2 || (distinctCnt == 2 && freq[s[rht]] > 0)); ++rht) {
                if (++freq[s[rht]] == 1) {
                    ++distinctCnt;
                }
            }

            ret = std::max(ret, rht - lft);

            if (--freq[s[lft]] == 0) {
                --distinctCnt;
            }
        }

        return ret;
    }
};
