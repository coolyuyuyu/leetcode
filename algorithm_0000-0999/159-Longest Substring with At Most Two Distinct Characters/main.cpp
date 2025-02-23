class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        vector<int> freq(256, 0);

        int ret = 0;
        for (int lft = 0, rht = 0, n = s.size(), diffCnt = 0; lft < n; ++lft) {
            for (; rht < n && (diffCnt < 2 || (diffCnt == 2 && freq[s[rht]] > 0)); ++rht) {
                if (++freq[s[rht]] == 1) {
                    ++diffCnt;
                }
            }

            ret = std::max(ret, rht - lft);

            if (--freq[s[lft]] == 0) {
                --diffCnt;
            }
        }

        return ret;
    }
};
