class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();

        int ret = 0;
        // [lft, rht)
        for (int lft = 0, rht = 0, cost = 0; rht < n; ++lft) {
            if (lft > rht) {
                rht = lft;
            }

            for (; rht < n && cost + abs(s[rht] - t[rht]) <= maxCost; ++rht) {
                cost += abs(s[rht] - t[rht]);
            }
            ret = std::max(ret, rht - lft);

            if (lft < rht) {
                cost -= abs(s[lft] - t[lft]);
            }
        }

        return ret;
    }
};
