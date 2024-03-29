class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        vector<int> freq(256, 0);

        int ret = 0;
        for (int lft = 0, rht = 0, n = s.size(), cnt = 0; lft < n; ++lft) {
            for (; rht < n && (cnt < k || cnt == k && freq[s[rht]] > 0); ++rht) {
                if (freq[s[rht]]++ == 0) {
                    ++cnt;
                }
            }

            ret = std::max(ret, rht - lft);

            if (--freq[s[lft]] == 0) {
                --cnt;
            }
        }

        return ret;
    }
};
