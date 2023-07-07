class Solution {
public:
    // Time: O(n)
    int characterReplacement(string s, int k) {
        int n = s.size();

        vector<int> cnts(26, 0);

        auto check = [&](int lft, int rht) {
            int len = rht - lft + 1;
            int maxF = std::max(*std::max_element(cnts.begin(), cnts.end()), cnts[s[rht] - 'A'] + 1);
            return (len - maxF) <= k;
        };

        int ret = 0;
        for (int lft = 0, rht = 0; lft < n; ++lft) {
            for (; rht < n && check(lft, rht); ++rht) {
                ++cnts[s[rht] - 'A'];
            }

            ret = std::max(ret, rht - lft);

            --cnts[s[lft] - 'A'];
        }

        return ret;
    }
};
