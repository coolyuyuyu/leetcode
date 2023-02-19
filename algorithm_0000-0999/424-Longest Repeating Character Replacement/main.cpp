class Solution {
public:
    // two pointers
    // Time: O(n)
    int characterReplacement(string s, int k) {
        vector<int> counts(26, 0);
        auto check = [&s, &counts, k](int lft, int rht) { // [lft, rht]
            int len = rht - lft + 1;
            int maxF = std::max(*std::max_element(counts.begin(), counts.end()), counts[s[rht] - 'A'] + 1);
            return (len - maxF) <= k;
        };

        int ret = 0;
        for (int lft = 0, rht = 0, n = s.size(); lft < n; ++lft) {
            for (; rht < n && check(lft, rht); ++rht) {
                ++counts[s[rht] - 'A'];
            }
            ret = std::max(ret, rht - lft); // [lft, rht)

            --counts[s[lft] - 'A'];
        }

        return ret;
    }
};
