class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        int n = s.size();

        int ret = 0;
        for (int lft = 0, rht = 0, repCnt = 0; lft < n; ++lft) {
            while (rht < n && (repCnt + (0 < rht && s[rht - 1] == s[rht])) < 2) {
                repCnt += (0 < rht && s[rht - 1] == s[rht]) ? 1 : 0;
                ++rht;
            }

            ret = std::max(ret, rht - lft);

            if (0 <= lft && s[lft] == s[lft + 1]) {
                repCnt -= 1;
            }
        }

        return ret;
    }
};
