class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();

        vector<int> cnts(26, 0);
        int ret = 0;
        for (int lft = 0, rht = 0; lft < n; ++lft) {
            while (rht < n && cnts[s[rht] - 'a'] <= 1) {
                ++cnts[s[rht] - 'a'];
                ++rht;
            }

            ret = std::max(ret, rht - lft);

            --cnts[s[lft]  - 'a'];
        }

        return ret;
    }
};
