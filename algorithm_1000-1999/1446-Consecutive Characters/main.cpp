class Solution {
public:
    int maxPower(string s) {
        int n = s.size();

        int ret = 0;
        for (int lft = 0; lft < n;) {
            int rht = lft;
            while (rht + 1 < n && s[lft] == s[rht + 1]) {
                ++rht;
            }
            ret = std::max(ret, rht - lft + 1);

            lft = rht + 1;
        }

        return ret;
    }
};
